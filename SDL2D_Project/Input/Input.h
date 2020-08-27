#ifndef KEYINPUT_H
#define KEYINPUT_H
#include <map>
#include<iostream>
#include "../Physics/Collider.h"
class SDL;
class Input
{
public:
	virtual ~Input();
	virtual bool keyBoardInput(int key) = 0;
	virtual bool mouseInput(int key) = 0;
	virtual bool controllerInput(int key) = 0;
	bool keyPressed(int is_Pressed,int keycode);
	bool MousePressed(int is_Pressed, int keycode);
	std::map<int, bool> InputKeyBoardHolder;
	std::map<int, bool> InputMouseHolder;

private:
	int mouseX, mouseY;
	Collider* mouseClick;
};
#endif // !KEYINPUT_H
