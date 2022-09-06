#ifndef OBJECT_H
#define OBJECT_H
#include <iostream>
#include <map>
#include "../Components/Component.h"
// I should use this class to move over more generic ID stuff*/
/*2021-07-09
	This class is fine
	Add component functionality to the class,
	where a component will update,render and or create itself.
	*/
class BaseObj
{
public:
	BaseObj() { indexLocation = 0; ID = 0; isEnabled = true; typeReference = nullptr; }
	virtual ~BaseObj() {}
	virtual void OnCreate()=0;
	virtual void OnDestroy()=0;
	virtual void Update(float deltaTime_)=0;
	virtual void Render()=0;
	void setID(int ID_) { ID = ID_; }
	void setIndexLocation(int index_) { indexLocation = index_; }
	void setEnable(bool flag_) { isEnabled = flag_; }
	void* getTypeReference() { return typeReference; }
	bool IsEnable() { return isEnabled; }
	int getID() { return ID; }
	int getIndexLocation() { return indexLocation; }
	std::string getNameIdentifier() {	return nameIdentifier; }
	std::string getClassName() { return className; }
	std::string getName() { return name; }
protected:
	std::string nameIdentifier; // will be used in Editor
	std::string className; //The Actual class name 
	std::string name; //an subjective string variable that you assign what ever name; 
	std::map <std::string, std::string> componentData; 
	void* typeReference;
private: 
	bool isEnabled;
	int indexLocation;// Localtion within my LargeStorage container of all my gameObjects
	int ID; // unique Identifyer 
};
#endif
