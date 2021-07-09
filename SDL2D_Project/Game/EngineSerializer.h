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
std::string const SerializedEnginePath = "C:/Users/jalbm/source/repos/SDL2D_Project/SDL2D_Project/EngineData";
std::string const SerializedScenePath = "C:/Users/jalbm/source/repos/SDL2D_Project/SDL2D_Project/Game/Scenes";
std::string const SerializedGameObjectInfo = "C:/Users/jalbm/source/repos/SDL2D_Project/SDL2D_Project/GameObjects/GameObjectData";



class GameObject;
class Serializer
{
public:
	Serializer();
	~Serializer();
	//PURE WRITE FUNCTIONS
	void AddAnimationState(GameObject* OBJ_, const char* imageSrc_);//Write function
	void RemoveAnimation(std::string tagID_, const char* imageSrc_);//Write function
	void CreateScene(int currentScene_, std::string sceneName_);// Write function
	void RemoveScene(const char* sceneName); //Write function
	//PURE READ FUNCTIONS

											 
	//HELPER FUNCTIONS 
	void newAnimationSet(); //WriteFunction
	pugi::xml_document* GameObjectSerializer(GameObject* OBJ_); //Write Function
	pugi::xml_document* DefaultSerialized(std::string tag_); //Write Function
	bool isChildNodeExist(const char* nodeName_); //Read Function
	void SceneExist(int SceneIndex_, const char* SceneName_);//Red Function
	void loadFile(const char* nodeName_); //Read function
	//Debug functions
	void Print();
private:
	pugi::xml_document* CurrentDoc;
	pugi::xml_parse_result result;
	std::multimap <pugi::xml_document*, pugi::xml_node> documentList;
	std::map < const char*, const char*> directorydictionary; // This might need to be remove
	friend class Animation;
	const char* docRootNames[3] = { "EngineDataInfo","ScenesInfo","GameObjectsInfo" };
};

class EngineSerializer
{
public:
	void Update(int condition_);
	void operator()();
private:
	int condition;
	StateMachine<IntializedState, UpdateState, ReadState, WriteState> stateMachine;
};

#endif // !ANIMATORSERIALIZER
