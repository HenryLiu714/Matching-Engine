from enum import Enum
import time

from protocols import trademessage_pb2

class Direction(Enum):
    LONG = 0
    SHORT = 1

class OrderType(Enum):
    MARKET = 0
    LIMIT = 1

class TradeMessage(object):
    ORDER_ID = 0
    
    def __init__(self, user_id, symbol, quantity, direction = Direction.LONG.value, order_type = OrderType.MARKET.value, price = 0):
        self.order_id = TradeMessage.ORDER_ID
        self.user_id = user_id
        self.symbol = symbol
        self.quantity = quantity
        self.direction = direction
        self.order_type = order_type
        self.price = price
        
        self.transaction_time = int(time.time())
        
        TradeMessage.ORDER_ID += 1
        