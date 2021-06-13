#ifndef ENGINESERIALIZER
#define ENGINESERIALIZER
#include <fstream>
#include <filesystem>
#include <string>
#include "PugiXML/pugixml.hpp"
#include<sys/stat.h>
#include<sys/types.h>
#include <iostream>

/* I could rework this right now, 

	main focus is that, the documents can be handle all together. Instead of individually. 
	So XMLHandler could handle a xml_document doc and a lastNodeElement variable
	essentally a data structure class 
	
	*/

std::string const SerializedAnimationPath ="C:/Users/jalbm/source/repos/SDL2D_Project/SDL2D_Project/Animator";
std::string const SerializedEnginePath = "C:/Users/jalbm/source/repos/SDL2D_Project/SDL2D_Project/EngineData";
std::string const SerializedScenePath = "C:/Users/jalbm/source/repos/SDL2D_Project/SDL2D_Project/Game/Scenes";
std::string const SerializedGameObjectInfo = "C:/Users/jalbm/source/repos/SDL2D_Project/SDL2D_Project/GameObjects/GameObjectData";
class GameObject;

class XMLHandler
{
public:
	XMLHandler();
	~XMLHandler();
	void Update(float deltaTime_);
	pugi::xml_document doc;
private:
	bool isExist;
	bool hasChanged;
	std::string xmlPath;
};

class EngineSerializer
{
public:
	EngineSerializer();
	~EngineSerializer();
	//XML File Handler 
	//EngineStuff
	/*
		Anything with the game objects should handle there current xml file, to make it modular	
	*/
	void AddAnimationState(GameObject* OBJ_,const char* imageSrc_);
	void RemoveAnimation(std::string tagID_ ,const char* imageSrc_);
	void CreateScene(int currentScene_,std::string sceneName_);// This will only create a Scene but not its serialized information
	void RemoveScene(const char* sceneName);
	void Save();
	//Final Stuff 
	void Update();
	void Write();
	void Read();
	//Helper Functions 
	void newAnimationSet();
	pugi::xml_document GameObjectSerializer(GameObject* OBJ_);
	pugi::xml_document DefaultSerialized(std::string tag_);
private:
	pugi::xml_document doc;
	pugi::xml_parse_result result;
	pugi::xml_node lastNodeElement; //This is kinda a bad idea and should exist for their own xmlDocuments
	friend class Animation;
	bool isCreated;
};
#endif // !ANIMATORSERIALIZER
