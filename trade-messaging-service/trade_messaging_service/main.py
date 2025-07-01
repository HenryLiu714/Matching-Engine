import socket
import struct
import os
from dotenv import load_dotenv
from supabase import create_client, Client

from protocols.trademessage_pb2 import OrderMessage, OrderResponse, Direction, OrderStatus

# Load environment variables from .env file
load_dotenv()

def _map_direction(direction):
    if direction == Direction.LONG:
        return "LONG"
    elif direction == Direction.SHORT:
        return "SHORT"
    return None

def _map_status(status):
    if status == OrderStatus.PENDING:
        return "PENDING"
    elif status == OrderStatus.FILLED:
        return "FILLED"
    elif status == OrderStatus.CANCELLED:
        return "CANCELLED"
    elif status == OrderStatus.PARTIAL:
        return "PARTIAL"
    return None

class ResponseReceiver(object):
    def __init__(self):
        url: str = os.environ.get("SUPABASE_URL")
        key: str = os.environ.get("SUPABASE_KEY")

        self.supabase: Client = create_client(url, key)
        self.host = "0.0.0.0"
        self.port = int(os.environ.get("RESPONSE_PORT"))

    def upload_order(self, order: OrderMessage):
        def update_order(order_id):
            current_order = (self.supabase.table("Trades")
                             .select("*")
                             .eq("order_id", order_id)
                             .execute()).data[0] # Get the current order

            order_quantity = current_order['quantity']
            
            # Update the order quantity
            self.supabase.table("Trades").update({"quantity": order_quantity + order.order_quantity}).eq("order_id", order_id).execute()
            
            # Update the status
            self.supabase.table("Trades").update({"status": _map_status(order.status)}).eq("order_id", order_id).execute()
            self.supabase.table("Trades").update({"transaction_time": order.transaction_time}).eq("order_id", order_id).execute()
           
        def create_order():
            # Create a new order
            self.supabase.table("Trades").insert({
                "order_id": order.order_id,
                "user_id": order.user_id,
                "symbol": order.symbol,
                "transaction_time": order.transaction_time,
                "quantity": order.order_quantity,
                "price": order.price,
                "side": _map_direction(order.side),
                "status": _map_status(order.status)
            }).execute()
        
        if self.supabase.table("Trades").select("*").eq("order_id", order.order_id).execute().data:
            update_order(order.order_id)
        else:
            create_order()
  
    def run_receiver(self):
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

        server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        server_socket.bind((self.host, self.port))
        server_socket.listen()

        print(f"Listening for incoming connections on {self.host}:{self.port}...")
        
        try:
            while True:
                conn, _ = server_socket.accept()
                
                print(f"Accepted connection from {conn.getpeername()}")
                
                try:
                    while True:
                        data = receive_message(conn)
                        
                        if not data:
                            break  # Exit loop when client disconnects

                        # Decode safely to avoid UnicodeDecodeError
                        order = OrderResponse()
                        order.ParseFromString(data)
                        self.upload_order(order)
                        
                        print("Received and processed order response:", order)

                except Exception as e:
                    print(f"Error: {e}")

                finally:
                    conn.close()
        except Exception as e:
            print(f"Error: {e}")
            
        finally:
            server_socket.close()

if __name__ == "__main__":
    receiver = ResponseReceiver()
    print(f"Starting server on {receiver.host}:{receiver.port}")
    receiver.run_receiver()
