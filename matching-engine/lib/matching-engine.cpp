#include <unordered_map>
#include <vector>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <iomanip>
#include<cstdio>

#include <matching-engine.h>
#include <trade.h>
#include <trademessage.pb.h>

MatchingEngine::MatchingEngine() {
    order_book = std::map<std::string, std::map<float, std::deque<Trade>>>();
}

static bool engine_running = true;

void receive_message(OrderMessage * msg, int clientSocket) {
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

        receive_message(&order_message, client);

        std::cout << order_message.DebugString() << "\n";
        std::cout << "Mission complete";

        char response[6] = "Helo!";
        send(client, response, sizeof(response), 0);
    }
}