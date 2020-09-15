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
	WindowPtr = nullptr;
}

MapLayer::MapLayer(string Name_, int ID_, bool isback_,int xSize_, int ySize_)
{
	name = Name_;
	ID = ID_;
	IsBackground = isback_;
	mapStatus = DEVELOPER;
	rows = xSize_;
	cols = ySize_;
	cout << "Size of MAP is: " << rows << "," << cols << "" << endl;

	//TileSet set = TileSet("baseSet", 0); // trying to make this a singleton
	this->Xsize = xSize_;
	this->Ysize = ySize_;
}


void MapLayer::attachWindow(Window* tempWindow_)
{

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
void MapLayer::OnUpdate()
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
void MapLayer::OnUpdate()
{
	if (mapDataFlag==false)
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

					tex = set->getTile(set->DIRTTILE); // you don't have to give it is texture information right away.
					Tile::setTileSize(20, 20);
					//This is how you access the Tile Textures Right here;
					tileMap.push_back(Tile(tex, tempR, tempC, true));
					tileMap.at(index).SetID(index);
					int tempR = 16 * i; //these can be used as the cordiantes that I can used in order to place tiles
					int tempC = 30 * j;

					mapData.insert(make_pair(i,map<int,int>()));
					mapData[i].insert(make_pair(i, j));

					tex = set->getTile(set->DIRTTILE);
					tileMap.push_back(Tiles(tex, tempR, tempC, true));


||||||| 50f9777
=======
					tileMap.at(index).setX(i);
					tileMap.at(index).setY(j);
					int tempR = 16 * i; //these can be used as the cordiantes that I can used in order to place tiles
					int tempC = 30 * j;

					mapData.insert(make_pair(i,map<int,int>()));
					mapData[i].insert(make_pair(i, j));

					tex = set->getTile(set->DIRTTILE);
					tileMap.push_back(Tiles(tex, tempR, tempC, true));


>>>>>>> 48d7615b797d99609e19fadd6cf40cd1ccacf523
					mapDataFlag = true;
				}
			}
			set = TileSet::RemoveInstance();
		}
		break;
		case MapLayer::ALPHA:
			break;

		default:

			break;
		}
	}

	OnRender();
}
/* This is will read the mapVector data and tell it
to change the the tilelocation and the texture.*/
void MapLayer::readMapData()
{
	int total = tileMap.size();
	for (int i=0; i<total; i++)
	{
	for (int i = 0; i < mapColData.size(); i++)
||||||| 50f9777
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
=======
		tileMap.at(i).OnUpdate();
		tileMap.at(i).mouseInput(keyCode);
	for (int i = 0; i < mapColData.size(); i++)
	{
		for  (int j = 0; j < mapRowData[i].size(); j++)
		{
			if (prevMapRowData[i].at(i)!=mapRowData[i].at(i))
			{
				mapDataFlag = true;
			}
		}
>>>>>>> parent of e7eaafc... 2020-08-26 9:35 PM
	}
}

MapLayer::~MapLayer()
{
	tileMap.empty();
}
