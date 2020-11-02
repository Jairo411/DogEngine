#ifndef Game_H
#define Game_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "../TextureManager/TextureManager.h"
#include "../Window/Window.h"
#include "../Input/Input.h"
#include "../Timer/Timer.h"
#include "Scenes/SceneManager.h"
#include "Scenes/GameScenes/Scene0.h"
#include "../GameObjects/Map/Map.h"
#include "../GameObjects/Map/TileSet/Tiles.h"
#include "../GameObjects/GameObject.h"
#include "../GameObjects/Player.h"
#include "../GameObjects/Enemy.h"
#include "../GameObjects/Player.h"
#include "../GameObjects/Map/Map.h"

class Game{
public:
	Game();
	void init(const char* title, int posx, int posy, int widith, int height,bool fullscreen);
	void GameLoop();
	void HandleEvents();
	void OnUpdate(float deltaTime_);
	void handleCollisions();
	void OnRender();
	void clean();
	static SDL_Renderer *renderer;
	static Timer *timer;
	static Window* actualWindow;
	static bool	setIsRunning(bool tempBool_);
	~Game();
private:
	int cnt=0;
	const int FPS = 120;
	static bool isRunning;
	SDL_Window* window;
	SceneManager* sceneManager;
};

#endif // !Game_H
