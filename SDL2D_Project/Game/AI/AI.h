#ifndef AI_H
#define AI_H
#include "../../Math/Vec2.h"
#include "../../Math/Converter.h"
#include "../../Physics/Collider.h"
#include "../../GameObjects/GameObject.h"
#include "Grid.h"
#include <minmax.h>
#include <queue>
#include <algorithm>
/* AI class is an interface that is meant to be added into GameObjects
	To give them basic AI Functionality and states.*/
	// The AI class is just an intereface that may have some member variables that I might use 
class AI
{
public:
	AI();
	virtual ~AI();
	virtual void SetTarget(GameObject* obj_) final;
	virtual void Steer() = 0; 
	virtual void Seperate() = 0; 
	virtual void CheckAgentsDistance() final;
	virtual void a_starPathFinding(NavTile goal_ ) final;
	virtual void setWeightedGraph(std::vector<NavTile> weightedgraph_) final;
	virtual NavTile getNavTileAt(int index_);
protected:
	bool chaseFlag;
	bool seperateFlag;
	bool pathFinding;
	int  indexPath;
	float MaxD;
	float minD;
	float radius;
	Vec2 targetPos;
	GameObject* targetObj; // I should make this private
	RectCollider navCollider;
	CircleCollider circleCol;
	std::vector<NavTile> path;
private:
	NavTile grabOriginTile();
	NavTile* grabNeighbors(NavTile* current_, int index_,std::vector<A_Star_Node_Priority> closedlist_);
	void Huristic(NavTile currentNode_,NavTile goalNode_);
	float gVaule(NavTile distanceFromOrigin_);
	std::vector<NavTile> weightedgraph;
	NavTile start, goal;
};

class AIManager
{
public:
	static AIManager* getInstance();
	static AIManager* removeInstance();
	void getTotalAgents();
	void OnUpdate(float deltaTime);
	static std::vector<GameObject*> AIAgentContainer;
	static std::map<GameObject*, Vec2> getClosestDistanceBetweenAgents();
	void setPath(AI* agents_, std::vector<Tile*> mapData ,int goal_);
	
private:
	AIManager() {};
	~AIManager() {};
	AIManager(const AIManager&) = delete;
	AIManager& operator=(const AIManager&) = delete;
	static AIManager* instance;

};
#endif //AI_H
