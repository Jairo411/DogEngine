#ifndef ENGINESERIALIZER
#define ENGINESERIALIZER
#include <fstream>
#include <filesystem>
#include <assert.h>
#include "../DogEngineDefinitions.h"
#include "../PugiXML/pugixml.hpp"
#include<sys/stat.h>
#include<sys/types.h>
#include <iostream>
#include <list>
#include <map>
#include <stdlib.h>
#include <queue>
#include <algorithm>
#include "DirectoryHandler.h"

/*
* 
*/

class GameObject;
class Scene;
	class Serializer
	{
	public:
		Serializer(Serializer& other) = delete;
		Serializer(const Serializer&) = delete;
		Serializer& operator =(Serializer& other) = delete;
		Serializer& operator=(const Serializer&) = delete;
		static Serializer* GetInstance();
		//PURE WRITE FUNCTIONS
		//Serializes GameObject
		void AddGameObject(GameObject* OBJ_); //Write function in scene
		void AddGameObject(int ID_); //Write function in serializer
		//On Engine Initialization I will assign already written IDs to current engine game Objects
		void AssignID(std::list<GameObject*> OBJ_List);
		void CreateID(GameObject* OBJ_);
		//Serializes Animations of GameObject
		void AddAnimationState(GameObject* OBJ_, const char* imageSrc_);//Write function //Animations will be stored in there respective gameObjectDataXML sheet. With there associated tags. 
		void RemoveAnimation(std::string tagID_, const char* imageSrc_);//Write function 
		//Creates a Scene 
		void CreateScene(int currentScene_, const char* sceneName_);// Write function 
		//Serializes Scene
		void SaveScene(int currentScene_, Scene& Scenedata_); //Write function //The Scenedata will push out how many gameObjects are in a scene and there ID's nothing more nothing less
		//Remove Scene
		void RemoveScene(const char* sceneName); //Write function
		//PURE READ FUNCTIONS
		void DeserializeAnimations(); //<-- Deserialzer should return a string
		void DeserializeScenes(); //<--Deserializer should return a string 
		//HELPER FUNCTIONS 
		int GenerateRandomNumber(); // Generates random number, that will later be used as ID
		pugi::xml_document* DefaultSerialized(std::string tag_); //Write Function
		bool isChildNodeExist(const char* nodeName_); //Read Function
		bool SceneExist(int SceneIndex_, const char* SceneName_);//Read Function
		bool GameObjectExist(int ID_); // Read Function
		bool loadFile(const char* fileDirectory_); //Read function
		void Update(); //this will update as fast as possible
	private:
		Serializer();
		~Serializer();

		pugi::xml_document* CurrentDoc;
		pugi::xml_parse_result result;
		std::list<pugi::xml_document*> document_list;
		std::vector<int> gameObjectIDs;
		std::string cwd; //Current working directory 
		static Serializer* instance;
	};
#endif // !ANIMATORSERIALIZER