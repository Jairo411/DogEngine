#ifndef XML_H
#define XML_H
#include "XML_parser/pugixml.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include<assert.h>
#include <ctype.h>
#include<type_traits>
#include<cstdint>

std::string const XML_FILE_PATH = "C:/Users/jalbm/source/repos/SDL2D_Project/SDL2D_Project/Game/AI/DecisionTree/XML/";
std::string const XMLExtention = ".xml";

using namespace pugi;

class XML
{
public:
	 XML();
	~XML();
	void createXML();
	void loadXML(const char* source_);
	void addTag(int condition_);
	void removeTag(xml_node* node);
	void printXML();
	xml_node getNode(int index_);
private:
	std::string source;
	std::string docName;
	xml_document docs;
	xml_parse_result res;
	xml_node mainTag;
	xml_node currentNode;

};
#endif
