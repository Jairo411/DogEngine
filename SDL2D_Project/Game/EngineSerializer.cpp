#include "EngineSerializer.h"
#include "../GameObjects/GameObject.h"
#include "Scenes/Scene.h"

Serializer* Serializer::instance = nullptr;

Serializer::Serializer()
{
	//Just creating every file, not handling any of the files
	//intializing my std::map variable
	CurrentDoc = new pugi::xml_document();
	directorydictionary.insert(std::make_pair("C:/Users/jalbm/source/repos/SDL2D_Project/SDL2D_Project/EngineData", "/EngineData.xml"));
	directorydictionary.insert(std::make_pair("C:/Users/jalbm/source/repos/SDL2D_Project/SDL2D_Project/Game/Scenes", "/SceneData.xml"));
	directorydictionary.insert(std::make_pair("C:/Users/jalbm/source/repos/SDL2D_Project/SDL2D_Project/GameObjects/GameObjectData", "/GameObjectData.xml"));
	struct stat status;
	std::map <const char*, const char*>::iterator it = directorydictionary.begin();
	int count = 0;
	while (it != directorydictionary.end())
	{
		if (std::filesystem::exists(it->first) == false)
		{
			std::cout << it->first << std::endl;
			std::cout << "Directory doesn't exist, creating it..." << std::endl;

			std::filesystem::create_directory(it->first);
			std::cout << "Creating Files, currentFile being created :" << docRootNames[count] << std::endl;
			pugi::xml_document* temp = DefaultSerialized(docRootNames[count]);
			auto rootNode = temp->child(docRootNames[count]);
			// just some const char handling 
			std::string path = it->first;
			std::string file = it->second;
			std::string combined = path + file;


			temp->save_file(combined.c_str(), PUGIXML_TEXT(""));
			documentList.insert(std::make_pair(temp, rootNode));
		}
		else
		{
			//Files don't get re-written if they exist
			std::string path = it->first;
			std::string file = it->second;
			std::string combined = path + file;
			// this checks to see if the files exist themselves  
			// if they don't exist
			if (stat(combined.c_str(), &status) != 0)
			{
				std::cout << "Creating Files, currentFile being created :" << docRootNames[count] << std::endl;
				pugi::xml_document* temp;
				temp = DefaultSerialized(docRootNames[count]);
				auto rootNode = temp->child(docRootNames[count]);
				documentList.insert(std::make_pair(temp, rootNode));
				temp->save_file(combined.c_str(), PUGIXML_TEXT(""));
			}
			// if they do they get loaded in
			else if (stat(combined.c_str(), &status) == 0)
			{
				std::cout << "Loading in Files...." << std::endl;
				std::string path = it->first;
				std::string file = it->second;
				std::string combined = path + file;
				pugi::xml_document* temp = new pugi::xml_document();

				temp->load_file(combined.c_str());

				auto rootNode = temp->child(docRootNames[count]);
				documentList.insert(std::make_pair(temp, rootNode));
			}
		}
		count++;
		it++;
	}
	
}

Serializer* Serializer::GetInstance()
{
	if (instance==nullptr)
	{
		instance = new Serializer();
	}
	return instance;
}

Serializer::~Serializer()
{
	CurrentDoc = nullptr;
	delete CurrentDoc;
}



pugi::xml_document* Serializer::GameObjectSerializer(GameObject* OBJ_)
{
	return 	DefaultSerialized(OBJ_->nameID);
}

pugi::xml_document* Serializer::DefaultSerialized(std::string tag_)
{
	/* SO THIS IS ALWAYS THE DEFAULT*/
	pugi::xml_document* temp = new pugi::xml_document();

	auto declarationNode = temp->append_child(pugi::node_declaration);
	declarationNode.append_attribute("version") = 1.0f;
	declarationNode.append_attribute("encoding") = "ISO-8859-1";
	auto root = temp->append_child(pugi::node_element).set_name(tag_.c_str());

	return temp;
}

bool Serializer::isChildNodeExist(const char* nodeName_)
{
	if (CurrentDoc->child(nodeName_) != NULL)
	{
		return true;
	}

	return false;
}

bool Serializer::SceneExist(int SceneIndex_, const char* SceneName_)
{
	pugi::xml_node root = CurrentDoc->first_child();
	std::cout << root.name() << std::endl;
	for (pugi::xml_node node: root.children("Scene"))
	{
		std::cout << node.name()<<std::endl;
		pugi::xml_attribute_iterator it;
		std::string de_SerializedContainer[2];
		for (it= node.attributes().begin(); it !=node.attributes().end(); it++)
		{
			std::string attributeName = it->name();
			if (strcmp(attributeName.c_str(),"SceneNumber")==0)
			{
				std::cout << " " << it->name();
				std::cout << " = " << it->as_string();
				de_SerializedContainer[0] = it->as_string();
			}
			if (strcmp(attributeName.c_str(),"SceneName")==0)
			{
				std::cout << " " << it->name();
				std::cout << " = " << it->as_string();
				de_SerializedContainer[1] = it->as_string();
			}
			if (strcmp(de_SerializedContainer[0].c_str(),std::to_string(SceneIndex_).c_str())==0) // comparing the first attribute with my SceneIndex value
			{
				if (strcmp(de_SerializedContainer[1].c_str(),SceneName_)==0)
				{
					std::cout << std::endl;
					return true;
				}
			}
		}
		std::cout << std::endl;
	}
	return false;
}

bool Serializer::loadFile(const char* FileDirectory_)
{
	
	pugi::xml_parse_result result = CurrentDoc->load_file(FileDirectory_);
	std::cout << "Load results: " << result.description() << std::endl;
	return result;
}

void Serializer::AddAnimationState(GameObject* OBJ_, const char* imageSrc_)
{
	loadFile(fullpath[2]);

	std::map<pugi::xml_document*, pugi::xml_node>::iterator it;

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
void Serializer::CreateScene(int currentScene_, const char* sceneName_)
{
	/*I need to load the file if it exist*/
	loadFile(fullpath[1]);
	if (SceneExist(currentScene_, sceneName_) == false)
	{
		std::multimap<pugi::xml_document*, pugi::xml_node>::iterator it0 = documentList.begin();
		std::map <const char*, const char*>::iterator it1 = directorydictionary.begin();

		for (int i = 0; i < 1; i++)
		{
			it0++;
			it1++;
		}

		if (isChildNodeExist("ScenesInfo") == true)
		{

			auto rootNode = CurrentDoc->child("ScenesInfo");

			auto sceneNode = rootNode.append_child(pugi::node_element);
			sceneNode.set_name("Scene");
			sceneNode.append_attribute("SceneNumber ") = currentScene_;
			sceneNode.append_attribute("SceneName ") = sceneName_;


			std::string path = it1->first;
			std::string fileName = it1->second;
			std::string combined = path + fileName;

			CurrentDoc->save_file(combined.c_str(), PUGIXML_TEXT(""));
		}
	}
	else
	{
		std::cout << sceneName_ << ": this scene already exist" << std::endl;
	}
}

