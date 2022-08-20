#include "DogEngine.h"	
#include <iostream>

DogEngine *engine = nullptr;

int main(int argc,char * argv[]) {
	
	engine->GetInstance();
	return 0;
}
