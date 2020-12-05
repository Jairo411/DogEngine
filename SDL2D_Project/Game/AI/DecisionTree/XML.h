#ifndef XML_H
#define XML_h
#include "XML-DT/XML_parser/pugixml.hpp"
#include <iostream>

using namespace pugi;

class XML
{
public:
	XML(const char* source_);
	~XML();
	//Save Current File as is or create new XML file and save it
	void saveFile(int condition_);
 private:
	xml_document doc;
	xml_parse_result res;
	const char* source;
};
#endif