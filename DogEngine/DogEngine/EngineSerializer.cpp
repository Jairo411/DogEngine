#include "EngineSerializer.h"
#include "../GameObjects/GameObject.h"
#include "Scenes/Scene.h"

DGEngine::Serializer* Serializer::instance = nullptr;

DGEngine::Serializer::Serializer()
{
	//Just creating every file, not handling any of the files
	CurrentDoc = new pugi::xml_document();
	directoryHandler = DirectoryHandler();
	

	/*22-12-2023
	* Okay here is an idea, the iterator will simply just erase where it is at
	* so what I can do is create a for loop probably using auto, because I will never know the path
	* of the root,user and desktop. But what I can do is erase all the characters of the current working directory of this file 
	* till I get to this path /DogEngine/SDL2D_Project.
	*/

	
	/*23-12-2023
	Because the iterator checks for characters one by one, 
	 I have to actually make the iterator check for the first appearance of 
	 DogEngine in the path, because that path is the actual project folder containing everything. 
	 
	 I am currently thinking about how I am going to add 3rd party libraries into my DogEngine,
	 because if I want my project to be able to be built everywhere, I either need to store all the libraries within my project. 
	 Or create somesort of package manager, or use cmake. 

	 So this is kind of a temporary solution to get things working. 

	 This engine module needs to be literally pretty modular, already, so to prevent refactoring too much, what I am going to do is 
	 not hard code it as much.
	 */
	//for (auto i = cwd; i < length; i++)
	//{

	//}
	//
	std::cout << cwd << std::endl;
	/*
	* If I am able to take the current working directory of this file C:\Users\jalbm\Documents\Visual Studio 2022\DogEngine\SDL2D_Project\DogEngine\EngineSerializer.cpp
	* which is the full path of this project, and then remove every that isn't this \DogEngine\SDL2D_Project\DogEngine
	* I will be able to access all files through my project while also technically being cross platform.
	*/
	std::vector<std::string> directories = 
	{
	"DogEngine/DogEngine/GameEngineSaveInfo/EngineData/",
	"DogEngine/DogEngine/GameEngineSaveInfo/Scenes/",
	"DogEngine/DogEngine/GameEngineSaveInfo/GameObjects/"
	};

	

	std::vector<std::string> files =
	{
		"DogEngine/DogEngine/GameEngineSaveInfo/EngineSaveData.xml",
		"DogEngine/DogEngine/GameEngineSaveInfo/SceneData.xml",
		"DogEngine/DogEngine/GameEngineSaveInfo/GameObjectData.xml"
	};

	directoryHandler.SetDefaults(directories, files);

	if (directoryHandler!="DogEngine/DogEngine/GameEngineSaveInfo/")
	{
		directoryHandler.CreateDirectory("DogEngine/DogEngine/GameEngineSaveInfo/");
	}
	
	directoryHandler = "DogEngine/DogEngine/GameEngineSaveInfo/";

	if (directoryHandler!=directoryHandler.GetIntialDirectories()) //create the directories if files don't exist
	{
		directoryHandler.CreateDirectory(directoryHandler.GetIntialDirectories()[0].c_str());
		directoryHandler.CreateDirectory(directoryHandler.GetIntialDirectories()[1].c_str());
		directoryHandler.CreateDirectory(directoryHandler.GetIntialDirectories()[2].c_str());
	}
	
	if (directoryHandler!=directoryHandler.GetIntialFiles()) // Load in the directories if files do exist
	{
		pugi::xml_document* document0;
		pugi::xml_document* document1;
		pugi::xml_document* document2;
		document0 = DefaultSerialized(directoryHandler.GetIntialFiles()[0].c_str());
		document1 = DefaultSerialized(directoryHandler.GetIntialFiles()[1].c_str());
		document2 = DefaultSerialized(directoryHandler.GetIntialFiles()[2].c_str());
		document0->save_file(directoryHandler.GetIntialFiles()[0].c_str());
		document1->save_file(directoryHandler.GetIntialFiles()[1].c_str());
		document2->save_file(directoryHandler.GetIntialFiles()[2].c_str());
		document_list.push_back(document0);
		document_list.push_back(document1);
		document_list.push_back(document2);
	}

	//struct stat status;
	///// Create the directories if they don't exist
	//for (int CurrentIndex = 0; CurrentIndex < sizeof(directoryPath) / sizeof(*directoryPath); CurrentIndex++) 
	//{
	//	if (std::filesystem::exists(directoryPath[CurrentIndex]) == false)
	//	{
	//		std::cout << directoryPath[CurrentIndex] << std::endl;
	//		std::cout << "Directory doesn't exist, creating it..." << std::endl;
	//	}
	//	bool file = std::filesystem::create_directories(directoryPath[CurrentIndex]);
	//	assert(file == false); //Put assert in places that shouldn't go wrong at all. 
	//}

	//for (int currentIndex = 0; currentIndex < sizeof(fileNames) / sizeof(*fileNames); currentIndex++)
	//{
	//	std::string path = directoryPath[currentIndex + 1];
	//	std::string file = fileNames[currentIndex];
	//	std::string combined = path + file;
	//	/// Create the files if they don't exist
	//	if (stat(combined.c_str(), &status) != 0)
	//	{
	//		std::cout << "Creating Files, currentFiles being created :" << docRootNames[currentIndex] << std::endl;
	//		pugi::xml_document* document;
	//		document = DefaultSerialized(docRootNames[currentIndex]);
	//		document->save_file(combined.c_str(), PUGIXML_TEXT(""));
	//		document_list.push_back(document);
	//	}
	//	/// Load the files because they exist
	//	else if (stat(combined.c_str(), &status) == 0)
	//	{
	//		std::cout << "Loading in Files..." << std::endl;
	//		std::string file = fileNames[currentIndex];
	//		std::string combined = path + file;
	//		pugi::xml_document* document = new pugi::xml_document();
	//		document->load_file(combined.c_str());
	//		document_list.push_back(document);
	//	}
	//}



	
	//for (int i = 0; i < lengthDir; i++)
	//{
	//	if (std::filesystem::exists(directoryPath[indexDir]) == false)
	//	{
	//		std::cout << directoryPath[indexDir] << std::endl;
	//		std::cout << "Directory doesn't exist, creating it..." << std::endl;
	//	}
	//	
	//	bool file =std::filesystem::create_directories(directoryPath[indexDir]);
	//	assert(file == false); //Put assert in places that shouldn't go hard at all. 
	//	indexDir++;
	//}

	/*for (int i = 0; i < lengthFile; i++)
	{
		std::string path = directoryPath[indexFile+1];
		std::string file = fileNames[indexFile];
		std::string combined = path + file;
		/// Create the files if they don't exist
		if (stat(combined.c_str(), &status)!=0)
		{
			std::cout << "Creating Files, currentFiles being created :" << docRootNames[indexFile] << std::endl;
			pugi::xml_document* document;
			document = DefaultSerialized(docRootNames[indexFile]);
			document->save_file(combined.c_str(), PUGIXML_TEXT(""));
			document_list.push_back(document);
		}
		/// Load the files because they exist
		else if (stat(combined.c_str(),&status)==0)
		{
			std::cout << "Loading in Files..." << std::endl;
			std::string file = fileNames[indexFile];
			std::string combined = path + file;
			pugi::xml_document* document = new pugi::xml_document();
			document->load_file(combined.c_str());
			document_list.push_back(document);
		}
		indexFile++;
	}*/
	/*while (done != true)
	{
		
		if (std::filesystem::exists(directoryPath[indexDir]) == false)
		{
			std::cout << directoryPath[indexDir] << std::endl;
			std::cout << "Directory doesn't exist, creating it..." << std::endl;
		}
		// get current path from iterator then check to see if they exist or not
		std::string path = directoryPath[indexDir];
		std::string file = fileNames[indexFile];
		std::string combined = path + file;
		// this checks to see if the files exist themselves  
		// if they don't exist
		if (stat(combined.c_str(), &status) != 0)
		{
			std::cout << "Creating Files, currentFile being created :" << docRootNames[indexFile] << std::endl;
			pugi::xml_document* document;
			document = DefaultSerialized(docRootNames[indexFile]);
			document->save_file(combined.c_str(), PUGIXML_TEXT(""));
			document_list.push_back(document);
		}
		// if they do they get loaded in
		else if (stat(combined.c_str(), &status) == 0)
		{
			std::cout << "Loading in Files...." << std::endl;
			std::string file = fileNames[indexFile];
			std::string combined = path + file;
			pugi::xml_document* document = new pugi::xml_document();
			document->load_file(combined.c_str());
			document_list.push_back(document);
		}
	}
	*/
}

DGEngine::Serializer* Serializer::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new Serializer();
	}
	return instance;
}

DGEngine::Serializer::~Serializer()
{
	CurrentDoc = nullptr;
	delete CurrentDoc;
}



int DGEngine::Serializer::GenerateRandomNumber()
{
	int random = 0;
	srand(random);
	random = (rand() % INTMAX_MAX) + 1;
	return random;
}

pugi::xml_document* DGEngine::Serializer::DefaultSerialized(std::string tag_)
{
	/* SO THIS IS ALWAYS THE DEFAULT*/
	pugi::xml_document* temp = new pugi::xml_document();
	auto declarationNode = temp->append_child(pugi::node_declaration);
	declarationNode.append_attribute("version") = 1.0f;
	declarationNode.append_attribute("encoding") = "UTF-8";
	declarationNode.append_attribute("standalone") = "no";
	auto root = temp->append_child(pugi::node_element).set_name(tag_.c_str());

	return temp;
}

bool DGEngine::Serializer::isChildNodeExist(const char* nodeName_)
{
	if (CurrentDoc->child(nodeName_) != NULL)
	{
		return true;
	}

	return false;
}

bool DGEngine::Serializer::SceneExist(int SceneIndex_, const char* SceneName_)
{
	loadFile(directoryHandler.GetIntialDirectories()[1].c_str());
	pugi::xml_node root = CurrentDoc->first_child();
	std::cout << root.name() << std::endl;
	for (pugi::xml_node node : root.children("Scene"))
	{
		std::cout << node.name() << std::endl;
		pugi::xml_attribute_iterator it;
		std::string de_SerializedContainer[2];
		for (it = node.attributes().begin(); it != node.attributes().end(); it++)
		{
			std::string attributeName = it->name();
			if (strcmp(attributeName.c_str(), "SceneNumber") == 0)
			{
				std::cout << " " << it->name();
				std::cout << " = " << it->as_string();
				de_SerializedContainer[0] = it->as_string();
			}
			if (strcmp(attributeName.c_str(), "SceneName") == 0)
			{
				std::cout << " " << it->name();
				std::cout << " = " << it->as_string();
				de_SerializedContainer[1] = it->as_string();
			}
			if (strcmp(de_SerializedContainer[0].c_str(), std::to_string(SceneIndex_).c_str()) == 0) // comparing the first attribute with my SceneIndex value
			{
				if (strcmp(de_SerializedContainer[1].c_str(), SceneName_) == 0)
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

bool DGEngine::Serializer::GameObjectExist(int ID_)
{
	if (ID_!=0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool DGEngine::Serializer::loadFile(const char* FileDirectory_)
{

	pugi::xml_parse_result result = CurrentDoc->load_file(FileDirectory_);
	std::cout << "Load results: " << result.description() << std::endl;
	return result;
}



void DGEngine::Serializer::Update()
{
	//if HasFileChange == true or whatever
	//Assign existing ID to existing gameObj
	//if existing GameObj exist and no ID exist make an ID for that existing game object
}

void DGEngine::Serializer::AddGameObject(GameObject* OBJ_) // 
{
	loadFile(directoryHandler.GetIntialDirectories()[2].c_str());
	if (GameObjectExist(OBJ_->getID() == false))
	{
		CreateID(OBJ_); // Create ID for Object that doesn't have one
		if (isChildNodeExist("GameObjectsInfo") == true)
		{
			auto rootNode = CurrentDoc->child("GameObjectsInfo"); //get to this node, then locate yourself to the last entry in that node

			auto gameObjectNode = rootNode.append_child(pugi::node_element);
			gameObjectNode.set_name("GameObject");
			gameObjectNode.append_attribute("ID") = OBJ_->getID();
			gameObjectNode.append_attribute("Name") = OBJ_->getNameIdentifier().c_str();


			auto classNode = gameObjectNode.append_child(pugi::node_element);
			classNode.set_name("Class");
			classNode.append_attribute("Name") = OBJ_->getClassName().c_str();


			auto ParentNode = gameObjectNode.append_child(pugi::node_element);
			ParentNode.set_name("ParentOf");

			auto childNode = gameObjectNode.append_child(pugi::node_element);
			childNode.set_name("ChildOf");

			CurrentDoc->save_file(directoryHandler.GetIntialDirectories()[2].c_str(), PUGIXML_TEXT(""));
		}
	}
}

void DGEngine::Serializer::AddGameObject(int ID_)
{
	loadFile(directoryHandler.GetIntialDirectories()[2].c_str());
}

void DGEngine::Serializer::AssignID(std::list<GameObject*> OBJ_List) //this will only assign ID to object/class that already exist, this will only be called in the beginning of the Engine load
{
	loadFile(directoryHandler.GetIntialDirectories()[2].c_str());

	pugi::xml_node root = CurrentDoc->first_child();
	std::cout << root.name() << std::endl;
	
	for (pugi::xml_node node : root.children("GameObject"))
	{
		if (node.first_attribute().as_int()!=0)
		{
			gameObjectIDs.push_back(node.first_attribute().as_int());
		}
	}

	if (gameObjectIDs.size()<OBJ_List.size())
	{
		/// if there are less GameObject in memory then in save data, we can choose to create more GameObjects or remove the data
		///remove the data
		std::vector<int>::iterator it = gameObjectIDs.begin();
		for (pugi::xml_node node : root.children("GameObject"))
		{
			if (node.first_attribute().as_int()!=*it|| node.first_attribute().as_int()!=0 && it==gameObjectIDs.end())
			{
				//first remove node's children 
				CurrentDoc->child(node.name()).remove_children();
				//then remove that node itself
				CurrentDoc->remove_child(node.name());
			}
			if (it!=gameObjectIDs.end())
			{
				it++;
			}
		}
	}
	else if (gameObjectIDs.size()>OBJ_List.size())
	{
		/// if there are more GameObject in memory then in save data, we can choose to remove the GameObjects from memory or add the data
		///add the data
		/// if the last xml_node doesn't exist to the current 
		/// with the way this is set up, it will probably load the information during the program being ran, but not actually create the objects in the program. Only till the next program run.
		/// Ill have to decide if im okay with this design choice
		std::vector<int>::iterator it = gameObjectIDs.begin();
		pugi::xml_node::iterator nodeIt = CurrentDoc->children().begin();
		for (it; it != gameObjectIDs.end(); it++)
		{
			int ID = *it;
			if (nodeIt==CurrentDoc->children().end())
			{
				AddGameObject(ID);
			}
			else
			{
				nodeIt++;
			}
		}
	}
	else if (gameObjectIDs.size()==OBJ_List.size())
	{
		/// there is the same amount of GameObject in memory as in save data
	}
}

void DGEngine::Serializer::CreateID(GameObject* OBJ_)
{
	//Lets just make sure that the ID doesn't already exist
	//then assign that ID in our XML file
	int ID = 0;
	for (int i = 0; i<gameObjectIDs.size(); i++)
	{
		//If ID doesn't exist then assign it 
		int temp = gameObjectIDs[i];	
		ID = GenerateRandomNumber();
		while (ID == temp)
		{
		ID = GenerateRandomNumber();
		}
		
	}
	OBJ_->setID(ID);
	gameObjectIDs.push_back(ID);
	
}

void DGEngine::Serializer::AddAnimationState(GameObject* OBJ_, const char* imageSrc_)
{
	loadFile(directoryHandler.GetIntialDirectories()[2].c_str());
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
void DGEngine::Serializer::RemoveAnimation(std::string tagID_, const char* imageSrc_)
{
}
void DGEngine::Serializer::CreateScene(int currentScene_, const char* sceneName_)
{
	/*I need to load the file if it exist*/
	loadFile(directoryHandler.GetIntialDirectories()[1].c_str());
	if (SceneExist(currentScene_, sceneName_) == false)
	{
		if (isChildNodeExist("ScenesInfo") == true)
		{

			auto rootNode = CurrentDoc->child("ScenesInfo");

			auto sceneNode = rootNode.append_child(pugi::node_element);
			sceneNode.set_name("Scene");
			sceneNode.append_attribute("SceneNumber ") = currentScene_;
			sceneNode.append_attribute("SceneName ") = sceneName_;

			CurrentDoc->save_file(directoryHandler.GetIntialDirectories()[1].c_str(), PUGIXML_TEXT(""));
		}
	}
	else
	{
		std::cout << sceneName_ << ": this scene already exist" << std::endl;
	}
}

void DGEngine::Serializer::SaveScene(int currentScene_, Scene& Scenedata_)
{
}

void DGEngine::Serializer::RemoveScene(const char* sceneName)
{
}

void DGEngine::Serializer::DeserializeAnimations()
{
}

void DGEngine::Serializer::DeserializeScenes()
{
}

