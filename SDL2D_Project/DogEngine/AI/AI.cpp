#include "AI.h"

AIManager* AIManager::instance = nullptr;
std::list<GameObject*> AIManager::AIAgentList = std::list<GameObject*>();


AI::AI()
{
	MaxD = 1000;
	minD = 100;
	chaseFlag = false;
	seperateFlag = false;
	pathFinding = false;
	radius = 0;
	indexPath = 0;
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

/* will grab the tile closest to the AI Object and set it as the starting position*/
NavTile AI::grabOriginTile()
{

	//GameObject* currentAgent = dynamic_cast<GameObject*>(this);
	//bool isInRange = false;
	//for (int i = 0; i < weightedgraph.size(); i++)
	//{
	//	vec2 lowRange = weightedgraph.at(i).getPosition() + vec2(-10.0f, -10.0f);
	//	vec2 highRange = weightedgraph.at(i).getPosition() + vec2(10.0f, 0.0f);
	//	isInRange = Converter::inRange(lowRange, highRange, currentAgent->getPivotPosition());
	//	if (isInRange)
	//	{
	//		weightedgraph.at(i).aStar->priority;
	//		start = weightedgraph.at(i);
	//		start.aStar->priority = 0.0f;
	//		std::cout << "CurrentnavTilePoistion is " << "X: " << start.getGridPosition().x << " Y: " << start.getGridPosition().y << std::endl;
	//		return start;
	//	}
	//}

	return NavTile();
}

NavTile* AI::grabNeighbors(NavTile* current_, int index_, std::vector<A_Star_Node_Priority> closedV)
{
	//vec2 DIRECTION = vec2();
	//vec2 difference;

	//switch (index_)
	//{
	//case 0:
	//	DIRECTION = vec2(0.0f, -1.0f); // up
	//	difference = DIRECTION + current_->getGridPosition();
	//	break;
	//case 1:
	//	DIRECTION = vec2(-1.0f, 0.0f); // left
	//	difference = DIRECTION + current_->getGridPosition();
	//	break;
	//case 2:
	//	DIRECTION = vec2(0.0f, 1.0f); // down

	//	difference = DIRECTION + current_->getGridPosition();
	//	break;
	//case 3:
	//	DIRECTION = vec2(1.0f, 0.0f); // right

	//	difference = DIRECTION + current_->getGridPosition();
	//	break;
	//case 4:
	//	DIRECTION = vec2(-1.0f, -1.0f); // up diagonal left

	//	difference = DIRECTION + current_->getGridPosition();
	//	break;
	//case 5:
	//	DIRECTION = vec2(1.0f, -1.0f); // up diagonal right

	//	difference = DIRECTION + current_->getGridPosition();
	//	break;
	//case 6:
	//	DIRECTION = vec2(1.0f, 1.0f);// down diagonal right

	//	difference = DIRECTION + current_->getGridPosition();
	//	break;
	//case 7:
	//	DIRECTION = vec2(-1.0f, 1.0f); // down diagonal left

	//	difference = DIRECTION + current_->getGridPosition();
	//	break;
	//default:
	//	break;
	//}


	//for (int i = 0; i < weightedgraph.size(); i++)
	//{
	//	//if any position in the weighted graph doesn't equal any one of the  neighbor position cases return nothing

	//	if (weightedgraph.at(i).getGridPosition() == difference)
	//	{
	//		return &weightedgraph.at(i);
	//	}
	//}

	return nullptr;

}

void AI::Huristic(NavTile currentNode_, NavTile goalNode_)
{

	//vec2 huristic;

	//NavTile originTile = start;
	//currentNode_.aStar->priority = 1.0f;

	//float g = gVaule(currentNode_);
	//float h = max(abs(currentNode_.getGridPosition().x - goalNode_.getGridPosition().x),
	//	abs(currentNode_.getGridPosition().y - goalNode_.getGridPosition().y));

	//currentNode_.f = g + h;
	//currentNode_.aStar->priority = currentNode_.f;

}

float AI::gVaule(NavTile distanceFromOrigin_)
{
	/*NavTile originTile = start;
	float g = max(abs(originTile.getGridPosition().x - goal.getGridPosition().x),
		abs(originTile.getGridPosition().y - goal.getGridPosition().y));
	g += 1.0f;
	return g;*/

	return 0.0f;
}

void AI::a_starPathFinding(NavTile goal_)
{
//	pathFinding = true;
//	start = grabOriginTile();
//	goal = goal_;
//	std::cout << "NavTile goal position is " << "X: " << goal.getGridPosition().x << " Y: " << goal.getGridPosition().y << std::endl;
//	std::priority_queue<A_Star_Node_Priority, std::deque<A_Star_Node_Priority>, ComparePriority> openList;
//	std::priority_queue<A_Star_Node_Priority, std::deque<A_Star_Node_Priority>, ComparePriority> closedList;
//	std::vector<NavTile> navHolder;
//	std::vector<A_Star_Node_Priority> closedNode;
//	NavTile* currentTile = new NavTile();
//	NavTile* otherTile = new NavTile();
//	bool flag = false;
//	//putting a start Node in the beginning of my list
//	currentTile = &start;
//	openList.push(*currentTile->aStar);
//
//	while (flag == false)
//	{
//		if (openList.size() > 0)
//		{
//			for (int i = 0; i < weightedgraph.size(); i++)
//			{
//				Node* nodeTograb;
//				nodeTograb = openList.top().node;
//				if (weightedgraph.at(i).aStar->node == nodeTograb)
//				{
//					currentTile = &weightedgraph.at(i);
//				}
//			}
//		}
//
//		if (currentTile->n != goal.n)
//		{
//			//Check all of its neighbors 
//			for (int i = 0; i < 8; i++)
//			{
//				if (closedNode.size() == 0)
//				{
//					otherTile = grabNeighbors(currentTile, i, closedNode);
//					Huristic(*otherTile, goal_);
//					openList.push(*otherTile->aStar);
//				}
//				else if (closedNode.size() > 0)
//				{
//					for (int j = 0; j < closedNode.size(); j++)
//					{
//						if (currentTile->n != closedNode.at(j).node)
//						{
//							otherTile = grabNeighbors(currentTile, i, closedNode);
//							Huristic(*otherTile, goal_);
//							openList.push(*otherTile->aStar);
//						}
//					}
//				}
//			}
//
//			A_Star_Node_Priority c = openList.top();
//
//			closedNode.push_back(c);
//			closedList.push(c);
//
//			openList.pop();
//
//		}
//		else if (currentTile->n == goal.n)
//		{
//			///Warning C4834
//			(void*)openList.empty();
//			flag = true;
//		}
//	}
//
//	for (int i = 0; i < closedNode.size(); i++)
//	{
//		for (int j = 0; j < weightedgraph.size(); j++)
//		{
//			if (weightedgraph.at(j).aStar->node == closedNode.at(i).node)
//			{
//				navHolder.push_back(weightedgraph.at(j));
//				closedList.pop();
//			}
//		}
//	}
//	
////	std::reverse(std::begin(navHolder),std::end(navHolder));
//
//	path = navHolder;
}

void AI::setWeightedGraph(std::vector<NavTile> weightedgraph_)
{
	weightedgraph = weightedgraph_;
}

NavTile AI::getNavTileAt(int index_)
{
	return weightedgraph.at(index_);
}



/*Need to pass this some sort of like AI stats in order for it to run properly.
	this funciton will not be called every update. It will be triggered
*/
std::map<GameObject*, vector2> AIManager::getClosestDistanceBetweenAgents()
{
	//std::vector<GameObject*> Agents;
	//std::vector<GameObject*>::iterator agentsIt;
	//std::map<GameObject*, bool> checkAgentPosition;
	//std::map<GameObject*, vec2> newAgentDistance;
	//std::vector<vec2>positionsV;
	//std::vector<vec2>distanceV;
	//vec2 originPosition;

	////if (AIAgentContainer.size() > 0)
	////{
	////	for (int i = 0; i < AIAgentContainer.size(); i++)
	////	{
	////		Agents.push_back(AIAgentContainer.at(i)); //reference to the gameObjects i.e Agents
	////		checkAgentPosition.insert(std::make_pair(Agents.at(i), false)); // A map to see if positions are being checked
	////	}
	////	for (int i = 0; i < AIAgentContainer.size(); i++)
	////	{
	////		for (auto const& [key, val] : checkAgentPosition) // Same as the AI_AgentContainer, but this is way easier to write 
	////		{
	////			checkAgentPosition.at(Agents.at(i)) = true; //current Agent position is being checked
	////			if (val == true) // if key is false, position gets added to a vector
	////			{
	////				originPosition = key->getPosition();
	////			}
	////			if (val == false)
	////			{
	////				positionsV.push_back(key->getPosition());
	////			}
	////		}
	////		Vec2 distance;
	////		for (int i = 0; i < positionsV.size(); i++)
	////		{
	////			distance = originPosition - positionsV.at(i);
	////			//	std::cout << "Mag: " << distance.GetMag()<<std::endl;
	////			if (distance.GetMag() < 70.0f)
	////			{
	////				newAgentDistance.insert(std::make_pair(AIAgentContainer.at(i), AIAgentContainer.at(i)->getPosition()));
	////				std::cout << "Agents are close to each other" << std::endl;
	////			}
	////		}
	////		for (int i = 0; i < Agents.size(); i++)
	////		{
	////			checkAgentPosition.at(Agents.at(i)) = false;
	////		}
	////		positionsV.clear();
	////	}
	////	return newAgentDistance;
	////}
	////return std::map<GameObject*, Vec2>();

	//if (AIAgentList.size()>0)
	//{
	//	agentsIt = Agents.begin();
	//	for (auto it = AIAgentList.begin(); it!=AIAgentList.end(); it++)
	//	{
	//		Agents.push_back(*it);
	//		checkAgentPosition.insert(std::make_pair(*agentsIt,false));
	//		agentsIt++;
	//	}
	//	for (auto it = AIAgentList.begin(); it != AIAgentList.end(); it++)
	//	{
	//		for (auto const& [key, val] : checkAgentPosition)
	//		{
	//			checkAgentPosition.at(*it) = true;
	//			if (val == true)
	//			{
	//				originPosition = key->getPivotPosition();
	//			}
	//			else if (val == false)
	//			{
	//				positionsV.push_back(key->getPivotPosition());
	//			}
	//		}
	//	}
	//	agentsIt = Agents.begin();
	//	vec2 distance;
	//	vec2 position;
	//	std::list<GameObject*>::iterator listIterator;
	//	for (int i = 0; i < positionsV.size(); i++)
	//	{
	//		distance = originPosition - positionsV.at(i);
	//		position = dynamic_cast<GameObject*>(*listIterator)->getPivotPosition();
	//		if (distance.GetMag() < 70.0f)
	//		{
	//			newAgentDistance.insert(std::make_pair(*listIterator, position));
	//			std::cout << "Agents are close to each other" << std::endl;
	//			listIterator++;
	//		}
	//	}
	//	for (auto it = AIAgentList.begin(); it!= AIAgentList.end(); it++);
	//	{
	//		checkAgentPosition.at(*agentsIt) = false;
	//	}
	//	positionsV.clear();
	//	return newAgentDistance;
	//}
	//else 
	//{
	//	return std::map<GameObject*, vec2>();
	//}

return std::map<GameObject*, vector2>();
}

void AIManager::setPath(AI* agent_, std::vector<Tile*> mapData_, int goal_)
{
	Grid grid = Grid();
	NavTile goal;
	grid.BuildMesh(mapData_);
	agent_->setWeightedGraph(grid.getNavData());
	goal = agent_->getNavTileAt(goal_);
	agent_->a_starPathFinding(goal);
}



AIManager* AIManager::getInstance()
{
	if (instance == nullptr)
	{
		instance = new AIManager();
	}
	return instance;
}

AIManager* AIManager::removeInstance()
{
	if (instance != nullptr)
	{
		instance = nullptr;
	}
	return instance;
}

void AIManager::getTotalAgents()
{
	//for ( auto it = GameObject::OBJHolder.begin(); it!=GameObject::OBJHolder.end(); it++)
	//{
	//	if (dynamic_cast<AI*>(*it))
	//	{
	//		AIAgentList.push_back(*it);
	//	}
	//}

	////for (int i = 0; i < GameObject::OBJHolder.size(); i++)
	////{
	////	GameObject* tempPtr = GameObject::
	////	if (dynamic_cast<AI*>(tempPtr))
	////	{
	////		AIAgentContainer.push_back(tempPtr);
	////	}
	////}
	////std::cout << "Total amount of Agents: " << AIAgentContainer.size() << std::endl;

	//std::cout << "Total amount of Agents: " << AIAgentList.size() << std::endl;
}

// so over here the AI manager updates any GameObject in my AIAgentContainer that has an AI interface
void AIManager::OnUpdate(float deltaTime)
{
	///OLD 
	//for (int i = 0; i < AIAgentContainer.size(); i++)
	//{
	//	dynamic_cast<AI*>(AIAgentContainer.at(i))->Steer();
	//	dynamic_cast<AI*>(AIAgentContainer.at(i))->Seperate();

	//}
	///NEW
	for (auto it = AIAgentList.begin(); it!= AIAgentList.end(); it++)
	{
		dynamic_cast<AI*>(*it)->Steer();
		dynamic_cast<AI*>(*it)->Seperate();
	}
}

