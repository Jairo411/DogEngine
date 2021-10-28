#include "EngineSerializer.h"
#include "../GameObjects/GameObject.h"
#include "Scenes/Scene.h"

Serializer* Serializer::instance = nullptr;

Serializer::Serializer()
{
	//Just creating every file, not handling any of the files
	std::string directoryPaths[4] = { directoryPath[0],directoryPath[1],directoryPath[2],directoryPath[3]};
	std::string fileNames[4] = { fileNames[0],fileNames[1],fileNames[2],fileNames[3] };
	std::string::const_iterator its = directoryPaths->cbegin();
	CurrentDoc = new pugi::xml_document();
	struct stat status;
	int count = 0;
	while (its != directoryPaths->cend())
	{
		if (std::filesystem::exists(its) == false)
		{
			std::cout << *its << std::endl;
			std::cout << "Directory doesn't exist, creating it..." << std::endl;

			std::filesystem::create_directory(its);
			std::cout << "Creating Files, currentFile being created :" << docRootNames[count] << std::endl;
		}
		// get current path from iterator then check to see if they exist or not
		std::string iteratorString(1, *its);
		std::string path = iteratorString;
		std::string file = fileNames[count];
		std::string combined = path + file;
		// this checks to see if the files exist themselves  
		// if they don't exist
		if (stat(combined.c_str(), &status) != 0)
		{
			std::cout << "Creating Files, currentFile being created :" << docRootNames[count] << std::endl;
			pugi::xml_document* document;
			document = DefaultSerialized(docRootNames[count]);
			document->save_file(combined.c_str(), PUGIXML_TEXT(""));
			document_list.push_back(document);
		}
		// if they do they get loaded in
		else if (stat(combined.c_str(), &status) == 0)
		{
			std::cout << "Loading in Files...." << std::endl;
			std::string path = iteratorString;
			std::string file = fileNames[count];
			std::string combined = path + file;
			pugi::xml_document* document = new pugi::xml_document();
			document->load_file(combined.c_str());
			document_list.push_back(document);
		}
	}
	count++;
	its++;
}

void Serializer::OnCreate()
{
}

void Serializer::OnDestroy()
{
}

Serializer* Serializer::GetInstance()
{
	if (instance == nullptr)
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

int Serializer::GenerateRandomNumber()
{
	int random = 0;
	srand(random);
	random = (rand() % INTMAX_MAX) + 1;
	return random;
}

pugi::xml_document* Serializer::DefaultSerialized(std::string tag_)
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
	loadFile(fullpath[1]);
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

bool Serializer::GameObjectExist(int ID_)
{
	if (ID_==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Serializer::loadFile(const char* FileDirectory_)
{

	pugi::xml_parse_result result = CurrentDoc->load_file(FileDirectory_);
	std::cout << "Load results: " << result.description() << std::endl;
	return result;
}



void Serializer::Update()
{
	//if HasFileChange == true or whatever
	//Assign existing ID to existing gameObj
	//if existing GameObj exist and no ID exist make an ID for that existing game object
}

void Serializer::AddGameObject(GameObject* OBJ_) // 
{
	loadFile(fullpath[2]);
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

			CurrentDoc->save_file(fullpath[2], PUGIXML_TEXT(""));
		}
	}
}

void Serializer::AddGameObject(int ID_)
{
	loadFile(fullpath[2]);
}

void Serializer::AssignID(std::list<GameObject*> OBJ_List) //this will only assign ID to object/class that already exist, this will only be called in the beginning of the Engine load
{
	loadFile(fullpath[2]);

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

void Serializer::CreateID(GameObject* OBJ_)
{
	//Lets just make sure that the ID doesn't already exist
	//then assign that ID in our XML file
	int ID;
	for (int i = 0; i<gameObjectIDs.size(); i++)
	{
		//If ID doesn't exist then assign it 
		int temp = gameObjectIDs[i];
		ID = GenerateRandomNumber();
		while (ID==temp)
		{
			ID = GenerateRandomNumber();
		}
	}
	OBJ_->setID(ID);
	gameObjectIDs.push_back(ID);
	
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
void Serializer::RemoveAnimation(std::string tagID_, const char* imageSrc_)
{
}
void Serializer::CreateScene(int currentScene_, const char* sceneName_)
{
	/*I need to load the file if it exist*/
	loadFile(fullpath[1]);
	if (SceneExist(currentScene_, sceneName_) == false)
	{
		if (isChildNodeExist("ScenesInfo") == true)
		{

			auto rootNode = CurrentDoc->child("ScenesInfo");

			auto sceneNode = rootNode.append_child(pugi::node_element);
			sceneNode.set_name("Scene");
			sceneNode.append_attribute("SceneNumber ") = currentScene_;
			sceneNode.append_attribute("SceneName ") = sceneName_;

			CurrentDoc->save_file(fullpath[1], PUGIXML_TEXT(""));
		}
	}
	else
	{
		std::cout << sceneName_ << ": this scene already exist" << std::endl;
	}
}

void Serializer::SaveScene(int currentScene_, Scene& Scenedata_)
{
}

void Serializer::RemoveScene(const char* sceneName)
{
}

void Serializer::DeserializeAnimations()
{
}

void Serializer::DeserializeScenes()
{
}

