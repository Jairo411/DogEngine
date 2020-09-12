#include "Game.h"	
#include <iostream>
#include <SDL.h>

//An array to store frame times:
using namespace std;



Game *game = nullptr;

int main(int argc,char * argv[]) {
	
	const int FPS = 60;
	/*You're an idiot the frameDelay variable will only delay SDL from running you dumbass */
	const int frameDelay =  1000/FPS;
	Uint32 frameStart;
	int frametime;
	game = new Game();	
	game->init("Andre's Quest ", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

	while (game->running()) {
		
		frameStart = SDL_GetTicks();

		
		game->OnUpdate();
		game->OnRender();
		game->handleCollisions();
		game->HandleEvents();

		frametime = SDL_GetTicks() - frameStart;
		

		if (frameDelay>frametime)
		{
			SDL_Delay(frameDelay - frametime);
		
		}
		
		/*You need to add some functionality/extra variables in order to display the fps 
		because your frame Delay is a variable that only stop SDL from screen tearing. I.e you're FPS locking you're program 
		right now.*/
		//You're if statement is making sure cpu is cooperating with SDL. 
		//fix this shit please 
		
	}

	game->clean();

	std::getchar();

	return 0;
}
