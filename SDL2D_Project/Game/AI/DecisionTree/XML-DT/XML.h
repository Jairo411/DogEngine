#ifndef XML_H
#define XML_H
#include "XML_parser/pugixml.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include<assert.h>

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
			std::cout << node_types[node.type()] << ": name='" << node.name() << " ' , value='" << node.value() << " '\n";
			if (node_types[node.type()] == "element")
			{
				ElementV.push_back(node);
				totalElements++;
			}
			return true;
		}
	};


	void PrintNodeVector()
	{
		for (int i = 0; i < ElementV.size(); i++)
		{
			std::cout << ElementV.at(i).name() << std::endl;
			std::cout << ElementV.at(i).value() << std::endl;
		}
	};

	int totalElements = 0;
	std::vector<xml_node> ElementV;
	//xml_node* currentDataNode;

};

template <typename T>
std::string ToString(T const& in_val)
{
	return std::to_string(in_val);
}

class XML
{
public:
	XML();
	XML(const char* source_, const char* name_);
	~XML();
	void addClassNode(const char* name_, const char* type_);
	/*Both are used to add child elements, overloaded function with the 
	1. const char adds a tag with a value inside the brackets < type"object">
	2. second element is a general element <child> elementValue <child>
	*/
	void RemoveClassNode();
	void addChildElement(const char* name_, const char* type_);
	void addChildElement(const char* name_, std::string elementValue_);
	void RemoveChildElement();

	void savefile();
	void printXML();
	int getTotalAmountOfElements();
	bool checkNode(const char* tagName_);
	std::vector<const char*> getElements();
private:
	std::vector<const char*> setElements(simple_walker walker);
	std::vector<const char*>ElementNames;
	std::string source;
	xml_document doc;
	xml_parse_result res;
	xml_node mainTag;
	xml_node currentNode;
	simple_walker walker;

};
#endif 
