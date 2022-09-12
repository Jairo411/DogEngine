#ifndef TILESETMANAGER_H
#define TILESETMANAGER_H
#define MAXSPRITEMAPS_H 200
#include "../../../TextureManager/InfoStructs.h"
class DogEngine;
class TileSetManager
{
public:
	TileSetManager(const TileSetManager&) = delete;
	TileSetManager(TileSetManager& other_) = delete;
	TileSetManager& operator = (const TileSetManager&) = delete;
	TileSetManager& operator = (TileSetManager&) = delete;
	TileSetManager* GetInstance();
	~TileSetManager();

	/// <summary>
	/// Load spriteMap Info create spritemap
	/// </summary>
	/// <param name="info"></param>
	void CreateSpriteMap(SpriteMapInfo info);

private:
	TileSetManager();
	void Increment();
	void Decrement();
	int index;
	TileSetManager* instance;
	SpriteMapInfo maps[MAXSPRITEMAPS_H];
};
#endif // !TILESETMANAGER_H
