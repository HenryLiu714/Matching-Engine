import socket
import struct
from protocols import trademessage_pb2

def prompt_for_order():
    order = trademessage_pb2.OrderMessage()
    order.order_id = int(input("Enter order ID: "))
    order.user_id = int(input("Enter user ID: "))
    order.symbol = input("Enter symbol: ")
    order.side = trademessage_pb2.Direction.SHORT if int(input("Enter side (1 for LONG, 2 for SHORT): ")) == 2 else trademessage_pb2.Direction.LONG
    order.transaction_time = 1612345678
    order.order_quantity = int(input("Enter order quantity: "))
    order.price = int(input("Enter price: "))
    return order

def sample_order():
    order = trademessage_pb2.OrderMessage()
    order.order_id = 123456
    order.user_id = 654321
    order.symbol = "AAPL"
    order.side = trademessage_pb2.Direction.LONG
    order.transaction_time = 1612345678
    order.order_quantity = 100
    order.price = 15000  # Price in cents
    return order

def start_client():
    host = '127.0.0.1'  # Server's hostname or IP address
    port = 56000         # Server's port to connect to

    # Create a socket object

    while True:
        # Connect to the server
        client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        client_socket.connect((host, port))
        print(f"Connected to the server at {host}:{port}")
    
        # Get user input
        order = prompt_for_order()
        # order = sample_order()
        message = order.SerializeToString()
        
        length = struct.pack('!I', len(message))

        print(f'Message length: {length}')

        padded_message = length + message
        
        print(padded_message)

        # Send the message to the server
        client_socket.send(padded_message)

        # Receive the server's response
        response = client_socket.recv(1024)
        print(response.decode())

        # order2 = trademessage_pb2.NewOrderMessage()
        # order2.ParseFromString(response)

        # Close the connection
        client_socket.close()
        print("Disconnected from the server.")

if __name__ == "__main__":
    start_client()