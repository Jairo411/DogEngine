#ifndef OBJECT_H
#define OBJECT_H
#include <iostream>
#include <map>
// I should use this class to move over more generic ID stuff*/
/*2021-07-09
	This class is fine
	Add component functionality to the class,
	where a component will update,render and or create itself.
	*/
#include "Component/Component.h"
class BaseObj
{
public:
	BaseObj() {}
	virtual ~BaseObj() {}
	virtual void OnCreate()=0;
	virtual void OnDestroy()=0;
	virtual void Update(float deltaTime_)=0;
	virtual void fixedUpdate(float deltaTime)=0;
	virtual void Render()=0;
	std::string getName() {	return name; }
protected:
	std::string name; // will be used in Editor
	std::map <std::string, std::string> components; 
};
#endif
