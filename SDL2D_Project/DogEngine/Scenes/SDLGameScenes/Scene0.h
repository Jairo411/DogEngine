#ifndef SCENE0_H
#define SCENE0_H
#include"../Scene.h"
class DogEngine;
class Scene0: public Scene
{
public:
	Scene0();
	~Scene0();
	void OnCreate() final;
	void OnDestroy() final;
	void OnActivate() final;
	void OnDeactivate() final;
	void HandleEvents() final;
	void HandleCollison() final;
	void Update(float deltaTime_) final;
	void Render() final;
};
#endif //SCENE0
