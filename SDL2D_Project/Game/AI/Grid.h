#ifndef NAVMESH_H
#define NAVMESH_H
#include "../../PriorityQueue/A_Star_Node_Priority.h"
#include "../../Math/Vec2.h"
#include "../../GameObjects/GameObject.h"
#include <vector>
#include<queue>

/* This will be a subclass used by the AI manager */
class Map;
class Tile;

struct NavTile
{
	NavTile() { x = 0; y = 0; };
	~NavTile() {};
	Node *n=nullptr;
	A_Star_Node_Priority *aStar = nullptr;
	std::map<Vec2,bool> neighbors; // Map of neighbors check to see if move is valid and if it has been checked // move is vaild if the Vec2 position is already in the map's key, and boolean is a true or false to see if its been checked
	void setPosition(int x_, int y_);
	void setPosition(Vec2 position_);
	Vec2 getPosition();
private:
	int x, y;
	Vec2 position;
	
};

class Grid
{
public:
	Grid();
	~Grid();
	void BuildMesh(std::vector<Tile*> mapData_);
	std::vector<NavTile> getNavData();
private:
	std::map<Vec2,bool> grabNeighbors(Tile* mapData_);
	std::vector<NavTile> navData;
};

#endif // ! NAVMESH_H