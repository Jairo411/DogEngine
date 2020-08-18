#include "Input.h"
#include <SDL.h>
Input::~Input()
{
}

bool Input::keyPressed(int is_pressed,int keycode)
{
	if (SDL_PRESSED == is_pressed)
	{
		InputHolder->insert(std::pair<int,bool>(keycode,true));
		return true;
	}
	else if (SDL_RELEASED)
	{
		keycode = NULL;
		InputHolder->insert(std::pair<int, bool>(keycode, false));
		return true;
	}
	return false;
}
