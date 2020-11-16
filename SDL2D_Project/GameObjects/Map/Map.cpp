#include "Map.h"

MapLayer::MapLayer()
{
	name = "NULL";
	IsBackground = NULL;
	Visible = NULL;
	rows = 0;
	cols = 0;
	tileSize = 20;
}

MapLayer::MapLayer(Window* window)
{
	//This is should be the main Constructor
	name = "MapLayer";
	tileSize = 32;
	mapStatus = DEVELOPER;
	rows = window->getScreenWidth() / tileSize; //divided by the SDL_rect.w size of my tiles  
	cols = window->getScreenHeight() / tileSize; //divided by the SDL_rect.h size of my tiles 
	screenWidth = window->getScreenWidth();
	screenHeight = window->getScreenHeight();
	SDL_Rect srcRect, desRect;
	srcRect.w = 32;
	srcRect.h = 32;
	desRect.w = srcRect.w;
	desRect.h = srcRect.h;
	set0 = TileSet("./Assets/Level Sprites/Foreground/template8x6.png", "DeveloperMap", 0);
	set0.SetDisplayRects(srcRect, desRect);
	set0.CreateSet(64, desRect.w, desRect.h);
	cout << "Size of MAP is: " << rows << "," << cols << "" << endl;
	OnBuild(DEBUG); //choose the state through the constuctor 
	std::cout << "X: " << tileMap.at(22).getPosition().x << "Y: " << tileMap.at(22).getPosition().y << std::endl;
	std::cout << "X: " << tileMap.at(21).getPosition().x << "Y: " << tileMap.at(21).getPosition().y << std::endl;
}


void MapLayer::OnRender()
{
	for (int i = 0; i < tileMap.size(); i++)
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

}

std::vector<Tile*> MapLayer::getTiles()
{
	std::vector<Tile*> ptr;
	Tile* currentTile =nullptr;
	for ( int i = 0; i < tileMap.size(); i++)
	{
		currentTile=&tileMap.at(i);
		ptr.push_back(currentTile);
	}
	return ptr;
}

Vec2 MapLayer::getGameObjectLocation(Vec2 position_)
{
	/*Compare this to your tilePosition*/
	Vec2 newPosition;
	newPosition = Converter::GetMiddleOfSquare(position_);
	return newPosition;
}



/*okay so this works but you should probably store the values
of the map tiles so that it doesn't have to constantly render
 the tiles through the for loop*/
void MapLayer::OnBuild(int state_)
{
	int index = 0;
	if (state_ == 0)
	{

		switch (mapStatus)
		{
		case MapLayer::DEBUG:
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					int tempR = tileSize * i; //these can be used as the cordiantes that I can used in order to place tiles
					int tempC = tileSize * j;// the space between the rows and the cols should be the same as the size of the colliders and textures in the Tile class

					tex = TileSet::getTile(0); // you don't have to give it is texture information right away.
					//This is how you access the Tile Textures Right here;
					Tile::setTileSize(32, 32);
					tileMap.push_back(Tile(tex, tempR, tempC, true));
					Vec2 position = Vec2(tempR, tempC);
					Vec2 gridPosition = Vec2(i, j);
					tileMap.at(index).SetID(index);
					tileMap.at(index).SetPosition(position);
					tileMap.at(index).setGridPosition(gridPosition);
					std::cout << " Tile label ID: ";
					tileMap.at(index).getID(index)->print();
					index++;
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

					tex = TileSet::getTile(0); // you don't have to give it is texture information right away.
					//This is how you access the Tile Textures Right here;
					Tile::setTileSize(32, 32);
					tileMap.push_back(Tile(tex, tempR, tempC, true));
					Vec2 position = Vec2(tempR, tempC);
					Vec2 gridPosition = Vec2(i, j);
					tileMap.at(index).SetID(index);
					tileMap.at(index).SetPosition(position);
					tileMap.at(index).setGridPosition(gridPosition);
					std::cout << " Tile label ID: ";
					tileMap.at(index).getID(index)->print();
					index++;
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
/* This is will read the mapVector data and tell it
to change the the tilelocation and the texture.*/

MapLayer::~MapLayer()
{
	tileMap.empty();
}

