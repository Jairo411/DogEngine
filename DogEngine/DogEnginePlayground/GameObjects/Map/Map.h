#ifndef MAP_H
#define MAP_H
#include <list>
#include <vector>
#include "TileSet/Tiles.h"
#include "../../Window/Window.h" //Remove this 
#include "../../Math/Vec2.h"
#include "../../Math/Converter.h"
///*Map Layer is the background of the game, Currently acting like the actual game map
// but that will chance*/
// /* I either need to build a nav mesh class or extend MapLayer functionality to make this work better, right now I do not know */
//
////the Map struct should only contain pure Map information
//
///*2021-07-09
//	Probably the oldest class I have here that is written, Defienitly going to be reimplemented, to make more sense and generally be a better class
//*/
//class DogEngine;
//
//	struct map
//{
//	int cols, rows;
//	int tileSize;
//};
//
//class MapLayer
//{
//public:
//	MapLayer();
//	MapLayer(Window* window);
//	~MapLayer();
//	void OnBuild(int state_);
//	void Render();
//	void Update(float deltaTime_);
//	std::vector<Tile*> getTiles();
//	static vec2 getGameObjectLocation(vec2 position_);
//private:
//	/* Need to re-look at all these variables
//	   I'm pretty sure I don't use all these variables*/
//	int cols, rows;
//	int screenWidth, screenHeight;
//	int size;
//	int mapStatus;
//	int tileSize;
//	bool IsBackground;
//	bool Visible;
//	std::string name;
//	std::vector<Tile> tileMap;
//	SDL_Texture* tex;
//	vec2 covertedScreenCoords;
//	enum MapSetUp : unsigned short
//	{
//		DEBUG = 0,
//		DEVELOPER,
//		ALPHA,
//	};
//	enum MAPBUILD : unsigned short
//	{
//		DEFAULT = 0,
//		STATE0,
//		STATE1
//	};
//};

#endif // !MAP_H
