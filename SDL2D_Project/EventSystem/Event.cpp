#include <SDL.h>
#include "Event.h"
#include "../Window/Window.h"

EventListener::~EventListener()
{
	currentEvent = nullptr;	
	delete currentEvent;
}

void EventListener::SetEvent(SDL_Event* e_)
{
	currentEvent = e_;
}

MouseInput::MouseInput() : mouseX(0), mouseY(0), click(false), wheel(0.0f)
{
}

MouseInput::~MouseInput()
{
	inputMouseHolder.empty();
}

void MouseInput::OnCreate()
{
}

void MouseInput::OnDestroy()
{

}

std::map<MOUSEMAPPINGS, std::pair<bool, float>> MouseInput::GetInput()
{
	return inputMouseHolder;
}



int MouseInput::GetWheel()
{
	return wheel;
}


void MouseInput::HandleEvents()
{
	int buttons = SDL_GetMouseState((int*)&mouseX, (int*)&mouseY);
	switch (currentEvent->type)
	{
	default:
		break;
		
	case SDL_MOUSEBUTTONUP: 
		break;
	case SDL_MOUSEBUTTONDOWN:  
		break;
	case SDL_MOUSEWHEEL: 
		wheel = currentEvent->wheel.y;
		break;
	}
}

KeyBoardInput::KeyBoardInput()
{

}

KeyBoardInput::~KeyBoardInput()
{
	inputKeyBoardHolder.empty();
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
		
		break;
	case SDL_KEYUP:
	
		break;
	}
}

std::map<KEYBOARD_MAPPINGS, bool> KeyBoardInput::GetInput()
{
	return inputKeyBoardHolder;
}

PlayStation4Input::PlayStation4Input() : click(false) , L_Analog(0.0f) , R_Analog(0.0f), controllerInput(std::map<PLAYSTATION_MAPPINGS, std::pair<bool, float>>())
{
}

PlayStation4Input::~PlayStation4Input()
{
	controllerInput.empty();
}

std::map<PLAYSTATION_MAPPINGS, std::pair<bool, float>> PlayStation4Input::GetInput()
{
	return controllerInput;
}

void PlayStation4Input::OnCreate()
{
}

void PlayStation4Input::HandleEvents()
{
	switch (currentEvent->type)
	{
	case SDL_CONTROLLERAXISMOTION:
	
		break;
	case SDL_CONTROLLERBUTTONDOWN:

		break;
	case SDL_CONTROLLERBUTTONUP:

		break;
	case SDL_CONTROLLERDEVICEADDED:

		break;
	case SDL_CONTROLLERDEVICEREMOVED:

		break;
	default:
		break;
	}
}

void PlayStation4Input::OnDestroy()
{
}
