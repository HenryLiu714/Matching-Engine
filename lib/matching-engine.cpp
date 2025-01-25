#include <unordered_map>
#include <vector>
#include <conio.h>

#include <matching-engine.h>
#include <trade.h>

MatchingEngine::MatchingEngine() {
    trade_queue = std::unordered_map<std::string, std::vector<Trade>>();
}

static bool engine_running = false;

void MatchingEngine::keyboard_listener() {
    while (true) {
        if (_getch() == 'q') {
            engine_running = false;
            return;
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

    while (engine_running) {
        
    }
}