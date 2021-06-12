#include "EngineSerializer.h"
#include "../GameObjects/GameObject.h"

EngineSerializer::EngineSerializer()
{
	//struct stat status;
	//if (stat(SerializedEnginePath.c_str(), &status) != 0)
	//{
	//	std::cout << "This file doesn't exist";
	//	std::filesystem::create_directory("C:/Users/jalbm/source/repos/SDL2D_Project/SDL2D_Project/EngineData");
	//}
	////auto declarationNode = doc.append_child(pugi::node_declaration);
	////declarationNode.append_attribute("version") = 1.0;
	////declarationNode.append_attribute("encoding") = "ISO-8859-1";
	////auto rootNode = doc.append_child("Root").append_child(pugi::node_pcdata); //node_pcdata is the data of the node it closes the tag for you 

	//
	//std::string const path = "C:/Users/jalbm/source/repos/SDL2D_Project/SDL2D_Project/EngineData/BaseXML.xml"; 


	//bool save = doc.save_file(path.c_str(), PUGIXML_TEXT(" "));

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

void EngineSerializer::AddAnimationState(std::string tagID_, const char* imageSrc_)
{

}

void EngineSerializer::CreateScene(int currentScene_, std::string sceneName_)
{
	std::string path = "/SceneXML.xml"; //Might have to change the file name
	std::string combined = SerializedScenePath + path;

	//You can used this to check to see if files exist then add them into your engine  
	struct stat status;
	if (stat(combined.c_str(), &status) != 0)
	{
		std::cout << "This file doesn't exist, creating a new one" << std::endl;
		std::filesystem::create_directory("C:/Users/jalbm/source/repos/SDL2D_Project/SDL2D_Project/Scenes");


		doc = DefaultSerialized("Scenes");


		auto sceneNode = doc.child("Scenes").append_child(pugi::node_element);
		sceneNode.set_name("Scene");
		sceneNode.append_attribute("SceneNumber ") = currentScene_;
		sceneNode.append_attribute("SceneName ") = sceneName_.c_str();

		lastElement = sceneNode;

		bool save = doc.save_file(combined.c_str(), PUGIXML_TEXT(""));

		if (save == false)
		{
			std::cout << "Save failed" << std::endl;
		}
	}
	else  if (stat(SerializedScenePath.c_str(), &status) == 0)//The difference between the two statements is one creates the xml the other doesn't. 
	{
		std::string flag = "SceneName";
		std::string path = "/SceneXMl.xml";
		std::string combined = SerializedScenePath + path;
		std::string currentSceneName, lastSceneName;


		result = doc.load_file(combined.c_str());
		std::cout << "Load results: " << result.description() << std::endl;

		lastElement = doc.last_child().last_child(); //Cause the xml isn't ever gonna be that deep

		auto CurrentSceneNode = doc.child("Scenes").append_child(pugi::node_element);
		
	
		for (auto begin : lastElement.attributes())
		{
			if (flag.compare(begin.name())==0)
			{
				lastSceneName = begin.value();
			}
		}

		if (lastSceneName.compare(sceneName_.c_str())!=0)
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
			std::cout << "SceneName "<<sceneName_.c_str()<<" already exists"<< std::endl;
		}
	}
}
