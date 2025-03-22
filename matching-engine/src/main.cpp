#include <iostream>
#include <thread>

#include <matching-engine.h>
#include <trademessage.pb.h>

using namespace std;

void print_vector(std::vector<OrderResponse> vec) {
    for (const auto& item : vec) {
        cout << item.DebugString() << " ";
    }
    cout << endl;
}

void test1() {
    OrderMessage msg;
    msg.set_order_id(1);
    msg.set_user_id(1);
    msg.set_symbol("AAPL");
    msg.set_side(Direction::LONG);
    msg.set_transaction_time(123456789);
    msg.set_order_quantity(10.0);
    msg.set_price(150.0);
    
    OrderMessage msg2;
    msg2.CopyFrom(msg);
    msg2.set_order_id(2);
    msg2.set_side(Direction::LONG);

    OrderMessage msg3;
    msg3.set_order_id(3);
    msg3.set_user_id(2);
    msg3.set_symbol("AAPL");
    msg3.set_side(Direction::SHORT);
    msg3.set_transaction_time(987654321);
    msg3.set_order_quantity(15.0);
    msg3.set_price(150.0);

    OrderMessage msg4;
    msg4.set_order_id(4);
    msg4.set_user_id(2);
    msg4.set_symbol("AAPL");
    msg4.set_side(Direction::SHORT);
    msg4.set_transaction_time(987654321);
    msg4.set_order_quantity(15.0);
    msg4.set_price(150.0);

    OrderMessage msg5;
    msg5.CopyFrom(msg);
    msg5.set_order_id(5);
    msg5.set_side(Direction::LONG);
    msg5.set_order_quantity(10.0);

    MatchingEngine engine = MatchingEngine();
    std::cout << "Message 1" << std::endl;
    engine.handle_order_message(&msg);

    std::cout << "Message 2" << std::endl;
    engine.handle_order_message(&msg2);

    std::cout << "Message 3" << std::endl;
    engine.handle_order_message(&msg3);

    std::cout << "Message 4" << std::endl;
    engine.handle_order_message(&msg4);

    std::cout << "Message 5" << std::endl;
    engine.handle_order_message(&msg5);
}

int main() {
    MatchingEngine engine = MatchingEngine();

    engine.run_engine();
    return 0;
}