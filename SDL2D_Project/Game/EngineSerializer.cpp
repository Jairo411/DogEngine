#include "EngineSerializer.h"

EngineSerializer::EngineSerializer()
{
	auto declarationNode = doc.append_child(pugi::node_declaration);
	declarationNode.append_attribute("version") = 1.0;
	declarationNode.append_attribute("encoding") = "ISO-8859-1";
	auto rootNode = doc.append_child("Root").append_child(pugi::node_pcdata); //node_pcdata is the data of the node it closes the tag for you 

	
	std::string const path = "C:/Users/jalbm/source/repos/SDL2D_Project/SDL2D_Project/BaseXML.xml";


	bool save = doc.save_file(path.c_str(), PUGIXML_TEXT(" "));

}

EngineSerializer::~EngineSerializer()
{
}

void EngineSerializer::CreateScene(int currentScene_)
{
	/* You can used this to check to see if files exist then add them into your engine 
	* 
	struct stat status;
	if (stat(SerializedScenePath.c_str(),&status)!=0)
	{
		std::cout << "This file doesn't exist";
	}*/

	auto delcartionNode = doc.append_child(pugi::node_declaration);
	delcartionNode.append_attribute("version") = 1.0;
	delcartionNode.append_attribute("encoding") = "ISO-8859-1"; // <--What is this ????? look it up 
	auto rootNode = doc.append_child("Scene").append_attribute("currentSceneNumber") = currentScene_;

}
