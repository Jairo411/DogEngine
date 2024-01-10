#include "DogEngine.h"	
#include <iostream>
#include <SDL_main.h>

DogEngine *engine = nullptr;

int main(int argc,char * argv[]) {
	
	engine->GetInstance();
	return 0;
}
