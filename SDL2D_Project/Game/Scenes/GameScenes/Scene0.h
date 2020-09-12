#ifndef SCENE0_H
#define SCENE0_H

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
	void OnUpdate() override;
	void OnRender() override;
	//static SDL_Renderer* renderer;
private: 
	int cnt = 0;
	bool isRunning;
	//SDL_Rect srcR, dstR;
};
#endif //SCENE0
