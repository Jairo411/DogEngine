#ifndef KEYINPUT_H
#define KEYINPUT_H
#include <map>
#include <iostream>
#include "../Physics/Collider.h"
#include "../Math/Vec2.h"
class SDL;
class Window;
/* This is Input class is capable of an abstract class,
but does have actual functionallity. Really its more of an interface if anything.
*/
/*2021-07-09
 My first implementation of the Input class is kinda wonky, I believe it would be better if I completely re-work this.*/
class Input
{
public:
	virtual ~Input();
	virtual bool KeyBoardInput(int key) = 0;
	virtual bool MouseInput(int key) = 0;
	virtual bool ControllerInput(int key) = 0;

	bool keyPressed(int is_Pressed,int keycode);
	bool MousePressed(int is_Pressed, int keycode);
	std::map<int, bool> InputKeyBoardHolder;
	std::map<int, bool> InputMouseHolder;

	static RectCollider* mouseClick;
	void setWindow(Window* windowptr_);
	void setMiddlePoint(Vec2 tempV);
	Vec2 getMiddlePoint();
private:
	static int mouseX, mouseY;
	static bool CreateCollider(bool state_);
	Vec2 middlepoint;
	Window* window;
	

};
#endif // !KEYINPUT_H*/
