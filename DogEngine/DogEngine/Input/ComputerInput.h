#ifndef COMPUTERINPUT_H
#define COMPUTERINPUT_H
#include "../EventSystem/Event.h"
#include "../DogEngineDefinitions.h"
#include "Controller.h"
class DogEngine;
enum class KEYBOARD_MAPPINGS
{
	NONE = false,
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
enum class MOUSEMAPPINGS
{
	NONE = false,
	LEFTCLICK,
	RIGHTCLICK,
	MIDDLECLICK,
	MOUSEMOVED,
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
	std::map<KEYBOARD_MAPPINGS, bool> inputKeyBoardHolder;
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
	std::map<MOUSEMAPPINGS, inputVals> GetInput();
private:
	float mouseX, mouseY;
	float wheel;
	bool click;
	std::map<MOUSEMAPPINGS, inputVals> inputMouseHolder;
};

#endif // !COMPUTERINPUT_H
