#include <iostream>

#include "trade.h"

Trade::Trade(std::string symbol_, std::string user_id_, double price_, bool direction_) {
    symbol = symbol_;
    user_id = user_id_;
    price = price_;
    direction = direction_;
}