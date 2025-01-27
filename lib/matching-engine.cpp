#include <unordered_map>
#include <vector>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>

#include <matching-engine.h>
#include <trade.h>
#include <trademessage.pb.h>

MatchingEngine::MatchingEngine() {
    trade_queue = std::unordered_map<std::string, std::vector<Trade>>();
}

static bool engine_running = false;

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
        std::cout << "next" << std::endl;
        int client = accept(entry_socket, nullptr, nullptr);

        char buffer[1024] = {0};
        recv(client, buffer, sizeof(buffer), 0);

        std::cout << "Message received: " << buffer << std::endl;
    }
}