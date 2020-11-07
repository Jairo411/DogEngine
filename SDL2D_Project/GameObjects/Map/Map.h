#ifndef MAP_H
#define MAP_H
#include "TileSet/Tiles.h"
#include "../../Game/Game.h"
#include "../../Window/Window.h"
#include "../../TextureManager/TextureManager.h"
#include "../../Math/Vec2.h"
#include <list>
#include <vector>

/*Map Layer is the game map, Takes in the Window class I made, 
takes the screen width and height. Then displays the tiles from 0,0 to the final coordinate.
have the Other classes in order to move functionality.
*/



class MapLayer
{
public:
	MapLayer();
	MapLayer(Window* window);
	void OnBuild(int state_);
	void ReadMapData();
	void OnRender();
	void OnUpdate(float deltaTime_);
	int  keyCode;
	~MapLayer();
private:
	/* Need to re-look at all these variables 
	   I'm pretty sure I don't use all these variables*/
	int ID;
	int cols, rows;
	int screenWidth, screenHeight;
	int size;
	int mapStatus;
	int tileSize;
	bool IsBackground;
	bool Visible;
	bool mapDataFlag;
	std::string name;
	std::vector<Tile> tileMap;
	SDL_Texture* tex;
	Vec2 covertedScreenCoords;
	enum MapSetUp : unsigned short
	{
		DEBUG = 0,
		DEVELOPER,
		ALPHA,
	};
	enum MAPBUILD : unsigned short
	{
		DEFAULT = 0,
		STATE0,
		STATE1
	};
};

class GameMap {
public:
	GameMap(MapLayer mapData_);
	~GameMap();
private:
	MapLayer MapData;
};

#endif // !MAP_H
