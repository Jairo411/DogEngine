#ifndef MAP_H
#define MAP_H
#include "../../Game/Game.h"
#include "TileSet/Tiles.h"
#include "../../Physics/Math/Vec2.h"
#include <list>
#include <vector>

using namespace std;
class TextureManager;

/*Map Layer is basically the whole map or an single layer something like that
right now it's only gonna be a single layer
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
	void OnUpdate();
	int  keyCode;
	//Here is a Maplayer that will take in more layeers.
//	MapLayer(string name_, int ID_, bool isback_, int amountOfLayers);
	~MapLayer();
private:
	int ID;
	/* These two X,Y vaules are just defaults*/
	int Xsize, Ysize;
	int cols, rows;
	int screenWidth, screenHeight;
	int size;
	int mapStatus;
	int tileSize;
	bool IsBackground;
	bool Visible;
	bool mapDataFlag;
	string name;
	SDL_Texture* tex;
	vector<Tile> tileMap;
	map<int, map<int, int>> mapData;
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
