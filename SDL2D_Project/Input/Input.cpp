#include <SDL.h>
#include "Input.h"
#include "../Window/Window.h"

RectCollider* Input::mouseClick = new RectCollider();
int Input::mouseX = 0, Input::mouseY = 0;

Input::~Input()
{
}

void Input::SetEvent(SDL_Event* event_)
{
	currentEvent = event_;
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

MouseInput::MouseInput()
{
	mouseX = 0;
	mouseY = 0;
	buttons = 0;
	wheel = 0;
	InputMouseHolder = std::map<int, bool>();
}

MouseInput::~MouseInput()
{
	InputMouseHolder.empty();
}

std::vector<int> MouseInput::getMouse()
{
	std::vector<int> temp;

	temp.push_back(mouseX);
	temp.push_back(mouseY);

	return temp;
}

std::vector<int> MouseInput::getButtons()
{
	std::vector<int> temp;

	int tempButton = buttons & SDL_BUTTON(SDL_BUTTON_LEFT);
	int tempButton1 = buttons & SDL_BUTTON(SDL_BUTTON_RIGHT);

	temp.push_back(tempButton);
	temp.push_back(tempButton1);

	return temp;
}

int MouseInput::GetWheel()
{
	return wheel;
}


void MouseInput::HandleEvents()
{
	int buttons = SDL_GetMouseState(&mouseX, &mouseY);
	switch (currentEvent->type)
	{
	default:
		break;
		
	case SDL_MOUSEBUTTONUP: //Should be used for singluar clicks
		InputMouseHolder.insert(std::pair<int, bool>());
		break;
	case SDL_MOUSEBUTTONDOWN:  //Should be used when holding down the button
		
		InputMouseHolder.insert(std::pair<int, bool>());
		break;

	case SDL_MOUSEWHEEL: //Should be used when using the scrolling wheel
		InputMouseHolder.insert(std::pair<int, bool>());
		wheel = currentEvent->wheel.y;
		break;
	}
}

KeyBoardInput::KeyBoardInput()
{
	InputKeyBoardHolder = std::map<int, bool>();
}

KeyBoardInput::~KeyBoardInput()
{
}



void KeyBoardInput::HandleEvents()
{
	switch (currentEvent->type)
	{
	default:
		break;
	case SDL_KEYDOWN:
		InputKeyBoardHolder.insert(std::pair<int,bool>(currentEvent->key.keysym.scancode,true));
		break;
	case SDL_KEYUP:
		InputKeyBoardHolder.insert(std::pair<int, bool>(currentEvent->key.keysym.scancode, true));
		break;
	}
}


