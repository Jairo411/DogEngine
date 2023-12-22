#ifndef DEBUGSCENE_H
#define DEBUGSCENE_H
#include "../Scene.h"
class DebugScene : public Scene
{
public:
	DebugScene();
	~DebugScene();

	 virtual void OnCreate();
	 virtual void OnDestroy();
	 virtual void OnActivate();
	 virtual void OnDeactivate();
	 virtual void HandleEvents() override;
	 virtual void HandleCollison() override;
	 virtual void Update(float deltaTime_);
	 virtual void Render(); 
	 int currentScene;
};
#endif
