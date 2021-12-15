#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H
#include "Input.h"
#include "../GameObjects/Component/Component.h"
class GameObject;
/*Player Input Logic will be added here*/
class PlayerController : Component 
{
public:
	PlayerController();
	~PlayerController();
	virtual void OnCreate(BaseObj* parent_);
	virtual	void OnDestroy();
	virtual void Update();
	virtual void FixedUpdate();
	virtual void Render();
private:
	MouseInput mouseInput;
	KeyBoardInput keyBoardInput;
};
#endif // !PLAYERCONTROLLER_H
