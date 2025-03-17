#include <unordered_map>
#include <vector>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <iomanip>
#include<cstdio>
#include <memory>

#include <matching-engine.h>
#include <order.h>
#include <trademessage.pb.h>

MatchingEngine::MatchingEngine() {
    order_book = std::map<std::string, std::map<float, std::deque<std::unique_ptr<Order>>>>();
}

static bool engine_running = true;

void receive_order_message(OrderMessage* msg, int clientSocket) {
    uint32_t msgLength;
    int bytesReceived = recv(clientSocket, &msgLength, sizeof(msgLength), 0);
    if (bytesReceived <= 0) {
        std::cerr << "Failed to receive message length." << std::endl;
        return;
    }

    msgLength = ntohl(msgLength);  // Convert from network byte order

    char *buffer = new char[msgLength];
    bytesReceived = recv(clientSocket, buffer, msgLength, 0);

    if (bytesReceived <= 0) {
        std::cerr << "Failed to receive message." << std::endl;
    } else {
        if (msg->ParseFromArray(buffer, msgLength)) {
            std::cout << "Success!";
        } else {
            std::cerr << "Failed to parse Protobuf message." << std::endl;
        }
    }
}

/**
 * @brief 
 * TODO: Multithreading for input does not work
 */
void MatchingEngine::run_engine() {
    // std::thread check_engine_running(&MatchingEngine::keyboard_listener);

    int current_user_id = 0;
    
    // Setting up server socket
    int entry_socket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(56000);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Binding socket, setting to server mode
    bind(entry_socket, (struct sockaddr*) &server_address, sizeof(server_address));
    listen(entry_socket, 5);

    // Start engine polling loop
    while (engine_running) {
        std::cout << "Waiting for next order....." << std::endl;
        int client = accept(entry_socket, nullptr, nullptr);

        OrderMessage order_message;

        receive_order_message(&order_message, client);

        std::cout << order_message.DebugString() << "\n";

        char response[6] = "Helo!";
        send(client, response, sizeof(response), 0);
    }
}

/**
 * @brief Helper function to handle incoming order messages.
 * 
 * TODO: Instead of converting to oder, take in an OrderMessage smart pointer and send it to the order book
 * TODO: Connect to socket on receiving port and send response
 * @param msg 
 */
void MatchingEngine::handle_order_message(OrderMessage* msg) {
    // Create Order object
    std::unique_ptr<Order> order = std::make_unique<Order>(
        msg->order_id(),
        msg->user_id(),
        msg->symbol(),
        msg->side(),
        msg->transaction_time(),
        msg->order_quantity(),
        msg->price()
    );

    // Add order to order book
    std::vector<OrderResponse> responses = add_to_order_book(std::move(order));

    // Print responses for debugging
    for (const auto& response : responses) {
        std::cout << "Response: " << response.DebugString() << std::endl;
    }
}

/**
 * @brief Helper function to create an OrderResponse object from an order and its status.
 * 
 * @param order 
 * @param status 
 * @return OrderResponse 
 */
OrderResponse construct_response(Order* order, OrderStatus status, float quantity) {
    OrderResponse response;
    response.set_order_id(order->order_id);
    response.set_user_id(order->user_id);
    response.set_symbol(order->symbol);
    response.set_side(order->direction);
    response.set_transaction_time(order->transaction_time);
    response.set_order_quantity(quantity);
    response.set_price(order->price);
    response.set_status(status);
    return response;
}

std::vector<OrderResponse> MatchingEngine::add_to_order_book(std::unique_ptr<Order> order) {
    // Check for corresponding order
    std::string symbol = order->symbol;
    int direction = (order->direction == Direction::LONG) ? 1 : -1;

    std::vector<OrderResponse> responses;

    // Add symbol to order_book, if not in already
    if (order_book.find(symbol) == order_book.end()) {
        order_book[symbol] = std::map<float, std::deque<std::unique_ptr<Order>>>();
    }

    // Add order to order_book
    float price = order->price * direction;
    float corresponding_price = price * -1; // Matching order
    float starting_quantity = order->order_quantity;

    while (order->order_quantity > 0) {
        // Check if there is a matching order
        if (order_book[symbol].find(corresponding_price) == order_book[symbol].end() || order_book[symbol][corresponding_price].empty()) {
            // No matching order, add to order book
            if (order_book[symbol].find(price) == order_book[symbol].end()) {
                order_book[symbol][price] = std::deque<std::unique_ptr<Order>>();
            }
            
            std::unique_ptr<Order> order_copy = std::make_unique<Order>(*order);
            order_book[symbol][price].push_back(std::move(order_copy));

            if (starting_quantity == order->order_quantity) {
                responses.push_back(construct_response(order.get(), OrderStatus::PENDING, 0)); // No shares filled yet
            } 
            
            else {
                responses.push_back(construct_response(order.get(), OrderStatus::PARTIAL, starting_quantity - order->order_quantity)); // Some shares filled
            }

            break;
        }

        // Found a matching order
        if (order_book[symbol][corresponding_price].front()->order_quantity >= order->order_quantity) {
            
            // Matching order can fully fill the incoming order
            order_book[symbol][corresponding_price].front()->order_quantity -= order->order_quantity;

            // Matching order is also filled
            if (order_book[symbol][corresponding_price].front()->order_quantity == 0) {
                responses.push_back(construct_response(order_book[symbol][corresponding_price].front().get(), OrderStatus::FILLED, order->order_quantity)); // All shares filled
                order_book[symbol][corresponding_price].pop_front();
            }
            
            else {
                responses.push_back(construct_response(order_book[symbol][corresponding_price].front().get(), OrderStatus::PARTIAL, order->order_quantity)); // Some shares filled
            }

            order->order_quantity = 0; // All filled
            responses.push_back(construct_response(order.get(), OrderStatus::FILLED, starting_quantity)); // No shares left
        } else {
            // Incoming order can fully fill the matching order
            order->order_quantity -= order_book[symbol][corresponding_price].front()->order_quantity;
            responses.push_back(construct_response(order_book[symbol][corresponding_price].front().get(), OrderStatus::FILLED, order_book[symbol][corresponding_price].front()->order_quantity)); // All shares filled
            order_book[symbol][corresponding_price].pop_front(); // Remove filled order
        }
    }

    return responses;
}