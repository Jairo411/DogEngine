#ifndef AI_H
#define AI_H
#include "../../Math/Vec2.h"
#include "../../Physics/Collider.h"
#include "../../GameObjects/GameObject.h"
#include "Grid.h"
#include <queue>
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
	virtual float a_starPathFinding(Vec2 start_, Vec2 goal_ ) final;
	virtual void setWeightedGraph(std::vector<NavTile> weightedgraph_) final;
protected:
	bool chaseFlag;
	bool seperateFlag;
	float MaxD;
	float minD;
	float radius;
	Vec2 targetPos;
	GameObject* targetObj; // I should make this private
	CircleCollider circleCol;
	enum class Enabled
	{
		FALSE = 0,
		TRUE
	};
private:
	NavTile grabOriginTile(GameObject* currentAgent);
	NavTile Huristic(NavTile currentNode_,NavTile otherNode_);
	std::vector<NavTile> weightedgraph;
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
private:
	AIManager() {};
	~AIManager() {};
	AIManager(const AIManager&) = delete;
	AIManager& operator=(const AIManager&) = delete;
	static AIManager* instance;

};
#endif //AI_H
