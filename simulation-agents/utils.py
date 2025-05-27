from protocols.trademessage_pb2 import OrderMessage, OrderResponse
import dotenv
import os
import socket
import struct

class Trader:
    def __init__(self, user_id: int):
        dotenv.load_dotenv()
        
        self.host = os.getenv("ORDER_HOST")
        self.port = os.getenv("ORDER_PORT")
        self.user_id = user_id
        
    def send_order(self, order: OrderMessage):
        """
        Simulate sending an order and receiving a response.
        
        Args:
            order (OrderMessage): The order to be sent.
        
        Returns:
            OrderResponse: The response received after sending the order.
        """
        # In a real implementation, this would send the order to a trading system
        # and wait for a response. Here we just simulate it.
        
        # Simulate a response
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        sock.connect((self.host, self.port))
        
        message = order.SerializeToString()
        
        length = struct.pack('!I', len(message))
        
        padded_message = length + message
        
        sock.send(padded_message)
        response = sock.recv(1024)
        print(response.decode())
        sock.close()
        
        return response.decode()
               
    def get_trades(self, n) -> list[OrderResponse]:
        pass