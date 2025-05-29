import os
from dotenv import load_dotenv
import sys
import socket
import struct

from utils.protocols import trademessage_pb2

from confluent_kafka.admin import AdminClient, NewTopic
from confluent_kafka import KafkaException, KafkaError
from confluent_kafka import Consumer

# from protocols import trademessage_pb2

load_dotenv()

bootstrap_servers = os.getenv("KAFKA_BOOTSTRAP_SERVERS")
topic_name = os.getenv("TRADE_TOPIC")

order_host = os.getenv("ORDER_HOST")
order_port = int(os.getenv("ORDER_PORT"))

def ensure_topic(bootstrap_servers, topic_name):
    admin = AdminClient({'bootstrap.servers': bootstrap_servers})
    topics = admin.list_topics(timeout=10).topics

    if topic_name not in topics:
        print(f"Creating topic {topic_name}")
        new_topic = NewTopic(topic_name, num_partitions=1, replication_factor=1)
        fs = admin.create_topics([new_topic])
        fs[topic_name].result()  # Raises if failed
    else:
        pass

def process_message(msg):
    # Forwards message to trade messaging server
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect((order_host, order_port))
    print(f"Connected to server")
    
    # Send the message to the server
    client_socket.send(msg.value())

    # Receive the server's response
    response = client_socket.recv(1024)
    
    client_socket.close()
    
    return response.decode()
    

def consumer_loop(consumer, topics):
    try:
        consumer.subscribe(topics)

        print("Polling service started. Waiting for messages...")
        
        while True:
            msg = consumer.poll(timeout=1.0)
            if msg is None: continue

            if msg.error():
                if msg.error().code() == KafkaError._PARTITION_EOF:
                    # End of partition event
                    sys.stderr.write('%% %s [%d] reached end at offset %d\n' %
                                     (msg.topic(), msg.partition(), msg.offset()))
                elif msg.error():
                    raise KafkaException(msg.error())
            else:
                print(f"Received message: {msg.value()}")
                print(process_message(msg))
    
    finally:
        consumer.close()


if __name__ == "__main__":
    if not bootstrap_servers or not topic_name:
        raise ValueError("KAFKA_BOOTSTRAP_SERVERS and TRADE_TOPIC must be set in .env file")
    
    ensure_topic(bootstrap_servers, topic_name)
    
    # Create a Kafka consumer
    consumer = Consumer({
        'bootstrap.servers': bootstrap_servers,
        'group.id': 'polling_service_group',
        'auto.offset.reset': 'earliest',
        'enable.auto.commit': False
    })
    
    consumer_loop(consumer, [topic_name])