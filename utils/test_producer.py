from confluent_kafka import Producer
import socket
import struct
import os
from dotenv import load_dotenv
import protocols.trademessage_pb2 as trademessage_pb2

load_dotenv()
trade_topic = os.getenv("TRADE_TOPIC")

p = Producer({'bootstrap.servers': 'localhost:9092'})

def sample_order():
    order = trademessage_pb2.OrderMessage()
    order.order_id = 20
    order.user_id = 654321
    order.symbol = "superorder"
    order.side = trademessage_pb2.Direction.LONG
    order.transaction_time = 1612345678
    order.order_quantity = 75
    order.price = 15000 # Price in cents
    return order

order = sample_order()
message = order.SerializeToString()

length = struct.pack('!I', len(message))
padded_message = length + message

p.produce(trade_topic, value=padded_message)
p.flush()