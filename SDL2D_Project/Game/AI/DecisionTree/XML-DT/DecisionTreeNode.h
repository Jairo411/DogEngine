#ifndef DECISIONTREENODE_H
#define DECISIONTREENODE_H
#include<string>
#include<iostream>
#include<stdio.h>
#include "../XML-DT/XML.h"

using namespace pugi;

class DecisionTreeNode
{
public:
	DecisionTreeNode();
	DecisionTreeNode(XML xmlFile_);
	~DecisionTreeNode();
	virtual DecisionTreeNode MakeDecision() = 0;
protected:
	XML xml_DecisionTree;
};


class Action : public DecisionTreeNode
{
public:
	Action();
	~Action();
	void SetAction(std::string action_);
private:
	std::string actionType;
protected:
//	virtual DecisionTreeNode MakeDecision();
};

class Decision : public DecisionTreeNode
{
public:
	Decision();
	~Decision();
protected:
	virtual void testValue();
	virtual void getBranch();
//	virtual DecisionTreeNode MakeDecision();
	DecisionTreeNode* falseNode;
	DecisionTreeNode* trueNode;
};
class BoolDecision : public Decision
{
public:
	void testValue();
	void getBranch();
};

#endif // !DECISIONTREENODE_H

