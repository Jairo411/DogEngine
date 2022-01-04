#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H
#include <vector>
#include "ResourceAllocator.h"
#include "../DesignPattern/GenericContainer.h"
class ResourceManager
{
public:
	//singleton code
	ResourceManager(const ResourceManager&) = delete;
	ResourceManager(ResourceManager&&) = delete;
	ResourceManager& operator = (const ResourceManager&)=delete;
	ResourceManager& operator = (ResourceManager&&) = delete;
	//actual code
	
	ResourceManager* getInstance();

	///Lets you access the GenericContainerObject 
	GenericContainer* AccessGenericContainer();
private:
	ResourceManager();
	~ResourceManager();
	static ResourceManager* instance;
	GenericContainer* container;
};
#endif //RESOURCEMANAGER_H
