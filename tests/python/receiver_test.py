import socket
import struct
from protocols.trademessage_pb2 import OrderMessage, OrderResponse

def receive_message(conn):
    # Read exactly 4 bytes (message length)
    length_data = conn.recv(4)
    if not length_data:
        return None  # Client disconnected

    # Unpack 4-byte integer (big-endian)
    message_length = struct.unpack("!I", length_data)[0]

    # Receive message of the exact length
    message = conn.recv(message_length)
    return message

HOST = "127.0.0.1"  # Localhost
PORT = 56001        # Port to listen on

# Create a TCP/IP socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind((HOST, PORT))
server_socket.listen()

print(f"Server listening on {HOST}:{PORT}...")

conn, addr = server_socket.accept()
print(f"Connected by {addr}")

try:
    while True:
        data = receive_message(conn)
        if not data:
            print("Client disconnected.")
            break  # Exit loop when client disconnects

        # Decode safely to avoid UnicodeDecodeError
        order = OrderResponse()
        order.ParseFromString(data)
        print(f"Received: {order}")

except Exception as e:
    print(f"Error: {e}")

finally:
    conn.close()
    server_socket.close()
    print("Server shut down.")