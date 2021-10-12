#ifndef Game_H
#define Game_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <thread>
#include "AI/AI.h"
#include "../Renderer/Renderer.h"
#include "../../Server/Server.h"
#include "../Graphics/TextureManager.h"
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

/*2021-07-09 
	Currently looking at this, don't really see a problem besides the FPS Issues that I need to fix,
	probably not coming on this side of the engine but yah, */
class AIManager;
class Serializer;
class Game{
public:
	Game();
	~Game();
	void init(const char* title, int posx, int posy, int widith, int height,bool fullscreen);
	// new Code
	void OnDestroy();
	void GameLoop();
	void HandleEvents();
	void Update(float deltaTime_);
	//new Code
	void FixedUpdate(float superDeltaTime_);
	void handleCollisions();
	void Render();
	void clean();
	static bool	setIsRunning(bool tempBool_);
	static Timer* timer; //EngineFunctitonality 
	static Window* window; //EngineFunctionality 
	static RendererManager* renderer; //EngineFunctionality
	static AIManager* AI_Manager; // this is a component not a engineFunctionality, should be removed 
	static Serializer* EngineSerializer; //engine functionality 
	SceneManager* sceneManager; //Engine functionality 
private:
	static bool isRunning;
	SDL_Renderer* rend;

};

#endif // !Game_H
