#ifndef MATCHING_ENGINE_H
#define MATCHING_ENGINE_H

#include <vector>
#include <string>
#include <unordered_map>

#include <trade.h>


class MatchingEngine {
    std::unordered_map<std::string, std::vector<Trade>> trade_queue;
    
    public:
        /**
         * @brief Construct a new Matching Engine object
         * 
         */
        MatchingEngine();
        
        /**
         * @brief 
         * 
         */
        void run_engine();
};

# endif