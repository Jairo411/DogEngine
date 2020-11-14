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
class TextureManager; // don't remove this forward delecration things well break
class TileSet
{
public:
	TileSet();
	TileSet(const char* dir_,string name_,int ID_);
	~TileSet();
	void CreateSet(int sizeOfCut_, int srcX_,int srcY_);
	void SetDisplayRects(SDL_Rect tempSrcR_,SDL_Rect tempDesR_);
	void SetBaseImage(SDL_Texture* tempIMG_);
	SDL_Texture* getBaseImage();
	static vector<SDL_Texture*>GetTileSet();
	static SDL_Texture* getTile( int index_);
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
private:
	int ID;
	int width, height;
	string name;
	SDL_Rect srcRect, desRect;
	SDL_Texture* tileSetImage;
	SDL_Texture* baseImage;
	static vector<SDL_Texture*> imageSetHolder;
};

class Tile: public Input
{
public:
	Tile();
	Tile(int srcX_, int srcY_);
	Tile(SDL_Texture* tex_, int srcX, int srcY, bool solid);//Creates Squares tiles but could really create rectangles
	SDL_Texture* getTex();
	SDL_Rect getSrcRect();
	Vec2 getPosition();
	static int getWidth();
	static int getHeight();
	static void setTileSize(int width_, int height_);
	void SetID(int ID_);
	
	Node* getID(int ID_);
	void OnRender();
	void OnUpdate();
	bool KeyBoardInput(int key_);
	bool MouseInput(int key_);
	bool controllerInput(int key_);
	void SetPosition(Vec2 pos_);
	~Tile();
private:
	SDL_Texture* baseTex;
	SDL_Rect srcRect,dstRect;
	RectCollider col;
	Node* n;
	int ID;
	int x, y;
	static int width, height;
	bool isSoild;
};

#endif // !TILE_H
