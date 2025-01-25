import socket

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
        message = input("Enter message to send (or type 'exit' to quit): ")
        if message.lower() == 'exit':
            break

        # Send the message to the server
        client_socket.send(message.encode())

        # Receive the server's response
        response = client_socket.recv(1024)
        print(f"Server echoed: {response.decode()}")

    # Close the connection
    client_socket.close()
    print("Disconnected from the server.")

if __name__ == "__main__":
    start_client()