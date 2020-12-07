#ifndef XML_H
#define XML_H
#include "XML_parser/pugixml.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace pugi;

struct simple_walker : xml_tree_walker
{
	int totalElements = 0;
	std::vector<xml_node> ElementV;
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
			std::cout << ElementV.at(i).first_attribute().as_bool() << std::endl;
		}
	};
	
};
class XML
{
public:
	XML();
	XML(const char * source_);
	~XML();
	void savefile(int condition_);
	void printXML();
	int getTotalAmountOfElements();
	bool checkNode(const char* tagName_);
	std::vector<const char*> getElements();
private:

	std::vector<const char*> setElements(simple_walker walker);
	std::vector<const char*>ElementNames;
	xml_document doc;
	xml_parse_result res;
	xml_node mainTag;
	simple_walker walker;
	const char* source;
};
#endif 
