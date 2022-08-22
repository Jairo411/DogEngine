#ifndef EVENTINPUT_H
#define EVENTINPUT_H
#include <map>
#include <iostream>
#include <vector>
#include "../Physics/Collider.h"
#include "../Math/Vec2.h"
class SDL;
class Window;
/*
* 2022/8/19 
*  Almost pure abstract Input class , that lets children Input classes to define their own functionality.  
*/
enum class PLAYSTATION_MAPPINGS
{
	T_BUTTON = false,
	C_BUTTON, 
	X_BUTTON, 
	S_BUTTON, 
	OPTIONS, 
	SHARE, 
	R1, 
	R2, 
	L1, 
	L2, 
	TOUCHPAD,
	TOPDIR,
	RIGHTDIR,
	BOTTOMDIR,
	LEFTDIR,
};

enum class KEYBOARD_MAPPINGS
{
	W = false,
	D,
	S,
	A,
	SPACE,
	TOPDIR,
	RIGHTDIR,
	BOTTOMDIR,
	LEFTDIR,
};

enum class MOUSE_MAPPINGS
{
	LEFTCLICK =false,
	RIGHTCLICK,
};

class EventListener
{
public:
	virtual ~EventListener();
	virtual void OnCreate() = 0;
	virtual void OnDestroy() = 0;
	virtual void HandleEvents() =0;
	virtual void SetEvent(SDL_Event* e_);
protected:
	SDL_Event* currentEvent =nullptr;
};
class KeyBoardInput : public EventListener
{
public:
	KeyBoardInput();
	~KeyBoardInput();
	virtual void OnCreate() final;
	virtual void OnDestroy() final;
	virtual void HandleEvents() final;
private:
	std::map<int, bool> InputKeyBoardHolder;
};

class MouseInput : public EventListener
{
public:
	MouseInput();
	~MouseInput();
	virtual void OnCreate() final;
	virtual void OnDestroy() final;
	std::vector<int> getMouse();
	std::vector<int> getButtons();
	int GetWheel();
	virtual void HandleEvents() final;
private:
	int mouseX, mouseY;
	int buttons;
	int wheel;
	std::map<int, bool> InputMouseHolder;
};

class PlayStation4Input : public EventListener
{
public:
	PlayStation4Input();
	~PlayStation4Input();
	virtual void OnCreate() final;
	virtual void OnDestroy() final;
private:

};


#endif // !KEYINPUT_H*/
