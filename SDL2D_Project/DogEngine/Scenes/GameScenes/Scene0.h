#ifndef SCENE0_H
#define SCENE0_H

#include"../Scene.h"
#include"../../DogEngine.h"

using namespace std;
/*2021-07-09 
	This code here is fine*/
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
	void FixedUpdate(float deltaTime_) override;
	void Render() override;
};
#endif //SCENE0
