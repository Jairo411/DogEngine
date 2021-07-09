#ifndef Game_H
#define Game_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <thread>
#include "AI/AI.h"
#include "../../Server/Server.h"
#include "../TextureManager/TextureManager.h"
#include "../Window/Window.h"
#include "../Input/Input.h"
#include "../Timer/Timer.h"
#include "../Math/Converter.h"
#include "Scenes/SceneManager.h"
#include "Scenes/GameScenes/Scene0.h"
#include "../GameObjects/Map/Map.h"
#include "../GameObjects/Map/TileSet/Tiles.h"
#include "../GameObjects/GameObject.h"
#include "../GameObjects/Player.h"
#include "../GameObjects/Skeleton.h"
#include "../GameObjects/Map/Map.h"
#include "EngineSerializer.h"

class AIManager;
class EngineSerializer;
class Game{
public:
	Game();
	~Game();
	void init(const char* title, int posx, int posy, int widith, int height,bool fullscreen);
	void GameLoop();
	void HandleEvents();
	void OnUpdate(float deltaTime_);
	void handleCollisions();
	void OnRender();
	void clean();
	static bool	setIsRunning(bool tempBool_);
	static SDL_Renderer *renderer;
	static Timer *timer;
	static Window* actualWindow;
	static AIManager* AI_Manager;
	static EngineSerializer* engineSerializer;
private:
	int cnt=0;
	const int FPS = 120;
	static bool isRunning;
	SceneManager* sceneManager;

};

#endif // !Game_H
