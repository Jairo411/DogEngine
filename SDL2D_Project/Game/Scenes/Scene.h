#ifndef SCENE_HEADER
#define SCENE_HEADER
#include "../../Window/Window.h"
class Scene
{
public:
	virtual void OnCreate() = 0;
	virtual void OnDestroy() = 0;
	virtual void OnActivate() {};
	virtual void OnDeactivate() {};
	virtual void HandleEvents() {};
	virtual void HandleCollison() {};
	virtual void OnUpdate(){};
	virtual void OnRender() {};
};
#endif //SCENE_HEADER