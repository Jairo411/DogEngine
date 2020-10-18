#include "Map.h"
#include "../../Window/Window.h"
#include "../../TextureManager/TextureManager.h"


MapLayer::MapLayer()
{
	name = "NULL";
	ID = NULL;
	IsBackground = NULL;
	rows = 0;
	cols = 0;
	tileSize = 20;
}

MapLayer::MapLayer(Window* window)
{
	//This is should be the main Constructor
	name = "MapLayer";
	ID = 0;
	tileSize = 20;
	mapStatus = DEVELOPER;
	rows = window->getScreenWidth()/tileSize; //divided by the SDL_rect.w size of my tiles  
	cols = window->getScreenHeight()/tileSize; //divided by the SDL_rect.h size of my tiles 
	screenWidth = window->getScreenWidth();
	screenHeight = window->getScreenHeight();
	cout << "Size of MAP is: " << rows << "," << cols << "" << endl;
	OnBuild(DEBUG); //choose the state through the constuctor 
}


void MapLayer::OnRender()
{
	int total = tileMap.size();
	for (int i = 0; i < total; i++)
	{
		tileMap.at(i).OnRender();
	}
}
/*
okay so this works but you should probably store the values
of the map tiles so that it doesn't have to constantly render
 the tiles through the for loop*/
void MapLayer::OnUpdate(float deltaTime_)
{
	int total = tileMap.size();
	for (int i = 0; i < total; i++)
	{
		//tileMap.at(i).OnRender();
	}
}
/*
okay so this works but you should probably store the values
of the map tiles so that it doesn't have to constantly render
 the tiles through the for loop*/
void MapLayer::OnBuild(int state_)
{
	if (state_ == 0)
	{
		if (mapDataFlag == false)
		{
			TileSet* set = TileSet::GetInstance(); // When you create the UI to select the different types of tile you are going to move this 
			switch (mapStatus)
			{
			case MapLayer::DEBUG:

				for (int i = 0; i < rows; i++)
				{
					for (int j = 0; j < cols; j++)
					{
						int tempR = tileSize * i; //these can be used as the cordiantes that I can used in order to place tiles
						int tempC = tileSize * j;// the space between the rows and the cols should be the same as the size of the colliders and textures in the Tile class

						int index = i + j;

						tex = set->getTile(set->BASETILE); // you don't have to give it is texture information right away.
						Tile::setTileSize(20, 20);
						//This is how you access the Tile Textures Right here;
						tileMap.push_back(Tile(tex, tempR, tempC, true));
						tileMap.at(index).SetID(index);

						/*This is PesudoCode 
						int X = i;
						int Y = j;
						Vec2 temp = covertedScreenCoords(int x,int y);
						tileMap.at(index).setX(temp.getX());
						tileMap.at(index).setY(temp.getY());

						This switches the tiles from screenCoords, to a origin
						that is in the middle
						*/// The Purpose of this is probably I will be able to move these tiles properly during game which could be cool.

						tileMap.at(index).setX(i);
						tileMap.at(index).setY(j);
						 
					}
				}

				break;
			case MapLayer::DEVELOPER:
			{
				for (int i = 0; i < rows; i++)
				{
					for (int j = 0; j < cols; j++)
					{
						int tempR = tileSize * i; //these can be used as the cordiantes that I can used in order to place tiles
						int tempC = tileSize * j;// the space between the rows and the cols should be the same as the size of the colliders and textures in the Tile class

						int index = i + j;

						tex = set->getTile(set->DIRTTILE); // you don't have to give it is texture information right away.
						Tile::setTileSize(20, 20);
						//This is how you access the Tile Textures Right here;
						tileMap.push_back(Tile(tex, tempR, tempC, true));
						tileMap.at(index).SetID(index);
						tileMap.at(index).setX(i);
						tileMap.at(index).setY(j);

						//	mapDataFlag = true;
					}
				}
			}
			break;
			case MapLayer::ALPHA:
				break;

			default:

				break;
			}
		}
	}


}
/* This is will read the mapVector data and tell it
to change the the tilelocation and the texture.*/
void MapLayer::ReadMapData()
{
	int total = tileMap.size();
	for (int i=0; i<total; i++)
	{
	//	tileMap.at(i).OnRender();
	}
}

MapLayer::~MapLayer()
{
	tileMap.empty();
}
