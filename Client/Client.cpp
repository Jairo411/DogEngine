#include "Client.h"

Client::Client()
{
}

Client::~Client()
{
}

bool Client::connetToServer(const char* ipAddress_)
{
	version = MAKEWORD(2, 2);
	iResult = WSAStartup(version, &wsaData);
	IPAddress = ipAddress_;
	if (iResult != 0)
	{
		std::cout << "Can't start WinSock: " << iResult;
		return false;
	}

	serverSocket = socket(AF_INET, SOCK_DGRAM, 0);

	server.sin_family = AF_INET;
	server.sin_port = htons(54000);
	inet_pton(server.sin_family, ipAddress_, &server.sin_addr);
	

	return true;
}

void Client::handleLoop()
{
}
