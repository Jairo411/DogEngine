#include<iostream>
#include "Client.h"
int main()
{
	Client client;
	char hostname[100];
	if (client.connetToServer("192.168.0.25"))
	{
		gethostname(hostname, sizeof(hostname));
		std::cout << "Connected to " << hostname << std::endl;
		system("pause");
	}


	return 0;
}