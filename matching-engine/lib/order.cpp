#include <order.h>

Order::Order(uint64_t order_id_, uint64_t user_id_, const std::string& symbol_, Direction direction_, uint64_t transaction_time_, float order_quantity_, float price_) {
    order_id = order_id_;
    user_id = user_id_;
    symbol = symbol_;
    direction = direction_;
    transaction_time = transaction_time_;
    order_quantity = order_quantity_;
    price = price_;
}