#include "XML.h"

XML::XML()
{
}

XML::XML(const char* source_,const char* name_)
{
	doc = xml_document();
	std::string fullpath = source_;
	fullpath += name_;
	doc.load_file(source_, parse_default | parse_declaration);
	
	auto declarationNode = doc.append_child(node_declaration);
	declarationNode.append_attribute("version") = "1.0";
	declarationNode.append_attribute("encoding") = "utf-8";

	mainTag = doc.append_child("myroot");
	bool saved = doc.save_file(fullpath.c_str());
	assert(saved);
//	doc.traverse(walker);
	//walker.PrintNodeVector();
	//setElements(walker);
	//std::cout << walker.totalElements << std::endl;
	//doc.print(std::cout);
	//system("pause");


}

XML::~XML()
{
}

void XML::addClassNode(const char* name_,const char* type_)
{

	xml_node classElement;
	/*Creates the element*/
	classElement = mainTag.append_child(name_);
	classElement.append_child(node_pcdata).set_value("");
	/*Assigns a type value inside the element*/
	classElement.append_attribute("type") = type_;	
}

bool XML::checkNode(const char* tagName_)
{
	return false;
}

std::vector<const char*> XML::getElements()
{
	return ElementNames;
}

std::vector<const char*> XML::setElements(simple_walker walker)
{
	for (int i = 0; i < walker.ElementV.size(); i++)
	{
		ElementNames.push_back(walker.ElementV.at(i).name());
	}
	return ElementNames;
}

void XML::addChildElement(const char* name_, std::string elementValue_)
{

	xml_node childElement;
	currentNode = mainTag.last_child();
	/*Creates the element*/
	childElement = currentNode.append_child(name_);
	childElement.set_value(elementValue_.c_str());
}

void XML::savefile()
{
	std::cout << "Saving in directory:  " << source.c_str() << std::endl;
	doc.save_file(source.c_str());
}

void XML::printXML()
{
	doc.print(std::cout);
	doc.traverse(walker);
	walker.PrintNodeVector();
//	std::cout << walker.totalElements << std::endl;
}

int XML::getTotalAmountOfElements()
{
	return walker.totalElements;
}

/* A way to check the xml parsed 
if (res)
	{
		std::cout << "XML [" << source << "] parsed without errors, attr value: [" << doc.child("node").attribute("attr").value() << "]\n\n";
	}
	else
	{
		std::cout << "XML [" << source << "] parsed with errors, attr value: [" << doc.child("node").attribute("attr").value() << "]\n";
		std::cout << "Error description: " << res.description() << "\n";
		std::cout << "Error offset: " << res.offset << " (error at [..." << (source + res.offset) << "]\n\n";
	}
*/