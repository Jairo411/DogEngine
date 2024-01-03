#include "Event.h"

EventListener::~EventListener()
{
	eventInfo = nullptr;	
	delete eventInfo;
}

void EventListener::SetEvent(EventInfo* eInfo_)
{
	eventInfo = eInfo_;
}

//MouseInput::MouseInput() : mouseX(0), mouseY(0), click(false), wheel(0.0f)
//{
//}
//
//MouseInput::~MouseInput()
//{
//}
//
//void MouseInput::OnCreate()
//{
//}
//
//void MouseInput::OnDestroy()
//{
//
//}



//int MouseInput::GetWheel()
//{
//	return wheel;
//}
//
//std::map<MOUSEMAPPINGS, inputVals> MouseInput::GetInput()
//{
//	return inputMouseHolder;
//}
//
//
//void MouseInput::HandleEvents()
//{
//	int buttons = SDL_GetMouseState((int*)&mouseX, (int*)&mouseY);
//	switch (eventInfo->event_->type)
//	{
//	default:
//		break;
//		
//	case SDL_MOUSEBUTTONUP: 
//		eventInfo->handled = true;
//		break;
//	case SDL_MOUSEBUTTONDOWN:  
//		eventInfo->handled = true;
//		break;
//	case SDL_MOUSEWHEEL: 
//		eventInfo->handled = true;
//		break;
//	}
//}

//KeyBoardInput::KeyBoardInput()
//{
//
//}
//
//KeyBoardInput::~KeyBoardInput()
//{
//
//}
//
//void KeyBoardInput::OnCreate()
//{
//}
//
//void KeyBoardInput::OnDestroy()
//{
//}
//
//
//
//void KeyBoardInput::HandleEvents()
//{
//	switch (eventInfo->event_->type)
//	{
//	default:
//		break;
//	case SDL_KEYDOWN:
//		eventInfo->handled = true;
//		std::cout << "Keyboard working" << std::endl;
//		break;
//	case SDL_KEYUP:
//		eventInfo->handled = true;
//		break;
//	}
//}
//
//std::map<KEYBOARD_MAPPINGS, bool> KeyBoardInput::GetInput()
//{
//	return inputKeyBoardHolder;
//}
//
//
//Controller::Controller() : click(false) , L_Analog(0.0f) , R_Analog(0.0f)
//{
//}
//
//Controller::~Controller()
//{
//
//}
//
//void Controller::OnCreate()
//{
//}
//
//void Controller::HandleEvents()
//{
//	int totalJoySticks;
//	switch (eventInfo->event_->type)
//	{
//	case SDL_CONTROLLERAXISMOTION:
//		eventInfo->handled = true;
//		std::cout << "Analog moved" << std::endl;
//		break;
//	case SDL_CONTROLLERBUTTONDOWN:
//		eventInfo->handled = true;
//		std::cout << "button pressed" << std::endl;
//		break;
//	case SDL_CONTROLLERBUTTONUP:
//		eventInfo->handled = true;
//		std::cout << "button released" << std::endl;
//		break;
//	case SDL_CONTROLLERDEVICEADDED:
//		eventInfo->handled = true;
//		std::cout << "controller added" << std::endl;
//		break;
//	case SDL_CONTROLLERDEVICEREMOVED:
//		eventInfo->handled = true;
//		std::cout << "controller removed" << std::endl;
//		break;
//	default:
//		break;
//	}
//}
//
//void Controller::OnDestroy()
//{
//}