#ifndef NAVMESH_H
#define NAVMESH_H
#define MAXTILES 1250000 //quick math 5 mb is 5000 kilobytes which is 5,000,000 bytes  , 5000,000 bytes divided by 4 is 1,250,000 possible tile positions. (assuming that we are using ints)
#include <glm/glm.hpp>
#include "../../PriorityQueue/A_Star_Node_Priority.h"
#include "../../Math/Vec2.h"
#include "../../GameObjects/GameObject.h"
#include <vector>
#include<queue>

/*2021-07-09
	Looking at this now, it's possible that this way of mapping is okay for now, 
	But knowing how I created it and the state I was in might need to rework this and improve this.*/

struct ComparePriority
{
	bool operator()(A_Star_Node_Priority const& lhs, A_Star_Node_Priority const& rhs)
	{
		return lhs.priority > rhs.priority;
	}
};
class Map;
class Tile;
//this is so bad 
struct NavTile
{
	NavTile() { x = 0; y = 0; };
	~NavTile() {};
	Node *n=nullptr;
	A_Star_Node_Priority *aStar = nullptr;
	vector2 getPosition();
	vector2 getGridPosition();
	 // Map of neighbors check to see if move is valid and if it has been checked // move is vaild if the Vec2 position is already in the map's key, and boolean is a true or false to see if its been checked
	void setPosition(int x_, int y_);
	void setPosition(vector2 position_,vector2 gridPosition_);
	NavTile* giveAddress(A_Star_Node_Priority node);

	float f;
private:
	int x, y;
	vector2 localPosition;
	vector2 gridPosition;
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