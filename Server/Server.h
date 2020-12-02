#ifndef SERVER_H
#define SERVER_H
#define WIN32_LEAN_AND_MEAN
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#pragma comment(lib, "Ws2_32.lib");

#include<Windows.h>
#include<WinSock2.h>
#include<WS2tcpip.h>
#include<vector>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include <ctime>
#include<sstream>
#include<string>



#define DEFAULT_BUFLEN 1024
#define DEFAULT_PORT "1986"

class Client;
class GameState;
class Server
{
public:
	Server();
	~Server();
	bool IntiServer(const char* ipAddress_);
	bool getisRunning();
	void handleLoop();
	void Update(float deltaTime_);
	void Speak();
	void Listen();

private:

	std::string testVariable = "TEST";

	template <class T>
	void sendMessage(T messageType)
	{
		std::stringstream stream;
		stream << messageType;

		std::string convertedString = stream.str();
		convertedString + getTime();

		iResult = sendto(listenSocket, convertedString.c_str(), convertedString.size()+1, 0, (sockaddr*)&client, sizeof(client));
		if (iResult == SOCKET_ERROR)
		{
			std::cout << "ERROR with the connection: " << WSAGetLastError() << std::endl;
		}


	}
	const char* ReadMessage();

	//your getTime function will be outdated and not functional on
//03:14 : 07 UTC on 19 January 2038 but who cares 
	std::string getTime();


	WSADATA wsaData;
	SOCKET listenSocket = INVALID_SOCKET;
	SOCKET clientListener;
	//std::vector<SOCKET> clientSocket;
	sockaddr_in service;
	sockaddr_in client;
	struct addrinfo hints;
	struct addrinfo* addresult;
	int iResult;

	char hostname[DEFAULT_BUFLEN];
	char recvBuf[DEFAULT_BUFLEN];
	int recvBufLength = DEFAULT_BUFLEN;
	int clientLength = sizeof(client);


	bool isRunning;
	int recvBuflen = DEFAULT_BUFLEN;
	float deltaTime;


};

class ClientStatus
{
public:

private:

};
#endif // !SERVER_H
