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
#include "../Input/InputManager.h"
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


/*
* 2022/8/19 
*  This is where the dog engine lives....
*/
class DogEngine : public ThreadAble {
public:

	~DogEngine();

	static DogEngine* GetInstance();
	/// <summary>
	/// Start the DogEngine Application
	/// </summary>
	void OnCreate(const char* title, int posx, int posy, int widith, int height,bool fullscreen);
	void OnDestroy();
	void GameLoop();
	void HandleEvents();
	void Update(float deltaTime_);
	void handleCollisions();
	void CheckRenderer();
	void Render();
	void clean();
	virtual void RunInstructions();
	static bool	setIsRunning(bool tempBool_);
	static Window* window; //Engine Functionality 
	static Timer* timer; //Engine Functitonality 
	static RendererManager* rendererManager; //Engine functionality
	static TextureManager* textureManager;// Engine functionality
	static AIManager* AI_Manager; // this is a component not a engineFunctionality, should be removed 
	static Serializer* engineSerializer; //Engine functionality 
	static SceneManager* sceneManager; //Engine functionality 
	static ThreadManager* threadManager; //Engine functionality
	static AudioManager* audioManager; //Engine functionality
	static ObjectManager* GameObjectManager; // Engine functionality
	static InputManager* inputManager; //Engine functionality
	static bool initialized;
	GUI* engineGUI;
	SDL_Event* event_;
private:
	DogEngine();
	static DogEngine* instance;
	static bool isRunning;	
	int currentRenderFlag = NULL;
	int passRenderFlag = NULL;
	std::vector<std::thread> threadContainer;
};

#endif // !DOGENGINE_H
