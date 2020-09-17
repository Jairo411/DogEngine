#ifndef TILE_H
#define TILE_H
#include <SDL.h>
#include <string>
#include <map>
#include <iostream>
#include "../../../Physics/Collider.h"
#include "../../../Input/Input.h"
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
class TileSet
{
protected:
	static TileSet* instance;
private:
	int ID;
	string name;
	string tileSet;
	static map<int, SDL_Texture*> imageSetHolder;
	SDL_Rect srcRect, desRect;
	void Init();
	TileSet(string name, int ID);
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
	static map<int, SDL_Texture*>GetTileSet();
	static SDL_Texture* getTile(int key_);
	TileSet(TileSet& temp) = delete;
	~TileSet();
};

/*This class is setUp I don't think Ill add anymore
Because everything should be actually made inside the map class*/
//Honestly could've done this insides the tileClass but this exists so im going to leave it.

class Tile: public Input
{
public:
	Tile();
	Tile(SDL_Texture* tex_,int srcX,int srcY,bool solid);
	SDL_Texture* getTex();
	SDL_Rect getSrcRect();

	static void setTileSize(int width_, int height_);
	static int getWidth();
	static int getHeight();
	void SetID(int ID_);
	void OnRender();
	void OnUpdate();
	int getX();
	int getY();
	bool keyBoardInput(int key_);
	bool mouseInput(int key_);
	bool controllerInput(int key_);
	void setX(int x_);
	void setY(int y_);
	~Tile();
private:
	SDL_Texture* baseTex;
	SDL_Rect srcRect,dstRect;
	Collider col;
	int getID();
	//This are int Variables for the postion of the Tile in the Array not Postion on the screen
	int ID;
	int x, y;
	static int width, height;
	bool isSoild;
};

#endif // !TILE_H
