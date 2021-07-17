#ifndef OBJECT_H
#define OBJECT_H
#include <iostream>
#include <map>
// I should use this class to move over more generic ID stuff*/
/*2021-07-09
	This class is fine*/
#include "Component/Component.h"
class BaseObj
{
public:
	BaseObj() {}
	virtual ~BaseObj() {}
	virtual void Start()=0;
	virtual void OnUpdate(float deltaTime_)=0;
	virtual void OnRender()=0;
protected:
	std::string tag;
	std::string name; 
	std::map <std::string, std::string> components; 
};
#endif
