#ifndef OBJECT_H
#define OBJECT_H
#include <iostream>
#include <map>
/* I should use this class to move over more generic ID stuff*/
class Object
{
public:
	Object();
	virtual ~Object()=0;
protected:
	std::string tag;
	std::string name; 
	std::map <std::string, std::string> components; 
};
#endif
