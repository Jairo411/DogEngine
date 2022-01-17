#include "ResourceManager.h"

ResourceManager* ResourceManager::instance = nullptr;
ResourceManager* ResourceManager::GetInstance()
{
	if (instance==nullptr)
	{
		instance = new ResourceManager();
	}
	return instance;
}

GenericContainer* ResourceManager::AccessGenericContainer()
{
    return container;
}

ResourceManager::ResourceManager()
{

}

ResourceManager::~ResourceManager()
{
}
