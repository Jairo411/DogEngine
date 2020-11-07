#include <SDL.h>
#include "Input.h"
#include "../Window/Window.h"

RectCollider* Input::mouseClick = new RectCollider();
int Input::mouseX = 0, Input::mouseY = 0;

Input::~Input()
{
}

bool Input::keyPressed(int is_pressed,int keycode)
{
	InputKeyBoardHolder.clear();
	if (SDL_PRESSED == is_pressed)
	{
		if (SDL_KEYDOWN)
		{
			/* You should add this to your player class then send the keycode to another function
		 Function within a function*/ 
			InputKeyBoardHolder.insert(std::pair<int, bool>(keycode, true));	
			return true;
		}
	}
	else if (SDL_RELEASED==is_pressed)
	{
		if (SDL_KEYUP)
		{
			keycode = NULL;
			InputKeyBoardHolder.insert(std::pair<int, bool>(keycode, false));
			return true;
		}
	} 
}

bool Input::MousePressed(int is_Pressed, int keycode)
{
	InputMouseHolder.clear();
	if (SDL_PRESSED== is_Pressed)
	{
		if (SDL_MOUSEBUTTONDOWN)
		{
			SDL_GetMouseState(&mouseX, &mouseY);
			InputMouseHolder.insert(std::pair<int, bool>(keycode, true));																										
			return true;
		}
	}
	else if (SDL_RELEASED== is_Pressed)
	{
		if (SDL_MOUSEBUTTONUP)
		{
			InputMouseHolder.insert(std::pair<int, bool>(keycode, false));
			return true;
		}
	}
	return false;
}

void Input::setWindow(Window* windowptr_)
{
	window = windowptr_;
}

void Input::setMiddlePoint(Vec2 tempV)
{
	middlepoint = tempV;
}

Vec2 Input::getMiddlePoint()
{
	return middlepoint;
}

bool Input::CreateCollider(bool state_)
{
	if (state_==true)
	{
		mouseClick = new RectCollider(mouseX, mouseY, 10);
	}
	else if (state_==false)
	{
		mouseClick = NULL;
	}
	return false;
}


