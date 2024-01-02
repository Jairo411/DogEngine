#ifndef SCENEMANAGER_HEADER
#define SCENEMANAGER_HEADER
#include <memory>
#include <unordered_map>
#include "Scene.h"
#include "../FileSystem/EngineSerializer.h"
#include "../Thread/ThreadManager.h"
/* 13-07-2023
* Scenemanager class handles scenes, by holding references to them. 
*/
	class SceneManager
	{
	public:

		//Singleton functionality
		SceneManager(const SceneManager&) = delete;
		SceneManager(SceneManager&&) = delete;
		SceneManager& operator =(const SceneManager&) = delete;
		SceneManager& operator =(SceneManager&&) = delete;
		static SceneManager* GetInstance();

		/// <summary>
		/// SceneManager handle events only handles in game scene events and not engine events. There is a bridge 
		/// of communication between the two. They both share input logic. 
		/// </summary>
		void HandleEvents();
		void Update(float deltaTime_);
		void Render();
		/// <summary>
		/// Collision is handled through the Scenemanger which should be a engine type of functionality, but the scale of this engine isn't going 
		/// to be that big, so i'll leave it as is with some ability to plug in more industry standard handle collison functionality. 
		/// </summary>
		void handleCollison();
		/// <summary>
		/// Add Scene to the sceneManager
		/// </summary>
		/// <param name="scene"> a shared pointer reference to a game scene.</param>
		/// <returns>returns ID of lastest added scene.</returns>
		unsigned int Add(std::shared_ptr<Scene> scene);
		/// <summary>
		/// this will take a deserialized string value and create a new scene in prospective to its coording xml information.
		/// </summary>
		/// <returns>0 on success, or -1 on error </returns>
		bool Load();
		//Switch scenes.
		void SwitchTo(unsigned int id);
		//Remove scenes. 
		void Remove(unsigned int id);


	private:
		SceneManager();
		~SceneManager();
		unsigned int insertedSceneID;
		static SceneManager* instance;
		std::unordered_map<unsigned int, std::shared_ptr<Scene>> scenes;
		std::shared_ptr<Scene> curScene;
	};
#endif //SCENEMANAGER_HEADER
