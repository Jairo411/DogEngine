#ifndef TILE_H
#define TILE_H
#include <SDL.h>
#include <string>
#include <map>
#include <iostream>
#include "../../../Physics/Collider.h"
#include "../../../Input/Input.h"
#include "../../../PriorityQueue/node.h"
/*
This is the tile class, all IT SHOULD DO IS cut up tile textures and save so they
can be used later.
******************
This should be a singleton because well.
Its a tilemanager and what it does is grab pictures and stores them
We done need any more than one
******************
*/
using namespace std;
class TextureManager;
/* If this is suppose to be a singleton please give it singleton functionality*/
class TileSet
{
public:
	// THE tileSet CLASS WILL ASSIGN THE TYPE OF TILE TO THE ARRAY
	enum ID : unsigned int
	{
		BASETILE = 0,
		DIRTTILE,
		GRASSTILE,
		CAVETILE,
		TILE5,
		TILE6,
		TILE7,
		TILE8
	};
	void operator=(const TileSet&) = delete;
	static TileSet* GetInstance();
	static TileSet* RemoveInstance();
	static vector<SDL_Texture*>GetTileSet();
	static SDL_Texture* getTile(int index_);
	TileSet(TileSet& temp) = delete;
	~TileSet();
private:
	static TileSet* instance;
	int ID;
	string name;
	string tileSet;
	SDL_Rect srcRect, desRect;
	static vector<SDL_Texture*> imageSetHolder;
	void Init();
	TileSet(string name, int ID);
};
struct TileStats
{
	int x, y;
	int labels;
	float prioritiesWeight;
	Node* n;
};
class Tile: public Input
{
public:
	Tile();
	Tile(SDL_Texture* tex_, int srcX, int srcY, bool solid);//Creates Squares tiles but could really create rectangles
	SDL_Texture* getTex();
	SDL_Rect getSrcRect();
	Vec2 getPosition();
	static int getWidth();
	static int getHeight();
	static void setTileSize(int width_, int height_);
	void SetID(int ID_);
	void OnRender();
	void OnUpdate();
	bool KeyBoardInput(int key_);
	bool MouseInput(int key_);
	bool controllerInput(int key_);
	void SetPosition(Vec2 pos_);
	void SetStats(int x_, int y_, int labels_);
	~Tile();
private:
	SDL_Texture* baseTex;
	SDL_Rect srcRect,dstRect;
	RectCollider col;
	TileStats tileDataMap;
	int getID();
	int ID;
	int x, y;
	static int width, height;
	bool isSoild;
};

#endif // !TILE_H
