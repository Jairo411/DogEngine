#ifndef MAP_H
#define MAP_H
#include "TileSet/Tiles.h"
#include "../../Game/Game.h"
#include "../../Physics/Math/Vec2.h"
#include <list>
#include <vector>

using namespace std;
class TextureManager;

/*Map Layer is the game map, Takes in the Window class I made, 
takes the screen width and height. Then displays the tiles from 0,0 to the final coordinate.
have the Other classes in order to move functionality.
*/

class GraphicLayer{

};

class Window;
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
	int Xsize, Ysize;
	int cols, rows;
	int screenWidth, screenHeight;
	int size;
	int mapStatus;
	int tileSize;
	bool IsBackground;
	bool Visible;
	bool mapDataFlag;
	std::string name;
	SDL_Texture* tex;
	std::vector<Tile> tileMap;
	std::map<int, map<int, int>> mapData;
	Vec2 covertedScreenCoords;
	// You need to find a way to dynamically Create this arrays Size
	//I HAVE AN ENUM HERE TO SET THE STANDARD TILE TYPE
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
private:

public:
	GameMap();
	~GameMap();
};

class GameMapEditor
{
public:
	GameMapEditor();
	~GameMapEditor();
};
#endif // !MAP_H
