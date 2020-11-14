#ifndef MAP_H
#define MAP_H
#include "TileSet/Tiles.h"
#include "../../Game/Game.h"
#include "../../Window/Window.h"
#include "../../Math/Vec2.h"
#include "../../Math/Converter.h"
#include <list>
#include <vector>

/*Map Layer is the background of the game, Currently acting like the actual game map
 but that will chance*/
 /* I either need to build a nav mesh class or extend MapLayer functionality to make this work better, right now I do not know */

class MapLayer
{
public:
	MapLayer();
	MapLayer(Window* window);
	~MapLayer();
	void OnBuild(int state_);
	void OnRender();
	void OnUpdate(float deltaTime_);
	std::vector<Tile> getTiles();
	static Vec2 getGameObjectLocation(Vec2 position_);
private:
	/* Need to re-look at all these variables
	   I'm pretty sure I don't use all these variables*/
	int cols, rows;
	int screenWidth, screenHeight;
	int size;
	int mapStatus;
	int tileSize;
	bool IsBackground;
	bool Visible;
	std::string name;
	std::vector<Tile> tileMap;
	SDL_Texture* tex;
	Vec2 covertedScreenCoords;
	TileSet set0;
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

#endif // !MAP_H
