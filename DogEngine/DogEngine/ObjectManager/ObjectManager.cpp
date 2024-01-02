#include "ObjectManager.h"
#include "../GameObjects/Object.h"

ObjectManager* ObjectManager::instance = nullptr;

ObjectManager* ObjectManager::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new ObjectManager();
	}
	return instance;
}

void ObjectManager::AddInActive(BaseObj* obj_)
{
	if (obj_->IsEnable()==true)
	{
		obj_->setEnable(false);
		activeObjects.remove(obj_);
	}
	inactiveObjects.push_back(obj_);
}

void ObjectManager::AddActive(BaseObj* obj_)
{
	activeObjects.push_back(obj_);
}

void ObjectManager::Remove(BaseObj* obj_)
{
	if (obj_->IsEnable()==false)
	{
		inactiveObjects.remove(obj_);
	}
	else if (obj_->IsEnable()==true)
	{
		activeObjects.remove(obj_);
	}
}

void ObjectManager::Enable(BaseObj* obj_)
{
	obj_->setEnable(true);
	inactiveObjects.remove(obj_);
	activeObjects.push_back(obj_);
}

void ObjectManager::Update(float deltaTime_)
{
	for (std::list<BaseObj*>::iterator it = activeObjects.begin(); it != activeObjects.end(); it++)
	{
		dynamic_cast<BaseObj*>(*it)->Update(deltaTime_);
	}
}

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
}
