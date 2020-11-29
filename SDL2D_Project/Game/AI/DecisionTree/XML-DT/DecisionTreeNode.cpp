#include "DecisionTreeNode.h"

DecisionTreeNode::DecisionTreeNode(const char* xml_)
{
	res = doc.load_file(xml_);

	if (res)
	{
		std::cout << "XML [" << xml_ << "] parsed without errors, attr value: [" <<
			doc.child("node").attribute("attr").value() << std::endl;
	}
	else
	{
		std::cout << "XML [" << xml_ << "] parsed with errors, attr value: [" << doc.child("node").attribute("attr").value() << "]\n";
		std::cout << "Error description: " << res.description() << std::endl;
		std::cout << "Error offset: " << res.offset << " (error at [..." << (xml_ + res.offset) << "]\n\n";
	}
	xml_node tools = doc.child("test");
	for (pugi::xml_node tool : doc.child("test").child("Tools").children("Tool"))
	{
		int timeout = tool.attribute("Timeout").as_int();

		if (timeout > 0)
			std::cout << "Tool " << tool.attribute("Filename").value() << " has timeout " << timeout << "\n";
	}
	system("pause");
}

DecisionTreeNode::~DecisionTreeNode()
{
}

//void Decision::testValue()
//{
//}
//
//void Decision::getBranch()
//{
//}
//
//void Action::MakeDecision()
//{
//}
