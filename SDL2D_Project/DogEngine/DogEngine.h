#ifndef DOGENGINE_H
#define DOGENGINE_H
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <thread>
#include <functional>
#include "DogEngineDefinitions.h"
#include "../Renderer/Renderer.h"
#include "../../Server/Server.h"
#include "../Window/Window.h"
#include "../Window/GUI.h"
#include "../EventSystem/Event.h"
#include "../Timer/Timer.h"
#include "../Math/Converter.h"
#include "Scenes/SceneManager.h"
#include "../Thread/ThreadManager.h"
#include "../Audio/AudioManager.h"
#include "../EventSystem/EventManager.h"
#include "../TextureManager/TextureManager.h"
#include "ObjectManager.h"
#include "../FileInput_OutPut/FileDirectoryHandler.h"
#include "ResourceAllocator.h"
#include "EngineSerializer.h"
#include "../Input/ComputerInput.h"
/*
* 2022/8/19 
*  This is where the dog engine lives....
*/
class Scene0;
class Scene1;
class AIManager;
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
	static ObjectManager* gameObjectManager; // Engine functionality
	static EventManager* eventManager; //Engine functionality
	static bool initialized;
	GUI* engineGUI;
	SDL_Event* event_;
private:
	DogEngine();
	//Helper functions 
	void SetupSystems();
	MouseInput* mouseInput;
	KeyBoardInput* keyBoardInput;
	static DogEngine* instance;
	static bool isRunning;	
	int currentRenderFlag = NULL;
	int passRenderFlag = NULL;
	std::vector<std::thread> threadContainer;
};

#endif // !DOGENGINE_H
