#ifndef DOGENGINE_H
#define DOGENGINE_H
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <thread>
#include <functional>
#include "DogEngineDefinitions.h"
#include "Renderer/Renderer.h"
#include "Window/Window.h"
#include "Window/GUI.h"
#include "EventSystem/EventManager.h"
#include "Timer/Timer.h"
#include "Math/Converter.h"
#include "SceneManager/SceneManager.h"
#include "Thread/ThreadManager.h"
#include "Audio/AudioManager.h"
#include "EventSystem/EventManager.h"
#include "TextureManager/TextureManager.h"
#include "ObjectManager/ObjectManager.h"
#include "FileSystem/DirectoryHandler.h"
#include "FileSystem/EngineSerializer.h"
#include "ResourceManager/ResourceAllocator.h""
#include "Input/ComputerInput.h"
#include "Input//Controller.h"
/*
* 2022/8/19 
*  This is where the dog engine lives....
*/
class Scene0;
class Scene1;
class Scene2;
class DebugScene;
class AIManager; //remove this 
namespace DGEngine::core {
	class DogEngine : public ThreadAble {
	public:
		~DogEngine();
		static DogEngine* GetInstance();
		/// <summary>
		/// Start the DogEngine Application
		/// </summary>
		void OnCreate(const char* title, int posx, int posy, int widith, int height, bool fullscreen);
		void OnDestroy();
		void GameLoop();
		void HandleEvents();
		void Update(float deltaTime_);
		void handleCollisions();
		void CheckRenderer();
		void Render();
		void clean();
		virtual void RunInstructions(); //Threading functionality 07-11-2023 needs to be reviewed 
		static bool	setIsRunning(bool tempBool_);
		static Window* window; //Engine Functionality 
		static Timer* timer; //Engine Functitonality 
		static RendererManager* rendererManager; //Engine functionality
		static TextureManager* textureManager;// Engine functionality
		//static AIManager* AI_Manager; // this is a component not a engineFunctionality, should be removed 
		static Serializer* engineSerializer; //Engine functionality 
		static SceneManager* sceneManager; //Engine functionality 
		static ThreadManager* threadManager; //Engine functionality
		static AudioManager* audioManager; //Engine functionality
		static ObjectManager* gameObjectManager; // Engine functionality
		static EventManager* eventManager; //Engine functionality
	private:
		DogEngine();
		//Helper functions 
		void IntializeEngineSystems();
		/// <summary>
		/// This function, contains specific dogEngine setting already chosen to help with development speed as a tinkering ground.
		/// </summary>
		void CurrentSetUp();
		static bool isRunning; // should remove static keyword
		static bool initialized; // should remove static keyword
		int currentRenderFlag = NULL;
		int passRenderFlag = NULL;
		GUI* engineGUI;
		SDL_Event* event_;
		static DogEngine* instance;
		std::vector<std::thread> threadContainer;
	};
}

/*
* 
void doSomething()
{

};
*/

#endif // !DOGENGINE_H