#ifndef SCENE2_H
#define SCENE2_H
#include "../Scene.h"
class DogEngine;
class Scene2
{
public:
	virtual void OnCreate() final;
	virtual void OnDestroy() final;
	virtual void OnActivate() final;
	virtual void HandleEvents() final;
	virtual void HandleCollison() final;
	virtual void Update(float deltaTime_) final;
	virtual void Render() final;
};
#endif

