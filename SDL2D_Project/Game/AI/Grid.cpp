#include "Grid.h"
#include "../../GameObjects/Map/Map.h"

Grid::Grid()
{
	navData = std::vector<NavTile>();
}

Grid::~Grid()
{

}

void Grid::BuildMesh(std::vector<Tile*> mapData_)
{
	for (int i = 0; i < mapData_.size(); i++)
	{
		NavTile nt;
		nt = NavTile();
		nt.setPosition(mapData_.at(i)->getPosition());
		nt.n = mapData_.at(i)->getID(i);
		nt.neighbors = grabNeighbors(mapData_.at(i));
	//	nt.aStar = new A_Star_Node_Priority(nt.n, 1.0f);
		navData.push_back(nt);
	}

}

std::vector<NavTile> Grid::getNavData()
{
	return navData;
}

std::map<Vec2,bool> Grid::grabNeighbors(Tile* mapData_)
{
	Vec2 tilePos = mapData_->getPosition();
	Vec2 neighbors;
	std::map<Vec2,bool>neighborspositions;
	for (int i = 0; i < 8; i++)
	{
		switch (i)
		{
		case 0:
			neighbors = Vec2(1.0f, 0.0f); //right
			tilePos = tilePos + neighbors;
			neighborspositions.insert(std::make_pair(tilePos, false));
			break;
		case 1:
			neighbors = Vec2(0.0f, 1.0f); //up
			tilePos = tilePos + neighbors;
			neighborspositions.insert(std::make_pair(tilePos, false));
			break;
		case 2:
			neighbors = Vec2(-1.0f, .0f); //left
			tilePos = tilePos + neighbors;
			neighborspositions.insert(std::make_pair(tilePos, false));
			break;
		case 3:
			neighbors = Vec2(0.0f, -1.0f); //down
			tilePos = tilePos + neighbors;
			neighborspositions.insert(std::make_pair(tilePos, false));
			break;
		case 4:
			neighbors = Vec2(-1.0f, 1.0f); //left diagonal
			tilePos = tilePos + neighbors;
			neighborspositions.insert(std::make_pair(tilePos, false));
			break;
		case 5:
			neighbors = Vec2(1.0f, 1.0f); //right diagonal
			tilePos = tilePos + neighbors;
			neighborspositions.insert(std::make_pair(tilePos, false));
			break;
		case 6:
			neighbors = Vec2(-1.0f, -1.0f); //bottom left diagonal
			tilePos = tilePos + neighbors;
			neighborspositions.insert(std::make_pair(tilePos, false));
		case 7:
			neighbors = Vec2(1.0f, -1.0f); //bottom right diagonal
			tilePos = tilePos + neighbors;
			neighborspositions.insert(std::make_pair(tilePos, false));
			break;
		default:
			break;
		}
	}
	return neighborspositions;
}

void NavTile::setPosition(int x_, int y_)
{
	x = x_;
	y = y_;
	position = Vec2(x, y);
}

void NavTile::setPosition(Vec2 position_)
{
	x = position_.x;
	y = position_.y;
	position = position_;
}

Vec2 NavTile::getPosition()
{
	return position;
}
