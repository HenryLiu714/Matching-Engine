import struct
import os
from dotenv import load_dotenv

from confluent_kafka import Producer
from protocols.trademessage_pb2 import OrderMessage, OrderResponse

load_dotenv()
trade_topic = os.getenv("TRADE_TOPIC")
bootstrap_servers = os.getenv("KAFKA_BOOTSTRAP_SERVERS")

class TradeInterface:
    def __init__(self):
        self.producer = Producer({'bootstrap.servers': bootstrap_servers})
    
    def send_order(self, order: OrderMessage):
        message = order.SerializeToString()
        length = struct.pack('!I', len(message))
        padded_message = length + message
        self.producer.produce(trade_topic, value=padded_message)
        self.producer.flush()
        
    def get_trades(self, n) -> list[OrderResponse]:
        pass
        