#ifndef DOGENGINE_H
#define DOGENGINE_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <thread>
#include <functional>
#include "AI/AI.h"
#include "../Renderer/Renderer.h"
#include "../../Server/Server.h"
#include "../TextureManager/TextureManager.h"
#include "../Window/Window.h"
#include "../Window/GUI.h"
#include "../Input/Input.h"
#include "../Timer/Timer.h"
#include "../Math/Converter.h"
#include "Scenes/SceneManager.h"
#include "Scenes/GameScenes/Scene0.h"
#include "Scenes/GameScenes/Scene1.h"
#include "../GameObjects/Map/Map.h"
#include "../GameObjects/Map/TileSet/Tiles.h"
#include "../GameObjects/GameObject.h"
#include "../GameObjects/Rogue.h"
#include "../GameObjects/Skeleton.h"
#include "../GameObjects/OpenGLTestGameObj.h"
#include "../GameObjects/Map/Map.h"
#include "../Thread/ThreadManager.h"
#include "../Audio/AudioManager.h"
#include "../FileInput_OutPut/FileDirectoryHandler.h"
#include "ObjectManager.h"
#include "ResourceAllocator.h"
#include "EngineSerializer.h"


/*2021-07-09 
	Currently looking at this, don't really see a problem besides the FPS Issues that I need to fix,
	probably not coming on this side of the engine but yah, */
class AIManager;
class Serializer;
class DogEngine : public ThreadAble {
public:
	DogEngine();
	~DogEngine();
	void OnCreate(const char* title, int posx, int posy, int widith, int height,bool fullscreen);
	// new Code
	void OnDestroy();
	void GameLoop();
	void HandleEvents();
	void Update(float deltaTime_);
	//new Code
	void FixedUpdate(float deltaTime_);
	void handleCollisions();
	void Render();
	void clean();
	static bool	setIsRunning(bool tempBool_);
	static Window* window; //Main Engine Component
	static Timer* timer; //Engine Functitonality 
	static RendererManager* rendererManager; //Engine functionality
	static TextureManager* textureManager;// Engine functionality
	static AIManager* AI_Manager; // this is a component not a engineFunctionality, should be removed 
	static Serializer* EngineSerializer; //Engine functionality 
	static SceneManager* sceneManager; //Engine functionality 
	static ThreadManager* threadManager; //Engine functionality
	static AudioManager* audioManager; //Engine functionality
	static ObjectManager* GameObjectManager; // Engine functionality 
	static bool initialized;
	GUI* engineGUI;
	SDL_Event* event_;

	virtual void RunInstructions()
	{
		while (getThreadAssignment()==true)
		{
			Render();
		}
	};
private:
	static bool isRunning;	
	std::vector<std::thread> threadContainer;
};

#endif // !DOGENGINE_H
