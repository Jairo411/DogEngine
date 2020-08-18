#ifndef KEYINPUT_H
#define KEYINPUT_H
#include <map>
class SDL;
class Input
{
public:
	virtual ~Input();
	virtual bool keyBoardInput(int key) = 0;
	virtual bool mouseInput(int key) = 0;
	virtual bool controllerInput(int key) = 0;
	 bool keyPressed(int is_Pressed,int keycode);
	 std::map<int, bool>*InputHolder;
};
#endif // !KEYINPUT_H
