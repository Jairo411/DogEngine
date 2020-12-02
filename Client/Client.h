#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include <WS2tcpip.h>
#include <chrono>
#include <time.h>
#include <vector>
#include<sstream>
#include "Window.h"
//Include the Winsock library (lib) file
#pragma comment (lib, "ws2_32.lib")
#define DEFAULT_BUFLEN 1024
#define DEFAULT_PORT "1986"

class Client
{
public:
	Client();
	~Client();
	bool connetToServer(const char* ipAddress_);
	void Inti();
	void handleLoop();
	void Listen();
	void Speak();
	void OnUpdate();
	void OnRender();
private:

	template <class T>
	void sendMessage(T messageType)
	{
		std::stringstream stream;
		stream << messageType;

		std::string convertedString = stream.str();

		iResult = sendto(serverSocket, convertedString.c_str(), convertedString.size()+1, 0, (sockaddr*)&server, sizeof(server));
		if (iResult == SOCKET_ERROR)
		{
			std::cout << "ERROR with the connection: " << WSAGetLastError() << std::endl;
		}


	}

	const char* readMessage();


	bool isWindowOn = false;
	/*Client SDL Window*/
	Window* Clientwindow;
	/*Server Side Stuff*/
	WSADATA wsaData;
	WORD version;
	// Create a UDP Socket
	SOCKET serverSocket;
	//create a hint structures
	sockaddr_in server;
	struct addrinfo* result = NULL, * ptr = NULL;
	int serverSize = sizeof(server);
	int recvbuflen[DEFAULT_BUFLEN];
	int iResult;
	const char* IPAddress;
	char recvBuf[DEFAULT_BUFLEN];
	bool isRunning;
	/*Server Side Stuff*/
};
#endif