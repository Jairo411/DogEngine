#include "XML.h"

XML::XML()
{
	/* Null Verison of creating an xml */
	source = std::string();
	document = std::string();
	doc = xml_document();
	mainTag = xml_node();
	currentNode = xml_node();
	

}

XML::~XML()
{
}

void XML::createXML(std::string name_)
{
	document = XML_FILE_PATH + name_;
	document += XMLExtention;
	doc = xml_document();
	xml_node node = doc.append_child(pugi::node_declaration);
	node.append_attribute("version") = "1.0";
	node.append_attribute("encoding") = "UTF-8";
	mainTag = doc.append_child("ROOT");
	mainTag.append_child(node_pcdata);
	doc.save_file(document.c_str());
}

void XML::loadXML(const char* source_)
{
	doc.load_file(source_);

	mainTag = doc.first_child();

	if (res)
	{
		std::cout << "XML [" << source << "] parsed without errors, attr value: [" << doc.child("node").attribute("attr").value() << "]\n\n";
	}
	else
	{
		std::cout << "XML [" << source << "] parsed with errors, attr value: [" << doc.child("node").attribute("attr").value() << "]\n";
		std::cout << "Error description: " << res.description() << "\n";
		//	std::cout << "Error offset: " << res.offset << " (error at [..." << (source + res.offset) << "]\n\n";
	}

}


void XML::addClassNode(const char* name_, const char* ID_)
{

	xml_node classElement;
	/*Creates the element*/
	classElement = mainTag.append_child(name_);
	classElement.append_child(node_pcdata).set_value("");
	/*Assigns a type value inside the element*/
	classElement.append_attribute("ID").set_value(ID_);
}

bool XML::checkNode(const char* tagName_)
{
	return false;
}

std::string XML::deserializeObjectString(int index_)
{
	std::string objectName = walker.ElementV.at(index_).name();
	return objectName;
}

std::string XML::deserializeAttribute(int index_)
{
	std::string attribute = walker.ElementV.at(index_).first_attribute().value();
	return attribute;
}

int XML::AmountOfNodes()
{
	return walker.ElementV.size();
}

xml_node XML::getNode(int index_)
{
	return walker.ElementV.at(index_);
}



void XML::setElements()
{
	doc.traverse(walker);
}

void XML::addChildElement(const char* name_, std::string elementValue_)
{

	xml_node childElement;
	currentNode = mainTag.last_child();
	/*Creates the element*/
	childElement = currentNode.append_child(name_);
	childElement.append_child(node_pcdata).set_value(elementValue_.c_str());
}

void XML::RemoveClassNode(const char* name_)
{
	xml_node removeClassNode;
	removeClassNode = mainTag.child(name_);
	removeClassNode.remove_child(name_);
}

void XML::RemoveChildElement(const char* name_)
{
	xml_node removeChildElement;
	removeChildElement = mainTag.last_child();
	removeChildElement.remove_child(name_);
}


void XML::savefile()
{
	std::cout << "Saving in directory:  " << source.c_str() << std::endl;
	doc.save_file(source.c_str());
}

void XML::printXML()
{
	doc.print(std::cout);
	walker.PrintNodeVector();
}
