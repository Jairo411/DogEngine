#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H
#include <list>
#include <assert.h>
/*
	2022/8/16  Singleton objectmanager interface. 
	-Handles all gameObjects in engine.
*/
class BaseObj;
class ObjectManager
{
public:
	ObjectManager(const ObjectManager&) = delete;
	ObjectManager(ObjectManager&&) = delete;
	ObjectManager& operator = (const ObjectManager&) = delete;
	ObjectManager& operator = (ObjectManager&&) = delete;
	static ObjectManager* GetInstance();
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
