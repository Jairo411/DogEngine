#ifndef DEBUGSCENE_H
#define DEBUGSCENE_H
#include "../../../DogEngine/SceneManager/Scene.h"
#include "../../GameObjects/Spinningplanet.h"
class DogEngine;
class DebugScene : public Scene
{
public:
	DebugScene();
	~DebugScene();

	 void OnCreate() final;
	 void OnDestroy() final;
	 virtual void OnActivate() final;
	 virtual void OnDeactivate() final;
	 virtual void HandleEvents() final;
	 virtual void HandleCollison() final;
	 virtual void Update(float deltaTime_) final;
	 virtual void Render() final; 
private:
	SDL_Texture* stillplanet;
	SpinningPlanet planet0;
};
#endif
