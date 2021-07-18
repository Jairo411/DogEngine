#ifndef ENGINESERIALIZER
#define ENGINESERIALIZER
#include <fstream>
#include <filesystem>
#include <string>
#include "PugiXML/pugixml.hpp"
#include<sys/stat.h>
#include<sys/types.h>
#include <iostream>
#include <list>
#include <map>
#include <vector>
#include<variant>
#include <utility>
#include "StateMachine.h"
/* I could rework this right now,

	main focus is that, the documents can be handle all together. Instead of individually.
	So XMLHandler could handle a xml_document doc and a lastNodeElement variable
	essentally a data structure class

	*/
	/* PATHS VISUALLIZED
	*
	* Converting this class to be a finite state machine  2021-06-09
	*/
	/*
	2021-07-09 
	So the way this is going to work is, that I am going to see if everyfile is created in the constructor, if it doesnt need to be created
	it is already loaded within a variable or I have reference to load it in. with the loadFile Function i've created i've made it possible to 
	correctly load in each and every document into the CurrentDoc variable. 

	Now Each Read and Write function can be handle properly through my load file function.
	To prevent any future problems we are going to try, catch execptions all over the read and write functions that I have. 
	*/
class GameObject;
class Scene;
class Serializer
{
public:
	Serializer(Serializer &other) = delete;
	Serializer operator=(const Serializer& other) = delete;
	static Serializer* GetInstance();
	//PURE WRITE FUNCTIONS
	//Serializes GameObject
	void AddGameObject(GameObject* OBJ_); //Write function 
	//Serializes Animations of GameObject
	void AddAnimationState(GameObject* OBJ_, const char* imageSrc_);//Write function //Animations will be stored in there respective gameObjectDataXML sheet. With there associated tags. 
	void RemoveAnimation(std::string tagID_, const char* imageSrc_);//Write function 
	//Creates a Scene 
	void CreateScene(int currentScene_, const char* sceneName_);// Write function 
	//Serializes Scene
	void serializeScene(int currentScene_, Scene Scenedata_); //Write function //The Scenedata will push out how many gameObjects are in a scene and there ID's nothing more nothing less
	//Remove Scene
	void RemoveScene(const char* sceneName); //Write function
	//PURE READ FUNCTIONS
	void DeserializeAnimations(); //<-- Deserialzer should return a string
	void DeserializeScenes(); //<--Deserializer should return a string 
											  
	//HELPER FUNCTIONS 
	void newAnimationSet(); //WriteFunction
	pugi::xml_document* GameObjectSerializer(GameObject* OBJ_); //Write Function
	pugi::xml_document* DefaultSerialized(std::string tag_); //Write Function
	bool isChildNodeExist(const char* nodeName_); //Read Function
	bool SceneExist(int SceneIndex_, const char* SceneName_);//Read Function
	bool GameObjectExist(const char* ID_); // Read Function
	bool loadFile(const char* fileDirectory_); //Read function
private:
	Serializer();
	~Serializer();
	pugi::xml_document* CurrentDoc;
	pugi::xml_parse_result result;
	std::multimap<pugi::xml_document*, pugi::xml_node> documentList; 
	std::map < const char*, const char*> directorydictionary;
	const char* docRootNames[3] = { "EngineDataInfo","ScenesInfo","GameObjectsInfo" };
	const char* fullpath[3] = { "C:/Users/jalbm/source/repos/SDL2D_Project/SDL2D_Project/EngineData/EngineData.xml",
						  "C:/Users/jalbm/source/repos/SDL2D_Project/SDL2D_Project/Game/Scenes/SceneData.xml",
	"C:/Users/jalbm/source/repos/SDL2D_Project/SDL2D_Project/GameObjects/GameObjectData/GameObjectData.xml" };
	std::string const SerializedEnginePath = "C:/Users/jalbm/source/repos/SDL2D_Project/SDL2D_Project/EngineData";
	std::string const SerializedScenePath = "C:/Users/jalbm/source/repos/SDL2D_Project/SDL2D_Project/Game/Scenes";
	std::string const SerializedGameObjectInfo = "C:/Users/jalbm/source/repos/SDL2D_Project/SDL2D_Project/GameObjects/GameObjectData";
	static Serializer* instance;
};

#endif // !ANIMATORSERIALIZER