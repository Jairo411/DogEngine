#include "Map.h"
#include "../../Window/Window.h"
#include "../../TextureManager/TextureManager.h"


MapLayer::MapLayer(string Name_, int ID_, bool isback_,int xSize_, int ySize_)
{
	name = Name_;
	ID = ID_;
	IsBackground = isback_;
	mapStatus = DEVELOPER;
	rows = xSize_;
	cols = ySize_;
	WindowPtr = nullptr;
	cout << "Size of MAP is: " << rows << "," << cols << "" << endl;
	
	//TileSet set = TileSet("baseSet", 0); // trying to make this a singleton 
	this->Xsize = xSize_;
	this->Ysize = ySize_;
	OnBuild();
}


void MapLayer::attachWindow(Window* tempWindow_)
{
	WindowPtr = tempWindow_;
	
}

void MapLayer::OnBuild()
{
	if (mapDataFlag == false)
	{
		switch (mapStatus)
		{
		case MapLayer::DEBUG:

			break;
		case MapLayer::DEVELOPER:
		{
			TileSet* set = TileSet::GetInstance();

			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					int tempR = 16 * i; //these can be used as the cordiantes that I can used in order to place tiles 
					int tempC = 30 * j;

					int index = i + j;
					
					tex = set->getTile(set->DIRTTILE);
					//This is how you access the Tile Textures Right here;
					tileMap.push_back(Tiles(tex, tempR, tempC, true));
					tileMap.at(index).SetID(index);
					mapDataFlag = true;
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

/*The Update Function will only read the current Map data and update if it's Changed*/
void MapLayer::OnUpdate() 
{
	/*If I tile has Changed it's positions or texture or blah blah The update will Read the Following MapData*/
	if (mapDataChanged==true)
	{
		for (int i = 0; i < mapData.size(); i++)
		{
			for (int j = 0; j < mapData.at(j).size(); j++)
			{

			}
		}
	}

	
}


MapLayer::~MapLayer()
{
	tileMap.empty();
}
