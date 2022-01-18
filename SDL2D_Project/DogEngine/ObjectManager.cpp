#include "ObjectManager.h"

ObjectManager* ObjectManager::instance = nullptr;

ObjectManager* ObjectManager::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new ObjectManager();
	}
	return instance;
}

void ObjectManager::Enable(BaseOBJ& args_ ...)
{
}

void ObjectManager::Remove(BaseOBJ& args_ ...)
{
}

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
}
