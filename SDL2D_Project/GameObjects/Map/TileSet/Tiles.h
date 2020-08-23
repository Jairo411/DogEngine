#ifndef TILE_H
#define TILE_H
#include <SDL.h>
#include <string>
#include <map>
#include <iostream>
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
	string name;
	string tileSet;
	static map<int, SDL_Texture*> imageSetHolder;
	SDL_Rect srcRect, desRect;
	int ID;
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
	static map<int, SDL_Texture*>GetTileSet();
	static SDL_Texture* getTile(int key_);

	TileSet(TileSet& temp) = delete;
	
	~TileSet();

	//void TestRender();
};

/*This class is setUp I don't think Ill add anymore 
Because everything should be actually made inside the map class*/
class Tiles
{
public:
	//Tileset tileSet;
	Tiles();
	Tiles(SDL_Texture* tex_,int srcX,int srcY,bool solid);
	SDL_Texture* getTex();
	SDL_Rect getSrcRect();
	void OnRender();	
	~Tiles();
private:
	SDL_Texture* baseTex;
	SDL_Rect srcRect,dstRect;
	void OnUpdate();
	void Collider();
	//int sourceX;
	//int sourceY;
	//Modular support 
	int width;
	int Height;
	bool isSoild;

	
};

#endif // !TILE_H