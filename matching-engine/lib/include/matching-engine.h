#ifndef MATCHING_ENGINE_H
#define MATCHING_ENGINE_H

#include <vector>
#include <string>
#include <map>
#include <deque>
#include <memory>
#include<stdlib.h>

#include <order.h>
#include <trademessage.pb.h>

// TODO: Move to a config file
static const int ORDER_PORT = 56000;
static const int RESPONSE_PORT = 56001;
static const std::string RESPONSE_IP = "127.0.0.1";

class MatchingEngine {
    std::map<std::string, std::map<float, std::deque<std::unique_ptr<Order>>>> order_book;
    std::vector<OrderResponse> order_responses;

    int server_socket;
    int client_socket;
    
    public:
        /**
         * @brief Construct a new Matching Engine object
         * 
         */
        MatchingEngine();
        
        /**
         * @brief Runs our matching engine
         * 
         */
        void run_engine();
    
    // private:
        void handle_order_message(OrderMessage* msg);

        std::vector<OrderResponse> add_to_order_book(std::unique_ptr<Order> order);

        void poll_orders();

        void handle_responses();

        int setup_server_socket();

        int setup_client_socket();

        bool receive_order_message(OrderMessage* msg, int clientSocket);

        bool send_response_message(OrderResponse* response, int sock);

        OrderResponse construct_response(Order* order, OrderStatus status, float quantity);
};

# endif