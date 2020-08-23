#include "Map.h"
#include "../../TextureManager/TextureManager.h"



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

					mapData.insert(make_pair(i,map<int,int>()));
					mapData[i].insert(make_pair(i, j));

					tex = set->getTile(set->DIRTTILE);
					tileMap.push_back(Tiles(tex, tempR, tempC, true));

					
					
				//	mapColData.push_back(set->DIRTTILE);
				//	mapRowData.push_back(mapColData);
				//	prevMapColData.push_back(set->DIRTTILE);
				//	prevMapRowData.push_back(prevMapColData);
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

	OnRender();
}
/* This is will read the mapVector data and tell it 
to change the the tilelocation and the texture.*/
void MapLayer::readMapData()
{
	for (int i = 0; i < mapColData.size(); i++)
	{
		for  (int j = 0; j < mapRowData[i].size(); j++)
		{
			if (prevMapRowData[i].at(i)!=mapRowData[i].at(i))
			{
				mapDataFlag = true;
			}
		}
	}
}

MapLayer::~MapLayer()
{
	tileMap.empty();
}
