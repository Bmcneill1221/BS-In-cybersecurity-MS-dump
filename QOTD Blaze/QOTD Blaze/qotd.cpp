#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>
#include <chrono>
#include <thread>

#pragma comment(lib, "Ws2_32.lib")

int wait(SOCKET s, int sec, int msec) {
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(s, &fds);

    timeval tv;
    tv.tv_sec = sec;
    tv.tv_usec = msec * 1000;

    return select(0, &fds, NULL, NULL, &tv);
}

int main(int argc, char* argv[]) {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup failed.\n";
        return 1;
    }

    SOCKET sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sock == INVALID_SOCKET) {
        std::cerr << "Socket creation failed with error: " << WSAGetLastError() << '\n';
        WSACleanup();
        return 1;
    }

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(17); // QOTD well-known port
    const char* serverIP = argc > 1 ? argv[1] : "PE-HRFIELDS-1"; //DO NOT FORGET TO CHANGE!!!!!
    inet_pton(AF_INET, serverIP, &serverAddr.sin_addr);

    char buffer[1024];
    std::string command;
    do {
        std::cout << "Command to send? ";
        std::getline(std::cin, command);

        // Convert command to lowercase for case-insensitive comparison
        for (auto& c : command) c = tolower(c);

        if (command == "quit") break;

        if (sendto(sock, command.c_str(), strlen(command.c_str()) + 1, 0, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
            std::cerr << "Sendto failed with error: " << WSAGetLastError() << '\n';
            continue;
        }

        if (command == "sendqotd") {
            std::string fullQuote;
            int attempts = 0;
            do {
                if (wait(sock, 2, 0) > 0) { // Adjusted timeout for demonstration. Hope this works now
                    int serverAddrSize = sizeof(serverAddr);
                    memset(buffer, 0, sizeof(buffer)); // Clear buffer before receiving may make it work now?   YES!
                    int bytesReceived = recvfrom(sock, buffer, sizeof(buffer) - 1, 0, (sockaddr*)&serverAddr, &serverAddrSize);
                    if (bytesReceived > 0) {
                        fullQuote.append(buffer, bytesReceived);
                        attempts = 0; // Reset attempts after successful receive
                    }
                }
                else {
                    attempts++; // Increment attempts if no data received
                }
            } while (attempts < 2); // Exit loop after 2 consecutive timeouts indicating no more data

            std::cout << "Quote of the day:\n" << fullQuote << '\n';
        }
    } while (true);

    closesocket(sock);
    WSACleanup();
    return 0;
}
