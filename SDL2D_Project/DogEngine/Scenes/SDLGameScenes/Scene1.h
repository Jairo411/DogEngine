#ifndef SCENE1_H
#define SCENE1_H
#include"../Scene.h"
class DogEngine;
class Scene1 : public Scene
{
public:
	Scene1();
	~Scene1();
	void OnCreate() final;
	void OnDestroy() final;
	void OnActivate() final;
	void OnDeactivate() final;
	void HandleEvents() final;
	void HandleCollison() final;
	void Update(float deltatime_) final;
	void Render() final;
};

#endif