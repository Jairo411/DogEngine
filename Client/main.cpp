#include<iostream>
#include "Client.h"
#include "Window.h"
int main(int argc, char* argv[])
{
	Client client;
	char hostname[100];
	if (client.connetToServer("192.168.1.12"))
	{
		gethostname(hostname, sizeof(hostname));
		std::cout << "Connected to " << hostname << std::endl;

		/// <summary>
		/// THIS IS WHERE CLIENT LOOP GETS INTIALIZED/RUNS
		/// </summary>
		/// <returns></returns>
		client.Inti();
	
	}
	else
	{

	}
	
	return 0;
}