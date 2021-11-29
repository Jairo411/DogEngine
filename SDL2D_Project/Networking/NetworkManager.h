#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include<stdio.h>
#include <WinSock2.h>

#pragma comment(lib,"ws2_32.lib") //Winsock Library

#define SERVER "127.0.0.1" // ip address of udp server
#define BUFLEN 512 // Max legth of buffer

#define PORT 8888 //The port on which to listen for incoming data

class NetworkManager
{
public:
	NetworkManager();
	~NetworkManager();
	void startProcess();
private:

};
#endif
