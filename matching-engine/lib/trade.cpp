#include <trade.h>

Trade::Trade(const std::string& symbol_, const std::string& user_id_, double price_, bool direction_) {
    symbol = symbol_;
    user_id = user_id_;
    price = price_;
    direction = direction_;
}