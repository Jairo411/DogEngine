#ifndef EVENTINPUT_H
#define EVENTINPUT_H
#include <map>
#include <iostream>
#include <vector>
#include <utility>
#include "../Physics/Collider.h"
#include "../Math/Vec2.h"
class SDL;
class Window;
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

enum class KEYBOARD_MAPPINGS
{
	NONE=false,
	W,
	D,
	S,
	A,
	SPACE,
	TOPDIR,
	RIGHTDIR,
	BOTTOMDIR,
	LEFTDIR,
};


class KeyBoardInput : public EventListener
{
public:
	KeyBoardInput();
	~KeyBoardInput();
	virtual void OnCreate() final;
	virtual void OnDestroy() final;
	virtual void HandleEvents() final;
	std::map<KEYBOARD_MAPPINGS, bool> GetInput();
private:
	std::map<KEYBOARD_MAPPINGS , bool> inputKeyBoardHolder;
};


enum class MOUSEMAPPINGS
{
	NONE = false,
	LEFTCLICK,
	RIGHTCLICK,
	MIDDLECLICK,
	MOUSEMOVED,
};


class MouseInput : public EventListener
{
public:
	MouseInput();
	~MouseInput();
	virtual void OnCreate() final;
	virtual void OnDestroy() final;
	virtual void HandleEvents() final;
	int GetWheel();
	std::map<MOUSEMAPPINGS, std::pair<bool, float>> GetInput();
private:
	float mouseX, mouseY;
	float wheel;
	bool click;
	std::map<MOUSEMAPPINGS, std::pair<bool,float>> inputMouseHolder;
};

enum class PLAYSTATION_MAPPINGS
{
	NONE=false,
	T_BUTTON,
	C_BUTTON,
	X_BUTTON,
	S_BUTTON,
	OPTIONS,
	SHARE,
	R1,
	R2,
	L1,
	L2,
	TOPDIR,
	RIGHTDIR,
	BOTTOMDIR,
	LEFTDIR,
	RANALOG,
	LEFTANALOG,
};

class Controller : public EventListener
{
public:
	Controller();
	~Controller();
	virtual void OnCreate() final;
	virtual void OnDestroy() final;
	virtual void HandleEvents() final;
	std::map<PLAYSTATION_MAPPINGS, std::pair<bool, float>> GetInput();
private:
	bool click;
	float L_Analog;
	float R_Analog;
	std::map<PLAYSTATION_MAPPINGS, std::pair<bool,float>> controllerInput;
};


#endif // !KEYINPUT_H*/
