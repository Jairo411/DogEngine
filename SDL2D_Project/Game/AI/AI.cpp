#include "AI.h"

AIManager* AIManager::instance = nullptr;
std::vector<GameObject*> AIManager::AIAgentContainer = std::vector<GameObject*>();


AI::AI()
{
	MaxD = 1000;
	minD = 100;
}

AI::~AI()
{
	/* Over here you should handle all the pointers in your AI Class */
}

void AI::SetTarget(GameObject* obj_)
{
	/* I should Just get the refence to the object*/
	
		if (targetObj == nullptr)
		{
			targetObj = obj_;
		}
}


void AI::CheckAgentsDistance()
{
	
}

NavTile AI::grabOriginTile(GameObject* currentAgent)
{
	return NavTile();
}

NavTile AI::Huristic(NavTile currentNode_, NavTile otherNode_)
{
	Vec2 huristic;
	//float movementCost = currentNode_.aStar->priority;
	float distantFromOrigin;
	
	
	return NavTile();
}

float AI::a_starPathFinding(Vec2 start_, Vec2 goal_)
{
	//std::priority_queue<A_Star_Node_Priority, std::deque<A_Star_Node_Priority>, ComparePriority> openList;
	//std::priority_queue<A_Star_Node_Priority, std::deque<A_Star_Node_Priority>, ComparePriority> closedList;
	//std::vector<NavTile>::iterator it;


	//for (int i = 0; i < weightedgraph.size(); i++)
	//{
	//	openList.push(*weightedgraph.at(i).aStar);
	//}
	//while (!openList.empty())
	//{
	//	Node *currentN = new Node();
	//	
	//	int i = 0; // counter
	//	for (it = weightedgraph.begin(); it < weightedgraph.end(); it++ , i++)
	//	{
	//		if (weightedgraph.at(i).getPosition()==goal_)
	//		{

	//		}
	//	}
	//}
	return 0.0f;
}

void AI::setWeightedGraph(std::vector<NavTile> weightedgraph_)
{
	weightedgraph = weightedgraph_;
}



/*Need to pass this some sort of like AI stats in order for it to run properly.
	this funciton will not be called every update. It will be triggered 
*/
std::map<GameObject*,Vec2> AIManager::getClosestDistanceBetweenAgents()
{
	std::vector<GameObject*> Agents;
	std::map<GameObject*,bool> checkAgentPosition;
	std::map<GameObject*, Vec2> newAgentDistance;
	std::vector<Vec2>positionsV;
	std::vector<Vec2>distanceV;
	Vec2 originPosition;

	if (AIAgentContainer.size() > 0)
	{
		for (int i = 0; i < AIAgentContainer.size(); i++)
		{
			Agents.push_back(AIAgentContainer.at(i)); //reference to the gameObjects i.e Agents
			checkAgentPosition.insert(std::make_pair(Agents.at(i),false)); // A map to see if positions are being checked
		}
		for (int i = 0; i < AIAgentContainer.size(); i++)
		{
			for (auto const& [key, val] : checkAgentPosition) // Same as the AI_AgentContainer, but this is way easier to write 
			{
				checkAgentPosition.at(Agents.at(i)) = true; //current Agent position is being checked
				if (val == true) // if key is false, position gets added to a vector
				{
					originPosition = key->getPosition();
				}
				if (val == false)
				{
					positionsV.push_back(key->getPosition());
				}
			}
			Vec2 distance; 
			for (int i = 0; i < positionsV.size(); i++)
			{
				distance = originPosition - positionsV.at(i);
			//	std::cout << "Mag: " << distance.GetMag()<<std::endl;
				if (distance.GetMag() < 70.0f)
				{
					newAgentDistance.insert(std::make_pair(AIAgentContainer.at(i), AIAgentContainer.at(i)->getPosition())); 
					std::cout << "Agents are close to each other" << std::endl;
				}
			}
			for (int i = 0; i < Agents.size(); i++)
			{
				checkAgentPosition.at(Agents.at(i)) = false;
			}
			positionsV.clear();
			}
		return newAgentDistance;
		}
	return std::map<GameObject*, Vec2>();
	}
	


AIManager* AIManager::getInstance()
{
	if (instance==nullptr)
	{
		instance = new AIManager();
	}
	return instance;
}

AIManager* AIManager::removeInstance()
{
	if (instance !=nullptr)
	{
		instance = nullptr;
	}
	return instance;
}

void AIManager::getTotalAgents()
{
	for (int i = 0; i < GameObject::ObjHolder.size(); i++)
	{
		GameObject* tempPtr = GameObject::ObjHolder.at(i);
		if (dynamic_cast<AI*>(tempPtr))
		{
			AIAgentContainer.push_back(tempPtr);
		}
	}
	std::cout << "Total amount of Agents: " << AIAgentContainer.size() << std::endl;
}

// so over here the AI manager updates any GameObject in my AIAgentContainer that has an AI interface
void AIManager::OnUpdate(float deltaTime)
{
	for (int i = 0; i<AIAgentContainer.size() ;i++)
	{
		dynamic_cast<AI*>(AIAgentContainer.at(i))->Steer();
		dynamic_cast<AI*>(AIAgentContainer.at(i))->Seperate();
		
	}
}

