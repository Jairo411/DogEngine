#ifndef SCENE0_H
#define SCENE0_H
#include"../Scene.h"
#include "../../../GameObjects/Rogue.h"
#include "../../../GameObjects/Skeleton.h"
#include "../../../GameObjects/OpenGLTestGameObj.h"
#include "../../../GameObjects/Map/Map.h"
class Scene0: public Scene
{
public:
	Scene0();
	~Scene0();
	void OnCreate() override;
	void OnDestroy() override;
	void OnActivate() override;
	void OnDeactivate() override;
	void HandleEvents() override;
	void HandleCollison() override;
	void Update(float deltaTime_) override;
	void Render() override;
};
#endif //SCENE0
