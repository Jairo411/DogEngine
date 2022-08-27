#ifndef EVENTINPUT_H
#define EVENTINPUT_H
#include <map>
#include <iostream>
#include <vector>
#include <utility>
#include "../Physics/Collider.h"
#include "../Math/Vec2.h"
#include <SDL_events.h>
/*
* 2022/8/19 
*  Abstract EventListener class. 
*  with concrete input classes
*/
enum class EVENTPRIORITY
{
	NONE = 0,
	LOW,
	MEDIUM,
	HIGH,
};
struct EventInfo
{
	SDL_Event* event_ = nullptr;
	EVENTPRIORITY priority = EVENTPRIORITY::NONE;
	bool handled = false;
};

class EventListener
{
public:
	virtual ~EventListener();
	virtual void OnCreate() = 0;
	virtual void OnDestroy() = 0;
	virtual void HandleEvents() =0;
	virtual void SetEvent(EventInfo* eInfo_);
protected:
	EventInfo* eventInfo =nullptr;
};


struct ListenerInfo
{
	int order = 0;
	int index = 0;
	EventListener* listener = nullptr;
};



//Remove this once you're done testing input 
class KeyBoardInput : public EventListener
{
public:
	KeyBoardInput();
	~KeyBoardInput();
	virtual void OnCreate() final;
	virtual void OnDestroy() final;
	virtual void HandleEvents() final;
};

//Remove this once you're done testing input 
class MouseInput : public EventListener
{
public:
	MouseInput();
	~MouseInput();
	virtual void OnCreate() final;
	virtual void OnDestroy() final;
	virtual void HandleEvents() final;
	int GetWheel();
private:
	float mouseX, mouseY;
	float wheel;
	bool click;
	
};
//Remove this once you're done testing input 
class Controller : public EventListener
{
public:
	Controller();
	~Controller();
	virtual void OnCreate() final;
	virtual void OnDestroy() final;
	virtual void HandleEvents() final;
private:
	bool click;
	float L_Analog;
	float R_Analog;
};


#endif // !KEYINPUT_H*/
