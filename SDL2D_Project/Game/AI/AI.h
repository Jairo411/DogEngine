#ifndef AI_H
#define AI_H
#include "../../Math/Vec2.h"
#include "../../Physics/Collider.h"
#include "../../GameObjects/GameObject.h"
#include "../../PriorityQueue/A_Star_Node_Priority.h"
#include <queue>

class Skeleton; // Foward Declaration 
/* AI class is an interface that is meant to be added into GameObjects
	To give them basic AI Functionality and states.*/
	// The AI class is just an intereface that may have some member variables that I might use 

/* Copied Code from Gail Harris 
Created on 2020-Oct-11 */
struct ComparePriority
{
	bool operator()(A_Star_Node_Priority const& lhs, A_Star_Node_Priority const& rhs)
	{
		return lhs.priority > rhs.priority;
	}
};
/* Copied Code from Gail Harris 
Created on 2020-Oct-11 */
class AI
{
public:
	AI();
	virtual ~AI();
	virtual void SetTarget(GameObject* obj_) final;
	virtual void Steer() = 0; 
	virtual void Seperate() = 0; 
	virtual void CreatePriorties() = 0;
	virtual void CheckAgentsDistance() final;
protected:
	bool chaseFlag;
	bool seperateFlag;
	float MaxD;
	float minD;
	float radius;
	Vec2 targetPos;
	GameObject* targetObj; // I should make this private
	CircleCollider circleCol;
	std::priority_queue < A_Star_Node_Priority, std::deque<A_Star_Node_Priority>, ComparePriority> PriorityQueue;
	enum class Enabled
	{
		FALSE = 0,
		TRUE
	};
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
	std::map<GameObject*, Vec2>temp;


};
#endif //AI_H
