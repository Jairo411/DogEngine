#include "EngineSerializer.h"
#include "../GameObjects/GameObject.h"

EngineSerializer::EngineSerializer()
{

}

EngineSerializer::~EngineSerializer()
{
}

pugi::xml_document EngineSerializer::GameObjectSerializer(GameObject* OBJ_)
{
	return 	DefaultSerialized(OBJ_->nameID);
}

pugi::xml_document EngineSerializer::DefaultSerialized(std::string tag_)
{
	/* SO THIS IS ALWAYS THE DEFAULT*/
	pugi::xml_document temp;

	auto declarationNode = temp.append_child(pugi::node_declaration);
	declarationNode.append_attribute("version") = 1.0;
	declarationNode.append_attribute("encoding") = "ISO-8859-1";
	auto root = temp.append_child(pugi::node_element).set_name(tag_.c_str());

	return temp;
}

void EngineSerializer::AddAnimationState(GameObject* OBJ_, const char* imageSrc_)
{
	std::string path = "/GameObjectsData.xml";
	std::string combinedPath = SerializedGameObjectInfo + path;
	std::string flag = "GameObject";
	struct stat status;

	//Creates new file
	if (stat(combinedPath.c_str(), &status) != 0)
	{
		if (std::filesystem::exists("C:/Users/jalbm/source/repos/SDL2D_Project/SDL2D_Project/GameObjects/GameObjectData") == false)
		{
			std::cout << "directory doesn't exist, creating a new one";
			std::filesystem::create_directory("C:/Users/jalbm/source/repos/SDL2D_Project/SDL2D_Project/GameObjects/GameObjectData");
		}

		std::cout << "This file doesn't exist, creating a new one " << std::endl;

		doc = DefaultSerialized("GameObjectsInfo");

		auto GameObjectNode = doc.child("GameObjectsInfo").append_child(pugi::node_element);
		GameObjectNode.set_name("GameObject");
		GameObjectNode.append_attribute("GameObjectID ") = OBJ_->nameID.c_str();
		
		auto AnimationNode=GameObjectNode.append_child(pugi::node_element);
		AnimationNode.set_name("AnimationInfo");
		AnimationNode.append_attribute("AmountOfAnimationSets") = 0;
		auto childAnimation = AnimationNode.append_child(pugi::node_element);

		std::string set = "AnimationSet"; 
		std::string combined= set + AnimationNode.first_attribute().value();

		childAnimation.set_name(combined.c_str());

		auto IMGSrc=childAnimation.append_child(pugi::node_element);
		
		IMGSrc.set_name("IMGSrc");
		IMGSrc.append_child(pugi::node_pcdata).set_value(imageSrc_);
		
		lastNodeElement = IMGSrc;

		bool save = doc.save_file(combinedPath.c_str(), PUGIXML_TEXT(""));
	} //Loads File 
	else if (stat(combinedPath.c_str(), &status) == 0)
	{
		std::string lastAnimationSet;
		result = doc.load_file(combinedPath.c_str());
		std::cout << "load results: " << result.description() << std::endl;


		auto parentOfLastNode = doc.child("AnimationInfo");
		int count=0;

		
	}
}
void EngineSerializer::CreateScene(int currentScene_, std::string sceneName_)
{
	std::string path = "/SceneXML.xml"; //Might have to change the file name
	std::string combined = SerializedScenePath + path;
	std::string flag = "SceneName";

	//You can used this to check to see if files exist then add them into your engine  
	struct stat status;
	if (stat(combined.c_str(), &status) != 0)
	{
		if (std::filesystem::exists("C:/Users/jalbm/source/repos/SDL2D_Project/SDL2D_Project/Game/Scenes")==false)
		{
			std::cout << "directory doesn't exist, creating a new one" << std::endl;
			std::filesystem::create_directory("C:/Users/jalbm/source/repos/SDL2D_Project/SDL2D_Project/Game/Scenes");
		}

		std::cout << "This file doesn't exist, creating a new one" << std::endl;
		doc = DefaultSerialized("Scenes");

		auto sceneNode = doc.child("Scenes").append_child(pugi::node_element);
		sceneNode.set_name("Scene");
		sceneNode.append_attribute("SceneNumber ") = currentScene_;
		sceneNode.append_attribute("SceneName ") = sceneName_.c_str();


		lastNodeElement = sceneNode;

		bool save = doc.save_file(combined.c_str(), PUGIXML_TEXT(""));

		if (save == false)
		{
			std::cout << "Save failed" << std::endl;
		}
	}
	else  if (stat(combined.c_str(), &status) == 0)//The difference between the two statements is one creates the xml the other doesn't. 
	{

		std::string currentSceneName, lastSceneName;

		result = doc.load_file(combined.c_str());
		std::cout << "Load results: " << result.description() << std::endl;

		lastNodeElement = doc.last_child().last_child(); //Cause the xml isn't ever gonna be that deep. In more clear terms this xml is about 2-3 tags deep.

		auto CurrentSceneNode = doc.child("Scenes").append_child(pugi::node_element);
		

		for (auto begin : lastNodeElement.attributes())
		{
			if (flag.compare(begin.name()) == 0)
			{
				lastSceneName = begin.value();
			}
		}

		if (lastSceneName.compare(sceneName_.c_str()) != 0)
		{
			CurrentSceneNode.set_name("Scene");
			CurrentSceneNode.append_attribute("SceneNumber ") = currentScene_;
			CurrentSceneNode.append_attribute("SceneName ") = sceneName_.c_str();

			bool save = doc.save_file(combined.c_str(), PUGIXML_TEXT(""));

			if (save == false)
			{
				std::cout << "Save failed" << std::endl;
			}
		}
		else
		{
			std::cout << "SceneName " << sceneName_.c_str() << " already exists" << std::endl;
		}
	}
}
