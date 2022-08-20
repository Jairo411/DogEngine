#include <SDL.h>
#include "Input.h"
#include "../Window/Window.h"

Input::~Input()
{
	currentEvent = nullptr;	
	delete currentEvent;
}

void Input::SetEvent(SDL_Event* e_)
{
	currentEvent = e_;
}


MouseInput::MouseInput()
{
}

MouseInput::~MouseInput()
{
	InputMouseHolder.empty();
}

void MouseInput::OnCreate()
{
	mouseX = 0;
	mouseY = 0;
	buttons = 0;
	wheel = 0;
	InputMouseHolder = std::map<int, bool>();
}

void MouseInput::OnDestroy()
{

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
		std::cout << "Mouse button was pressed" << std::endl;
		break;
	case SDL_MOUSEBUTTONDOWN:  //Should be used when holding down the button
		InputMouseHolder.insert(std::pair<int, bool>());
		std::cout << "Mouse button was pressed" << std::endl;
		break;

	case SDL_MOUSEWHEEL: //Should be used when using the scrolling wheel
		InputMouseHolder.insert(std::pair<int, bool>());
		wheel = currentEvent->wheel.y;
		std::cout << "Mouse button was pressed" << std::endl;
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

void KeyBoardInput::OnCreate()
{
}

void KeyBoardInput::OnDestroy()
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
		std::cout << "KeyBoard button was pressed" << std::endl;
		break;
	case SDL_KEYUP:
		InputKeyBoardHolder.insert(std::pair<int, bool>(currentEvent->key.keysym.scancode, true));
	//	std::cout << "KeyBoard button was pressed" << std::endl;
		break;
	}
}

PlayStation4Input::PlayStation4Input()
{
}

PlayStation4Input::~PlayStation4Input()
{
}

void PlayStation4Input::OnCreate()
{
}

void PlayStation4Input::OnDestroy()
{
}
