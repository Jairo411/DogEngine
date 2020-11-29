#ifndef DECISIONTREENODE_H
#define DECISIONTREENODE_H
#include<string>
#include<iostream>
#include<stdio.h>


#include"XML_parser/pugixml.hpp"

using namespace pugi;

class DecisionTreeNode
{
public:
	DecisionTreeNode(const char* xml_);
	~DecisionTreeNode();
	//virtual void MakeDecision() = 0;
private:
	xml_document doc;
	xml_parse_result res;
	
};

//
//class Action : public DecisionTreeNode
//{
//protected:
//	virtual void MakeDecision();
//};
//
//class Decision : public DecisionTreeNode
//{
//public:
//	void testValue();
//	void getBranch();
//protected:
//	//virtual void MakeDecision();
//};
//
//class FloatDecision : public Decision
//{
//public:
//
//};

#endif // !DECISIONTREENODE_H

