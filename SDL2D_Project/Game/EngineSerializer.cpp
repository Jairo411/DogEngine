#include "EngineSerializer.h"
#include "../GameObjects/GameObject.h"

EngineSerializer::EngineSerializer()
{
	//Just creating every file, not handling any of the files
	//intializing my std::map variable
	directorydictionary.insert(std::make_pair("C:/Users/jalbm/source/repos/SDL2D_Project/SDL2D_Project/EngineData", "/EngineData.xml"));
	directorydictionary.insert(std::make_pair("C:/Users/jalbm/source/repos/SDL2D_Project/SDL2D_Project/Game/Scenes", "/SceneData.xml"));
	directorydictionary.insert(std::make_pair("C:/Users/jalbm/source/repos/SDL2D_Project/SDL2D_Project/GameObjects/GameObjectData", "/GameObjectData.xml"));

	struct stat status;
	std::map <const char*, const char*>::iterator it = directorydictionary.begin();
	int count = 0;
	while (it != directorydictionary.end())
	{
		if (std::filesystem::exists(it->first)==false)
		{
			std::cout << it->first << std::endl;
			std::cout << "Directory doesn't exist, creating it..." << std::endl;

			std::filesystem::create_directory(it->first);
			std::cout << "Creating Files, currentFile being created :" << docRootNames[count] << std::endl;
			pugi::xml_document temp = DefaultSerialized(docRootNames[count]);
			// just some const char handling 
			std::string path = it->first;
			std::string file = it->second;
			std::string combined = path + file;

			temp.save_file(combined.c_str(), PUGIXML_TEXT(""));
			documentList.insert(std::make_pair(&temp, pugi::xml_node()));
		}
		else
		{
			std::string path = it->first;
			std::string file = it->second;
			std::string combined = path + file;
			if (stat(combined.c_str(),&status)!=0)
			{
				std::cout << "Creating Files, currentFile being created :" << docRootNames[count] << std::endl;
				pugi::xml_document temp = DefaultSerialized(docRootNames[count]);

				temp.save_file(combined.c_str(), PUGIXML_TEXT(""));
				documentList.insert(std::make_pair(&temp, pugi::xml_node()));
			}
		}
		it++;
		count++;
	}

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

bool EngineSerializer::isNodeExist(const char* nodeName_)
{
	if (CurrentDoc->child(nodeName_)!=NULL)
	{
		return true;
	}
	return false;
}

void EngineSerializer::AddAnimationState(GameObject* OBJ_, const char* imageSrc_)
{

	std::map<pugi::xml_document*, pugi::xml_node>::iterator it;

	std::string path = "/GameObjectsData.xml";
	std::string combinedPath = SerializedGameObjectInfo + path;
	std::string flag = "GameObject";
	struct stat status;

	//Creates new file
	//if (stat(combinedPath.c_str(), &status) != 0)
	//{
	//	if (std::filesystem::exists("C:/Users/jalbm/source/repos/SDL2D_Project/SDL2D_Project/GameObjects/GameObjectData") == false)
	//	{
	//		std::cout << "directory doesn't exist, creating a new one";
	//		std::filesystem::create_directory("C:/Users/jalbm/source/repos/SDL2D_Project/SDL2D_Project/GameObjects/GameObjectData");
	//	}

	//	std::cout << "This file doesn't exist, creating a new one " << std::endl;

	//	CurrentDoc = DefaultSerialized("GameObjectsInfo");

	//	auto GameObjectNode = CurrentDoc.child("GameObjectsInfo").append_child(pugi::node_element);
	//	GameObjectNode.set_name("GameObject");
	//	GameObjectNode.append_attribute("GameObjectID ") = OBJ_->nameID.c_str();
	//	
	//	auto AnimationNode=GameObjectNode.append_child(pugi::node_element);
	//	AnimationNode.set_name("AnimationInfo");
	//	AnimationNode.append_attribute("AmountOfAnimationSets") = 0;
	//	auto childAnimation = AnimationNode.append_child(pugi::node_element);

	//	std::string set = "AnimationSet"; 
	//	std::string combined= set + AnimationNode.first_attribute().value();

	//	childAnimation.set_name(combined.c_str());

	//	auto IMGSrc=childAnimation.append_child(pugi::node_element);
	//	
	//	IMGSrc.set_name("IMGSrc");
	//	IMGSrc.append_child(pugi::node_pcdata).set_value(imageSrc_);
	//	
	//	lastNodeElement = IMGSrc;

	//	bool save = CurrentDoc.save_file(combinedPath.c_str(), PUGIXML_TEXT(""));
	//} //Loads File 
	//else if (stat(combinedPath.c_str(), &status) == 0)
	//{
	//	std::string lastAnimationSet;
	//	result = CurrentDoc.load_file(combinedPath.c_str());
	//	std::cout << "load results: " << result.description() << std::endl;


	//	auto parentOfLastNode = CurrentDoc.child("AnimationInfo");
	//	int count=0;

	//	
	//	
	//}
}
void EngineSerializer::CreateScene(int currentScene_, std::string sceneName_)
{
	
	std::map<pugi::xml_document*, pugi::xml_node>::iterator it=documentList.begin();

	while (it!=documentList.end())
	{
		if (it->first->child("ScenesInfo"))
		{
		//Right here this is loading from memory
		pugi::xml_parse_result result =	CurrentDoc->load_buffer(it->first,sizeof(it->first));
		std::cout << "Load results: " << result.description() << std::endl;
			//If rootNode exist or not 
			if (isNodeExist("Scenes"))
			{
				auto sceneNode = CurrentDoc->child("Scenes").append_child(pugi::node_element);
				sceneNode.set_name("Scene");
				sceneNode.append_attribute("SceneNumber ") = currentScene_;
				sceneNode.append_attribute("SceneName ") = sceneName_.c_str();
			}
			else
			{
				auto rootNode = CurrentDoc->append_child(pugi::node_element);
				rootNode.set_name("Scenes");
				auto sceneNode = rootNode.append_child(pugi::node_element);
				sceneNode.set_name("Scene");
				sceneNode.append_attribute("SceneNumber ") = currentScene_;
				sceneNode.append_attribute("SceneName ") = sceneName_.c_str();
			}
		}
	}

	/*	auto sceneNode = CurrentDoc.child("Scenes").append_child(pugi::node_element);
		sceneNode.set_name("Scene");
		sceneNode.append_attribute("SceneNumber ") = currentScene_;
		sceneNode.append_attribute("SceneName ") = sceneName_.c_str();


		lastNodeElement = sceneNode;

		bool save = CurrentDoc.save_file(combined.c_str(), PUGIXML_TEXT(""));

		if (save == false)
		{
			std::cout << "Save failed" << std::endl;
		}*/
	
	//This had an if statement

		//std::string currentSceneName, lastSceneName;

		//result = CurrentDoc.load_file(combined.c_str());
		//std::cout << "Load results: " << result.description() << std::endl;

		//lastNodeElement = CurrentDoc.last_child().last_child(); //Cause the xml isn't ever gonna be that deep. In more clear terms this xml is about 2-3 tags deep.

		//auto CurrentSceneNode = CurrentDoc.child("Scenes").append_child(pugi::node_element);
		//

		//for (auto begin : lastNodeElement.attributes())
		//{
		//	if (flag.compare(begin.name()) == 0)
		//	{
		//		lastSceneName = begin.value();
		//	}
		//}

		//if (lastSceneName.compare(sceneName_.c_str()) != 0)
		//{
		//	CurrentSceneNode.set_name("Scene");
		//	CurrentSceneNode.append_attribute("SceneNumber ") = currentScene_;
		//	CurrentSceneNode.append_attribute("SceneName ") = sceneName_.c_str();

		//	bool save = CurrentDoc.save_file(combined.c_str(), PUGIXML_TEXT(""));

		//	if (save == false)
		//	{
		//		std::cout << "Save failed" << std::endl;
		//	}
		//}
		//else
		//{
		//	std::cout << "SceneName " << sceneName_.c_str() << " already exists" << std::endl;
		//}
}
