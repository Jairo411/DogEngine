#ifndef ENGINESERIALIZER
#define ENGINESERIALIZER
#include <fstream>
#include <filesystem>
#include <string>
#include "PugiXML/pugixml.hpp"
#include<sys/stat.h>
#include<sys/types.h>
#include <iostream>

std::string const SerializedAnimationPath ="C:/Users/jalbm/source/repos/SDL2D_Project/SDL2D_Project/Animator";
std::string const SerializedEnginePath = "C:/Users/jalbm/source/repos/SDL2D_Project/SDL2D_Project/EngineData";
std::string const SerializedScenePath = "C:/Users/jalbm/source/repos/SDL2D_Project/SDL2D_Project/Scenes";
class GameObject;
class EngineSerializer
{
public:
	EngineSerializer();
	~EngineSerializer();
	//EngineStuff
	void AddAnimationState(GameObject OBj_,const char* imageSrc_);
	void RemoveAnimation(GameObject OBJ_ ,const char* imageSrc_);
	void CreateScene(int currentScene_);// This will only create a Scene but not its serialized information
	void RemoveScene();
	void Save();
	//Final Stuff 
	void Write();
	void ReadS();
private:
	pugi::xml_document doc;
	friend class Animation;
};
#endif // !ANIMATORSERIALIZER
