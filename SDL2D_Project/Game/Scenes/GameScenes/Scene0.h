#ifndef SCENE0_H
#define SCENE0_H

#include"../../Game.h"
#include"../Scene.h"
#include "../../../Window/Window.h"

using namespace std;

class Scene0: public Scene
{
public:
	Scene0();
	void OnCreate() override;
	void OnDestroy() override;
	void HandleEvents() override;
	void HandleCollison() override;
	void OnUpdate(float deltaTime_) override;
	void OnRender() override;
private: 
	bool isRunning;
};
#endif //SCENE0
