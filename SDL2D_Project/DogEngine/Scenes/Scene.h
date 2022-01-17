#ifndef SCENE_HEADER
#define SCENE_HEADER
class Scene
{
public:
	virtual void OnCreate() = 0; 
	virtual void OnDestroy() = 0;
	virtual void OnActivate() = 0;
	virtual void OnDeactivate() = 0;
	virtual void HandleEvents() {};
	virtual void HandleCollison() {};
	virtual void Update(float deltaTime_) = 0;
	virtual void FixedUpdate(float deltaTime) = 0;
	virtual void Render() = 0;
	int currentScene;
};
#endif //SCENE_HEADER