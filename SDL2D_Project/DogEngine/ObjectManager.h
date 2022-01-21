#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H
#include <list>
#include <assert.h>
//This singleton class contains two containers one master list of all gameObjects and the other of all inactive game objects
//Probably want to be able to access object using ID and address. Also maybe name as well.
/*
* The Manager can be nofitied when an object has be enable
*/
class BaseObj;
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
	void AddInActive(BaseObj* obj_);
	void AddActive(BaseObj* obj_);
	void Remove(BaseObj* obj_);
	void Enable(BaseObj* obj_);
	void Update(float deltaTime_);
private:
	ObjectManager();
	~ObjectManager();
	static ObjectManager* instance;
	std::list<BaseObj*> activeObjects;
	std::list<BaseObj*> inactiveObjects;
};
#endif //!OBJECTMANAGER_H
