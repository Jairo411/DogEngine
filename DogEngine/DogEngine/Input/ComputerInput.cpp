#include "ComputerInput.h"
#include "../DogEngine.h"
KeyBoardInput::KeyBoardInput()
{

};

KeyBoardInput::~KeyBoardInput()
{

}

void KeyBoardInput::OnCreate()
{

};

void KeyBoardInput::OnDestroy()
{

}

void KeyBoardInput::HandleEvents()
{

}

std::map<KEYBOARD_MAPPINGS, bool> KeyBoardInput::GetInput()
{

	return std::map<KEYBOARD_MAPPINGS, bool>();
}

MouseInput::MouseInput()
{

}

MouseInput::~MouseInput()
{

}

void MouseInput::OnCreate()
{

}

void MouseInput::OnDestroy()
{

}

void MouseInput::HandleEvents()
{

}

int MouseInput::GetWheel()
{
	return 0;
}

std::map<MOUSEMAPPINGS, inputVals> MouseInput::GetInput()
{
	return std::map<MOUSEMAPPINGS, inputVals>();
}