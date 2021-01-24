#include <iostream>
#include "Server.h"
#include "message.h"
int main(int argv, char** args)
{
	Server server0;

	if (server0.IntiServer("192.168.1.12"))
	{
		while (server0.getisRunning()!=false)
		{
			server0.handleLoop();

		}
	}
	return 0;
}