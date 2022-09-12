#include "TileSetManager.h"
#include "../../../DogEngine/DogEngine.h"
TileSetManager* TileSetManager::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new TileSetManager();
		return instance;
	}
	else
	{
		return instance;
	}
}

TileSetManager::TileSetManager() : index (0) , instance(nullptr)
{
}

TileSetManager::~TileSetManager()
{
}

void TileSetManager::CreateSpriteMap(SpriteMapInfo info)
{
	DogEngine::textureManager->GetInstance()->CreateMapSprite();
}

void TileSetManager::Increment()
{
	index++;
}

void TileSetManager::Decrement()
{
	index--;
}
