#include <iostream>
#include <thread>

#include <matching-engine.h>
#include <trademessage.pb.h>

using namespace std;

void protobuf_test() {
    NewOrderMessage m;

    uint32_t user_id = 1;
    uint32_t order_id = 10;
    std::string symbol = "AAPL";
    Direction side = LONG;
    uint64_t transaction_time = 1000;
    double order_quantity = 5;
    OrderType order_type = MARKET;

    m.set_user_id(user_id);
    m.set_order_id(order_id);
    m.set_symbol(symbol);
    m.set_side(side);
    m.set_transaction_time(transaction_time);
    m.set_order_quantity(order_quantity);
    m.set_order_type(order_type);

    std::cout << m.symbol();

}

int main() {

    Trade t = Trade("HI", "HI", 1, 1);
    MatchingEngine engine = MatchingEngine();
    engine.run_engine();

    protobuf_test();
    
    cout << "HI";
    return 0;
}