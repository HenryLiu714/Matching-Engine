#include <unordered_map>
#include <vector>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <iomanip>
#include<cstdio>
#include <memory>
#include <stdexcept>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>  // For getaddrinfo()

#include <matching-engine.h>
#include <order.h>
#include <trademessage.pb.h>

static bool engine_running = true;

MatchingEngine::MatchingEngine() {
    order_book = std::map<std::string, std::map<float, std::deque<std::unique_ptr<Order>>>>();
    order_responses = std::vector<OrderResponse>();

    server_socket = setup_server_socket();
}

/**
 * @brief Set the up server socket object
 * 
 * @return int 
 */
int MatchingEngine::setup_server_socket() {
    // Setting up server socket
    int entry_socket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(ORDER_PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Binding socket, setting to server mode
    bind(entry_socket, (struct sockaddr*) &server_address, sizeof(server_address));
    listen(entry_socket, 5);

    return entry_socket;
}

/**
 * @brief Receive an OrderMessage from the client socket.
 * Helper method for poll_orders()
 * 
 * @param msg 
 * @param clientSocket 
 * @return true 
 * @return false 
 */
bool MatchingEngine::receive_order_message(OrderMessage* msg, int clientSocket) {
    uint32_t msgLength;
    int bytesReceived = recv(clientSocket, &msgLength, sizeof(msgLength), 0);
    if (bytesReceived <= 0) {
        std::cerr << "Failed to receive message length." << std::endl;
        return false;
    }

    msgLength = ntohl(msgLength);  // Convert from network byte order

    char *buffer = new char[msgLength];
    bytesReceived = recv(clientSocket, buffer, msgLength, 0);

    if (bytesReceived <= 0) {
        std::cerr << "Failed to receive message." << std::endl;
    } else {
        if (!msg->ParseFromArray(buffer, msgLength)) {
            std::cerr << "Failed to parse OrderMessage" << std::endl;
            return false;
        }
    }

    return true;
}

bool MatchingEngine::send_response_message(OrderResponse* response) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sock < 0) {
        std::cerr << "Failed to create socket." << std::endl;
        return -1;
    }

    // Resolve the hostname to an IP address
    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;  // IPv4
    hints.ai_socktype = SOCK_STREAM;

    int status = getaddrinfo(RESPONSE_HOST.c_str(), NULL, &hints, &res);
    if (status != 0) {
        std::cerr << "getaddrinfo failed: " << gai_strerror(status) << std::endl;
        return 1;
    }

    struct sockaddr_in *server_in = (struct sockaddr_in *)res->ai_addr;
    char *ip_str = inet_ntoa(server_in->sin_addr); // Convert binary IP to string

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(RESPONSE_PORT); 

    if (inet_pton(AF_INET, ip_str, &server_addr.sin_addr) <= 0) {
        std::cout << ip_str << " is not a valid address." << std::endl;
        std::cerr << "Invalid address/Address not supported." << std::endl;
        close(sock);
        return -1;
    }

    // Connect to server
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Connection to response server unsuccessful." << std::endl;
        close(sock);
        return -1;
    }
    
    // Send the response message
    std::string message;

    if (!response->SerializeToString(&message)) {
        std::cerr << "Failed to serialize response message." << std::endl;
        return false;
    }
    // Send the length of the message first
    uint32_t message_length = htonl(message.size());

    send(sock, &message_length, sizeof(message_length), 0);

    if (send(sock, message.c_str(), message.size(), 0) < 0) {
        std::cerr << "Failed to send response message." << std::endl;
        return false;
    } else {
        std::cout << "Sent response: " << response->order_id() << std::endl;
    }

    close(sock);

    return true;
 }

/**
 * @brief Polls for orders on the entry socket and processes them.
 * 
 * @param entry_socket 
 */
void MatchingEngine::poll_orders() {
    std::cout << "Waiting for next order....." << std::endl;
    int client = accept(server_socket, nullptr, nullptr);

    OrderMessage order_message;
    char* response;

    // Receive incoming order
    if (!receive_order_message(&order_message, client)) {
        std::cerr << "Failed to receive order message." << std::endl;
        response = "Error parsing message\n";
    }
    
    else {
        std::cout << "Received order: " << order_message.order_id() << "\n";
        response = "Order received\n";
    }
    
    handle_order_message(&order_message);
    send(client, response, strlen(response), 0);
}

void MatchingEngine::handle_responses() {
    // Send all order responses to the client
    for (OrderResponse response : order_responses) {
        if (!send_response_message(&response)) {
            std::cerr << "Failed to send response message: " << response.order_id() <<std::endl;
        }
    }
    order_responses.clear(); // Clear responses after sending
}

/**
 * @brief 
 * TODO: Multithreading for input does not work
 * TODO: Add error handling for socket connections
 */
void MatchingEngine::run_engine() {
    // std::thread check_engine_running(&MatchingEngine::keyboard_listener);

    int current_user_id = 0;

    // Start engine polling loop
    while (engine_running) {
        poll_orders();
        handle_responses();
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
    std::vector<OrderResponse> new_responses = add_to_order_book(std::move(order));

    // Add new responses to response vector
    order_responses.insert(order_responses.end(), new_responses.begin(), new_responses.end());
}

/**
 * @brief Helper function to create an OrderResponse object from an order and its status.
 * 
 * @param order 
 * @param status 
 * @return OrderResponse 
 */
OrderResponse MatchingEngine::construct_response(Order* order, OrderStatus status, float quantity) {
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