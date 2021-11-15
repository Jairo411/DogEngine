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
/*2021-11-14
Now Inputs are compeletly abstracted like before but with more concert defientions, to seperate certain inputs that aren't always going to be working together. i.e keyboard and mouse inputs aren't always going to be working 
with each other. 
Im totally copying Unity in the sense that are arbitrary defientions that I define that I can map for mutiple thing./// this actually sounds like alot of work
*/
class Input
{
public:
	virtual ~Input();
	///NEW
	virtual void Update() =0;
   	///OLD
	static RectCollider* mouseClick;
	void setWindow(Window* windowptr_);
	void setMiddlePoint(Vec2 tempV);
	Vec2 getMiddlePoint();
protected:
	SDL_Event* GetEvent();
private:
	static int mouseX, mouseY;
	static bool CreateCollider(bool state_);
	SDL_Event* currentEvent;
	///Remove middlePoint
	Vec2 middlepoint;
	Window* window;
};

//KeyBoard should always be listening, to accept mutiple inputs 
class KeyBoardInput : Input
{
	///Constructor & Destructor 
public:
	KeyBoardInput();
	~KeyBoardInput();
	
	virtual void Update() final;
private:
	std::map<int, bool> InputKeyBoardHolder;
};

class MouseInput : Input
{
public:
	///Constructor & Destructor 
	MouseInput();
	~MouseInput();
	virtual void Update() final;
private:
	int mouseX, mouseY;
	std::map<int, bool> InputMouseHolder;
};


#endif // !KEYINPUT_H*/
