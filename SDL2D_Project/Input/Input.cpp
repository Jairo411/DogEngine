#include <SDL.h>
#include "Input.h"
#include "../Window/Window.h"

RectCollider* Input::mouseClick = new RectCollider();
int Input::mouseX = 0, Input::mouseY = 0;

Input::~Input()
{
}

SDL_Event* Input::GetEvent()
{
	SDL_PollEvent(currentEvent);
	return currentEvent;
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
	InputMouseHolder = std::map<int, bool>();
}

MouseInput::~MouseInput()
{
	InputMouseHolder.empty();
}

void MouseInput::Update()
{
	switch (GetEvent()->type)
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



void KeyBoardInput::Update()
{
	SDL_Event* tempEvent = GetEvent();
	switch (tempEvent->type)
	{
	default:
		break;
	case SDL_KEYDOWN:
		InputKeyBoardHolder.insert(std::pair<int,bool>(tempEvent->key.keysym.scancode,true));
		break;
	case SDL_KEYUP:
		InputKeyBoardHolder.insert(std::pair<int, bool>(tempEvent->key.keysym.scancode, true));
		break;
	}
}


