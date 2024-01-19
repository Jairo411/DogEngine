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
#include "EventSystem/EventManager.h"
#include "Timer/Timer.h"
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
#include "Input/Controller.h"
/*
* 2022/8/19 
*  This is where the dog engine lives....
*/
class Scene0;
class Scene1;
class Scene2;
class DebugScene;
class AIManager; //remove this 
	class DogEngine : public ThreadAble {
	public:
		DogEngine(const DogEngine&) = delete;
		DogEngine(DogEngine& other) = delete;
		DogEngine& operator =(const DogEngine&) = delete;
		DogEngine& operator =(DogEngine&&) = delete;
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
		bool setIsRunning(bool tempBool_);
		virtual void RunInstructions(); //Threading functionality 07-11-2023 needs to be reviewed 
		static Window* window; //Engine Functionality 
		static Timer* timer; //Engine Functionality 
		static RendererManager* rendererManager; //Engine functionality
		static TextureManager* textureManager;// Engine functionality
		static Serializer* engineSerializer; //Engine functionality 
		static SceneManager* sceneManager; //Engine functionality 
		static ThreadManager* threadManager; //Engine functionality
		static AudioManager* audioManager; //Engine functionality
		static ObjectManager* gameObjectManager; // Engine functionality
		static EventManager* eventManager; //Engine functionality
	//	static GUI* dogEngineGUI;
	private:
		DogEngine();
		~DogEngine();
		/// <summary>
		/// Intialize all singleton dogengine Systems
		/// </summary>
		void IntializeEngineSystems();
		/// <summary>
		/// This function, contains specific dogEngine setting already chosen to help with development speed as a tinkering ground.
		/// </summary>
		void SetupInput();
		bool isRunning; 
		bool initialized; //might be the exact same thing as isRunning
		int currentRenderFlag;
		int passRenderFlag;
		static DogEngine* instance;
		SDL_Event* event_;
	};


/*
* 
void doSomething()
{

};
*/

#endif // !DOGENGINE_H
