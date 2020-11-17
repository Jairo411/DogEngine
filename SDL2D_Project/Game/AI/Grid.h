#ifndef NAVMESH_H
#define NAVMESH_H
#include "../../PriorityQueue/A_Star_Node_Priority.h"
#include "../../Math/Vec2.h"
#include "../../GameObjects/GameObject.h"
#include <vector>
#include<queue>

struct ComparePriority
{
	bool operator()(A_Star_Node_Priority const& lhs, A_Star_Node_Priority const& rhs)
	{
		return lhs.priority > rhs.priority;
	}
};

/* This will be a subclass used by the AI manager */
class Map;
class Tile;

struct NavTile
{
	NavTile() { x = 0; y = 0; };
	~NavTile() {};
	Node *n=nullptr;
	A_Star_Node_Priority *aStar = nullptr;
	Vec2 getPosition();
	Vec2 getGridPosition();
	 // Map of neighbors check to see if move is valid and if it has been checked // move is vaild if the Vec2 position is already in the map's key, and boolean is a true or false to see if its been checked
	void setPosition(int x_, int y_);
	void setPosition(Vec2 position_,Vec2 gridPosition_);
	NavTile* giveAddress(A_Star_Node_Priority node);

	float f;
private:
	int x, y;
	Vec2 localPosition;
	Vec2 gridPosition;
};

class Grid
{
public:
	Grid();
	~Grid();
	void BuildMesh(std::vector<Tile*> mapData_);
	std::vector<NavTile> getNavData();
private:

	std::vector<NavTile> navData;
};

#endif // ! NAVMESH_H