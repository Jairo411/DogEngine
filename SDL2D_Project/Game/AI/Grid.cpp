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
	    nt.aStar = new A_Star_Node_Priority(nt.n, FLT_MAX);
		navData.push_back(nt);
	}
}

std::vector<NavTile> Grid::getNavData()
{
	return navData;
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

NavTile* NavTile::giveAddress(A_Star_Node_Priority node)
{
	A_Star_Node_Priority* ptr = &node;
	if (ptr->node==this->n)
	{

		return this;
	}
}



Vec2 NavTile::getPosition()
{
	return position;
}
