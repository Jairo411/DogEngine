#ifndef TILE_H
#define TILE_H
#define MAXTILES 1250000 //quick math 5 mb is 5000 kilobytes which is 5,000,000 bytes  , 5000,000 bytes divided by 4 is 1,250,000 possible tile positions. (assuming that we are using ints.) 
#include <SDL.h>
#include <string>
#include <map>
#include <iostream>
#include <glm/glm.hpp>
//NEW 
#include "../../../GameObjects/GameObject.h"
#include "../../../Components/C_Sprite.h"
#include "../../../Components/C_2DTransform.h"
#include "../../../Components/C_RectangleCollider.h"
#include "../../../../DogEngine/DogEngineDefinitions.h"
//OLD 
//#include "../../../EventSystem/Event.h"
//#include "../../../PriorityQueue/node.h"

/*
This is the tile class, all IT SHOULD DO IS cut up tile textures and save so they
can be used later.
******************
This should be a singleton because well.
Its a tilemanager and what it does is grab pictures and stores them
We done need any more than one
******************
*/
//The dog engine should be here instead.
/*
* This needs to removed 
*/

class DogEngine;
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
}; //remove this 
//reconstruct this.
class TileSetManagerr
{
public:
	TileSetManagerr(const TileSetManagerr&) = delete;
	TileSetManagerr(TileSetManagerr& other_) = delete;
	TileSetManagerr& operator = (const TileSetManagerr&) = delete;
	TileSetManagerr& operator = (TileSetManagerr&) = delete;
	TileSetManagerr* GetInstance();
	///Remove all this code. 
	TileSetManagerr(const char* dir_,std::string name_, int ID_);

	void CreateSet(int sizeOfCut_, int srcX_,int srcY_);
	void SetDisplayRects(SDL_Rect tempSrcR_,SDL_Rect tempDesR_);
	void SetBaseImage(SDL_Texture* tempIMG_);
	SDL_Texture* getBaseImage();
private:
	TileSetManagerr();
	~TileSetManagerr();
	TileSetManagerr* instance;
	int ID;
	int width, height;
	std::string name;
	SDL_Rect srcRect, desRect;
	SDL_Texture* tileSetImage;
	SDL_Texture* baseImage;
};
//Tile represents a single tile in the window 
class TILE : public GameObject
{
public:
	TILE();
	~TILE();
	virtual void OnCreate() final;
	virtual void OnDestroy() final;
	virtual void Update(float deltaTime_) final;
	virtual void Render() final;
private:
	C_RectangleCollider* collider;
	C_Sprite* sprite;
	C_Transform2D* transform;
};
//GridPosition represents a group of tiles inside the grid.
class GridPosition : public GameObject
{
public:
	GridPosition();
	~GridPosition();
	virtual void OnCreate() final;
	virtual void OnDestroy() final;
	virtual void Update(float deltaTime_) final;
	virtual void Render() final;
private:
	TILE tiles[MAXTILES];
};

//Keep this as a reference
//class Tile
//{
//public:
//	Tile();
//	Tile(int srcX_, int srcY_);
//	Tile(SDL_Texture* tex_, int srcX, int srcY, bool solid);
//	SDL_Texture* getTex();
//	SDL_Rect getSrcRect();
//	vec2 getPosition();
//	vec2 getGridPosition();
//	static int getWidth();
//	static int getHeight();
//	static void setTileSize(int width_, int height_);
//	void SetID(int ID_);
//	Node* getID(int ID_);
//	void Render();
//	void Update(float deltaTime_);
//	void SetPosition(vec2 pos_);
//	void setGridPosition(vec2 pos_);
//	~Tile();
//private:
//	SDL_Texture* baseTex;
//	SDL_Rect srcRect;
//	SDL_Rect dstRect;
//	vec2 GridPosition;
//	Node* n;
//	int ID;
//	int x, y;
//	static int width, height;
//	bool isSoild;
//};
#endif // !TILE_H
