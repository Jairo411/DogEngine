#include "XML.h"

XML::XML(const char* source_)
{
	source = source_;
	res = doc.load_file(source_);
	
	//How to select a xml tag then inside select the child 
	xml_node tools = doc.child("decisionTree").child("false");

	if (res==false)
	{
		std::cout << "XML [" << source_ << "] parsed with errors, attr value: [" << doc.child("node").attribute("attr").value() << "]\n";
		std::cout << "Error description: " << res.description() << std::endl;
		std::cout << "Error offset: " << res.offset << " (error at [..." << (source_ + res.offset) << "]\n\n";
	}
	
	xml_node node = doc.append_child("node");

	//add description node with text child
	xml_node description = node.append_child("description");
	description.append_child(node_pcdata).set_value("simple node");


	// add param node before the description 
	xml_node param = node.insert_child_before("param", description);

	// add attributes to param node
	param.append_attribute("name") = "version";
	param.append_attribute("value") = 1.1;
	param.insert_attribute_after("type", param.attribute("name")) = "float";


	// how to write inside the file
	tools.append_child(node_pcdata).set_value("This is a test");



	doc.print(std::cout);
	system("pause");
}

XML::~XML()
{
}

void XML::saveFile(int condition_)
{
	switch (condition_)
	{
	
	case 0:
		doc.save_file(source);

	default:
		break;
	}
}
