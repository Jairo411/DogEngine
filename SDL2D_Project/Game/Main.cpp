#include "Game.h"	
#include <iostream>
#include <SDL.h>

//An array to store frame times:
using namespace std;

Game *game = nullptr;

int main(int argc,char * argv[]) {
	game = new Game();

	return 0;
}
