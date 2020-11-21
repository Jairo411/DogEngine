#include "Server.h"

Server::Server()
{
}

Server::~Server()
{
}

bool Server::IntiServer(const char* ipAddress_)
{
	isRunning = true;
	sockaddr_in *ptr;


	//Initialize Winsock
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0)
	{
		printf("WSAStartup failed with error: %d\n", iResult);
		system("pause");
		return false;
	}



	service.sin_addr.S_un.S_addr = inet_addr(ipAddress_);
	service.sin_family = AF_INET;
	service.sin_port = htons(54000); // convert from little to big endian

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_DGRAM;
	hints.ai_protocol = IPPROTO_UDP;
	hints.ai_flags = AI_PASSIVE;

	iResult = getaddrinfo(ipAddress_, DEFAULT_PORT, &hints, &addresult);


	if (iResult != 0)
	{
		std::cerr << "Error" << WSAGetLastError() <<
			"when getting addressinfo" << std::endl;
		return false;
	}

	listenSocket = socket(addresult->ai_family, addresult->ai_socktype, addresult->ai_protocol);
	if (listenSocket == INVALID_SOCKET) {
		printf("socket failed with error: %ld\n", WSAGetLastError());
		freeaddrinfo(addresult);
		WSACleanup();
		return false;
	}

	if (gethostname(hostname, sizeof(hostname)) == SOCKET_ERROR)
	{
		std::cerr << "Error " << WSAGetLastError() <<
			" when getting host name." << std::endl;
		return false;
	}

	std::cout << "Host name is " << hostname << std::endl;



	iResult = bind(listenSocket, (sockaddr*)&service, sizeof(service));
	if(iResult==SOCKET_ERROR)
	{
		std::cout << "Socket bind failed: " << WSAGetLastError() << std::endl;
		return false;
	}

	ptr = (struct sockaddr_in*)addresult->ai_addr;
	std::cout << "IPv4 address: " << inet_ntoa(ptr->sin_addr) << std::endl;

	freeaddrinfo(addresult);

	std::cout << "Server Set Up" << std::endl;
	
	return true;

}
bool Server::getisRunning()
{
	return isRunning;
}
/*Does all server stuff*/
void Server::handleLoop()
{
	while (isRunning == true)
	{
		Listen();
		Update(deltaTime);
	}
	// std::cout << getTime();
}

void Server::Update(float deltaTime_)
{

}

void Server::Listen()
{
	int clientLength = sizeof(client);
	ZeroMemory(&clientListener, clientLength);
	ZeroMemory( recvBuf, 1024);

	int bytesIn = recvfrom(listenSocket, recvBuf, 1024, 0, (sockaddr*)&client, &clientLength);
	if (bytesIn==SOCKET_ERROR)
	{
		std::cout << "Error receiving from client" << WSAGetLastError() << std::endl;
	}
	
}

std::string Server::getTime()
{
	std::string currentT;

	std::time_t result = std::time(nullptr);
	currentT = std::asctime(std::localtime(&result));


	return currentT;
}
