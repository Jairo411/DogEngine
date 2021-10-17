#ifndef SCENE_HEADER
#define SCENE_HEADER
class Scene
{
public:
	virtual void OnCreate() = 0; 
	virtual void OnDestroy() = 0;
	virtual void HandleEvents() {};
	virtual void HandleCollison() {};
	virtual void OnUpdate(float deltaTime_) = 0;
	virtual void OnRender() = 0;
	
};
#endif //SCENE_HEADER