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

class MatchingEngine {
    std::map<std::string, std::map<float, std::deque<std::unique_ptr<Order>>>> order_book;
    
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
};

# endif