#include "DogEngine.h"	
#include <iostream>
#include <SDL.h>

//An array to store frame times:
using namespace std;

DogEngine *game = nullptr;

int main(int argc,char * argv[]) {
	game = new DogEngine();

	return 0;
}
