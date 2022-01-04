#include "ResourceManager.h"

ResourceManager* ResourceManager::getInstance()
{
    return instance;
}

GenericContainer* ResourceManager::AccessGenericContainer()
{
    return container;
}

ResourceManager::~ResourceManager()
{
}
