#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H
#include "../../Components/Component.h"
#include "../../GameObjects/GameObject.h"
/*Player Input Logic will be added here*/

class MouseInput;
class KeyBoardInput;
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
	MouseInput* mouseInput;
	KeyBoardInput* keyBoardInput;
};
#endif // !PLAYERCONTROLLER_H
