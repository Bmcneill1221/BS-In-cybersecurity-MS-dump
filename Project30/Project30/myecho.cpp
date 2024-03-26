//Blaze McNeill
#include <iostream>
#include <WinSock2.h>
#include <ws2tcpip.h>
using namespace std;

#pragma comment(lib, "Ws2_32.lib")

#define DEFAULT_PORT "7"
#define DEFAULT_BUFLEN 512

int main(int argc, char** argv) {
    // Initialize Winsock
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        cout << "WSAStartup failed: " << iResult << endl;
        return 1;
    }

    const char* host = "PE-HRFIELDS-1";
    const char* service = DEFAULT_PORT;

    // Check command-line arguments
    if (argc > 1) {
        host = argv[1];
        if (argc > 2) {
            service = argv[2];
        }
    }

    // Create socket
    struct addrinfo* result = NULL, hints;
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    // Resolve server address and port
    iResult = getaddrinfo(host, service, &hints, &result);
    if (iResult != 0) {
        cout << "getaddrinfo failed: " << iResult << endl;
        WSACleanup();
        return 1;
    }

    // Create socket
    SOCKET ConnectSocket = INVALID_SOCKET;
    ConnectSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (ConnectSocket == INVALID_SOCKET) {
        cout << "Error at socket(): " << WSAGetLastError() << endl;
        freeaddrinfo(result);
        WSACleanup();
        return 1;
    }

    // Connect to server
    iResult = connect(ConnectSocket, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        closesocket(ConnectSocket);
        ConnectSocket = INVALID_SOCKET;
    }

    freeaddrinfo(result);

    if (ConnectSocket == INVALID_SOCKET) {
        cout << "Unable to connect to server \n";
        WSACleanup();
        return 1;
    }

    // Send and receive data in a loop
    int recvbuflen = DEFAULT_BUFLEN;
    char sendbuf[DEFAULT_BUFLEN];
    char recvbuf[DEFAULT_BUFLEN];

    while (true) {
        cout << "Message to send (type QUIT to exit): ";
        cin.getline(sendbuf, DEFAULT_BUFLEN);

        if (_stricmp(sendbuf, "QUIT") == 0)
            break;

        iResult = send(ConnectSocket, sendbuf, (int)strlen(sendbuf) + 1, 0);
        if (iResult == SOCKET_ERROR) {
            cout << "SEND FAILED: " << WSAGetLastError() << endl;
            closesocket(ConnectSocket);
            WSACleanup();
            return 1;
        }

        cout << "Bytes sent: " << iResult << endl;

        iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
        if (iResult > 0) {
            cout << "Message received: " << recvbuf << endl;
            cout << "Bytes received: " << iResult << endl;
        }
        else if (iResult == 0) {
            cout << "Connection closed \n";
            break;
        }
        else {
            cout << "recv failed: " << WSAGetLastError() << endl;
            break;
        }
    }

    // Disconnect
    closesocket(ConnectSocket);
    WSACleanup();

    return 0;
}
