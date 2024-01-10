#ifndef EVENTINPUT_H
#define EVENTINPUT_H
#include <map>
#include <iostream>
#include <vector>
#include <utility>
#include <SDL_events.h>
#include "../Math/Vec2.h"
/*
* 2022/8/19 
*  Abstract EventListener class. 
*  with concrete input classes
*/
enum class EVENTPRIORITY
{
	NONE = 0,
	LOW,
	HIGH
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





#endif // !KEYINPUT_H*/
