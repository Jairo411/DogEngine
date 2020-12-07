#include "XML.h"

XML::XML()
{
}

XML::XML(const char* source_)
{
	source = source_;
	doc.load_file(source_);
	// using the xml node is how you traverse your xml file
	mainTag = doc.first_child();
	xml_node tools = mainTag;
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

	
	
	doc.traverse(walker);
	walker.PrintNodeVector();
	setElements(walker);
	std::cout << walker.totalElements << std::endl;
	doc.print(std::cout);
	system("pause");

}

XML::~XML()
{
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

void XML::savefile(int condition_)
{
	switch (condition_)
	{
		//just saves current xml file
		//Currently not working seems like I need to parse it to a string and place it here 
	case 0:
		doc.load_string("");
		break;
		//  This should save the current xml document, then create a new one 
	case 1:

		break;
	default:
		break;
	}
}

void XML::printXML()
{
	doc.print(std::cout);
}

int XML::getTotalAmountOfElements()
{
	return walker.totalElements;
}
