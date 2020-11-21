#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include <WS2tcpip.h>
#include <chrono>
#include <time.h>
#include <vector>

//Include the Winsock library (lib) file
#pragma comment (lib, "ws2_32.lib")

#define DEFAULT_BUFLEN 1024
#define DEFAULT_PORT "1986"

class Client
{
public:
	Client();
	~Client();
	bool connetToServer(const char *ipAddress_);
	void handleLoop();
private:
	WSADATA wsaData;
	WORD version;
	// Create a UDP Socket
	SOCKET serverSocket;
	//create a hint structures
	sockaddr_in server;
	struct addrinfo* result = NULL,* ptr = NULL;
	int serverSize = sizeof(server);
	int recvbuflen[DEFAULT_BUFLEN];
	int iResult;
	const char *IPAddress;
	
};
#endif