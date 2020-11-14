#ifndef SCENE0_H
#define SCENE0_H

#include"../Scene.h"
#include"../../Game.h"

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

};
#endif //SCENE0
