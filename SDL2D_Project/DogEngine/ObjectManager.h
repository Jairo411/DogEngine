#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H
#include <list>
#include <vector>
#include <tuple>
//This singleton class contains two containers one master list of all gameObjects and the other of all inactive game objects
//Probably want to be able to access object using ID and address.
class BaseOBJ;
class ObjectManager
{
public:
	//Boiler plate singleton code
	ObjectManager(const ObjectManager&) = delete;
	ObjectManager(ObjectManager&&) = delete;
	ObjectManager& operator = (const ObjectManager&) = delete;
	ObjectManager& operator = (ObjectManager&&) = delete;
	static ObjectManager* GetInstance();
	//Boiler plate singleton code
	template <typename T, typename ... Args >
	void AddInactive(Args& ... args_);//template function prototype
	/*Okay so here is the problemand the solution all in one space right here,
	* you've also found the reason for template specialzation the main aspect is you should do 
	* partial template specialization where you can clearly define a part of the template but not the whole template 
	* allowing you to narrow in you generics while keeping part of it abstracted 
	* Here in your code you defined a template function prototype with typename T and typename arguments essentially undefined 
	* then you defined a more specfic template function prototype (here it would be called a template specialization) with typename T being defined 
	* How does the compiler know this? honestly no clue, I just know what im doing works.
	*/
	template <typename T, typename ... Args>
	void AddActive(Args& ... args_); //template function prototype

	template<typename ... Args>
	void AddInactive<BaseOBJ>(Args& ... args_)  //Add inactive objects into the vector
	{
		inactiveObjects.push_back(args_...);
	}
	
	template <typename ... Args>
	void AddActive<BaseOBJ>(Args& ... args_) // add active objects into the list
	{
		Objects.push_back(args_ ...);
	}

	void Remove(BaseOBJ& args_ ...); //Remove objects from both the list and vector in that order 
	void Enable(BaseOBJ& args_ ...); //Remove objects from the vector 

private:
	ObjectManager();
	~ObjectManager();
	static ObjectManager* instance;
	std::vector<BaseOBJ*> inactiveObjects;
	std::list<BaseOBJ*> Objects;
};
#endif // !OBJECTMANAGER_H
