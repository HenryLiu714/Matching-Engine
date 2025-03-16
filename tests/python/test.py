import socket
import struct
from protocols import trademessage_pb2

def prompt_for_order():
    order = trademessage_pb2.NewOrderMessage()
    order.order_id = int(input("Enter order ID: "))
    order.user_id = int(input("Enter user ID: "))
    order.symbol = input("Enter symbol: ")
    order.side = trademessage_pb2.Direction.SHORT
    order.transaction_time = 1612345678
    order.order_quantity = 100
    order.order_type = trademessage_pb2.OrderType.LIMIT
    order.price = 125
    return order

def start_client():
    host = '127.0.0.1'  # Server's hostname or IP address
    port = 56000         # Server's port to connect to

    # Create a socket object
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Connect to the server
    client_socket.connect((host, port))
    print(f"Connected to the server at {host}:{port}")

    while True:
        # Get user input
        order = prompt_for_order()
        message = order.SerializeToString()
        
        length = struct.pack('!I', len(message))

        print(f'Message length: {length}')

        padded_message = length + message
        
        print(padded_message)

        # Send the message to the server
        client_socket.send(padded_message)

        # Receive the server's response
        response = client_socket.recv(1024)

        # order2 = trademessage_pb2.NewOrderMessage()
        # order2.ParseFromString(response)

    # Close the connection
    client_socket.close()
    print("Disconnected from the server.")

if __name__ == "__main__":
    start_client()