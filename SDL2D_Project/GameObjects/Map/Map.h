#ifndef MAP_H
#define MAP_H
#include "../../Game/Game.h"
#include "TileSet/Tiles.h"
#include <list>
#include <vector>
using namespace std;
class TextureManager;

/*Map Layer is basically the whole map or an single layer something like that
right now it's only gonna be a single layer 
*/

class GraphicLayer{

};

class MapLayer
{
private: 
	int colSize;
	int ID;
	map<int, map<int,int>> mapData;
	/* These two X,Y vaules are just defaults*/
	bool IsBackground;
	bool Visible;
	bool mapDataFlag;
	string name;
	SDL_Texture* tex;
	vector<Tiles> tileMap;
	vector<vector<int>>mapRowData;
	vector<int>mapColData;
	vector<vector<int>>prevMapRowData;
	vector<int>prevMapColData;
	int Xsize, Ysize;
	int cols, rows;
	int size;
	int mapStatus;
	// You need to find a way to dynamically Create this arrays Size 
	//I HAVE AN ENUM HERE TO SET THE STANDARD TILE TYPE 
	enum MapSetUp : unsigned short
	{
		DEBUG = 0,
		DEVELOPER,
		ALPHA,
	};
public:
	MapLayer(string name_, int ID_, bool isback_,int Xsize_,int Ysize_);
	void OnRender();
	void OnUpdate();
	void readMapData();
	//Here is a Maplayer that will take in more layeers.
//	MapLayer(string name_, int ID_, bool isback_, int amountOfLayers);
	~MapLayer();

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

