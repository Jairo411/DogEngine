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
		std::cout << "Can't start WinSock: " << "error: "<< WSAGetLastError();
		return false;
	}

	serverSocket = socket(AF_INET, SOCK_DGRAM, 0);

	if (serverSocket==INVALID_SOCKET)
	{
		std::cout << "Invalid socket: " << "error: " << WSAGetLastError();
		return false;
	}

	server.sin_family = AF_INET;
	server.sin_port = htons(54000);
	iResult = inet_pton(AF_INET, ipAddress_, &server.sin_addr);
	if (iResult!=1)
	{
		std::cout << "couldn't connect to ip " << " error: " <<WSAGetLastError();
		return false;
	}

	isRunning = true;
	Speak();
	return true;
}

void Client::Inti()
{
	/* At first it will be like this just to set it up, but grab SDL window Information from the server */
	if (isWindowOn)
	{
		Clientwindow = new Window("Client Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
	}
	handleLoop();
}

void Client::handleLoop()
{
	while (isRunning!=false)
	{
		if (recvBuf=="listen")
		{
			Listen();
		}
		
		OnUpdate();
		OnRender();
	}
}

void Client::Listen()
{
	readMessage();
}

void Client::Speak()
{
	sendMessage<const char*>("inti");
}

void Client::OnUpdate()
{
	Clientwindow->OnUpdate();
}

void Client::OnRender()
{
	Clientwindow->OnRender();
}

const char* Client::readMessage()
{
	int bytesIn = recvfrom(serverSocket, recvBuf, 1024, 0, (sockaddr*)&server, &serverSize);
	if (bytesIn == SOCKET_ERROR)
	{
		std::cout << "Error receiving from Server " << WSAGetLastError() << std::endl;
	}
	std::cout << recvBuf << std::endl;
	return recvBuf;
}
