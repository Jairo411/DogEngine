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

using namespace pugi;

struct simple_walker : xml_tree_walker
{
	const char* node_types[8] =
	{
		"null", "document", "element", "pcdata", "cdata", "comment", "pi", "declaration"
	};

	virtual bool for_each(xml_node& node)
	{
		for (int i = 0; i < depth(); i++) std::cout << "";
		{
			std::cout << node_types[node.type()] << ": name='" << node.name() << "', attribute= " << node.first_attribute().value() << " ' , value='" << node.value() << " '\n";
			if (node_types[node.type()] == "element")
			{
				ElementV.push_back(node);
			}
			else if (node_types[node.type()] == "pcdata")
			{
				pcV.push_back(node);
			}
			totalElements++;
			return true;
		}
	};

	void PrintNodeVector()
	{
		for (int i = 0; i < ElementV.size(); i++)
		{
			if (node_types[ElementV.at(i).type()] == "element")
			{
				std::cout << ElementV.at(i).name();
			}
			else if (node_types[ElementV.at(i).type()] == "pcdata")
			{
				std::cout << ElementV.at(i).value() << std::endl;
			}
			std::cout << std::endl;
		}
	};

	int totalElements = 0;
	std::vector<xml_node> ElementV;
	std::vector<xml_node> pcV;
	//xml_node* currentDataNode;

};

std::string const XML_FILE_PATH = "C:/Users/jalbm/source/repos/SDL2D_Project/SDL2D_Project/Game/AI/DecisionTree/XML/";
std::string const XMLExtention = ".xml";

template <typename T>
std::string ToString(T const& in_val)
{
	return std::to_string(in_val);
}

class XML
{
public:
	XML();
	~XML();
	void createXML(std::string name_); //Creates XML
	void loadXML(const char* source_);
	void addClassNode(const char* name_, const char* ID_);
	/*Both are used to add child elements, overloaded function with the
	1. const char adds a tag with a value inside the brackets < type"object">
	2. second element is a general element <child> elementValue <child>
	*/
	void addChildElement(const char* name_, std::string elementValue_);
	void RemoveClassNode(const char* name_);
	void RemoveChildElement(const char* name_);
	void setElements();
	void savefile();
	void printXML();
	bool checkNode(const char* tagName_);
	std::string deserializeObjectString(int index_);
	std::string deserializeAttribute(int index_);
	template <typename T>
	T getPCdata(int index_)
	{
		int value;
		std::string stringValue;
		stringValue = walker.pcV.at(index_).value();
		return 1;
	}
	int AmountOfNodes();
	xml_node getNode(int index_);
private:
	simple_walker walker;
	std::string source;
	std::string document;
	xml_document doc;
	xml_parse_result res;
	xml_node mainTag;
	xml_node currentNode;

};
#endif 


