#ifndef MATCHING_ENGINE_H
#define MATCHING_ENGINE_H

#include <vector>
#include <string>
#include <map>

#include <trade.h>


class MatchingEngine {
    std::map<std::string, std::map<float, Trade>> order_book;
    
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
};

# endif