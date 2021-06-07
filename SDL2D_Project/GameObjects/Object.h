#ifndef OBJECT_H
#define OBJECT_H
#include <iostream>
#include <map>
// I should use this class to move over more generic ID stuff*/
class BaseObj
{
public:
	BaseObj() {}
	virtual ~BaseObj() {}
protected:
	std::string tag;
	std::string name; 
	std::map <std::string, std::string> components; 
};
#endif
