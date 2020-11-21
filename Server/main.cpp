#include <iostream>
#include "Server.h"
#include "message.h"
int main()
{
	Server server0;

	if (server0.IntiServer("192.168.0.25"))
	{
		while (server0.getisRunning()!=false)
		{
			server0.handleLoop();

		}
	}
}