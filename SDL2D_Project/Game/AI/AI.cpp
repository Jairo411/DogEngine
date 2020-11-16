#include "AI.h"

AIManager* AIManager::instance = nullptr;
std::vector<GameObject*> AIManager::AIAgentContainer = std::vector<GameObject*>();


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

	GameObject* currentAgent = dynamic_cast<GameObject*>(this);
	bool isInRange = false;
	for (int i = 0; i < weightedgraph.size(); i++)
	{
		Vec2 lowRange = weightedgraph.at(i).getPosition() + Vec2(-200.0f, -200.0f);
		Vec2 highRange = weightedgraph.at(i).getPosition() + Vec2(40.0f, 40.0f);
		isInRange = Converter::inRange(lowRange, highRange, currentAgent->getPosition());
		if (isInRange)
		{
			weightedgraph.at(i).aStar->priority;
			start = weightedgraph.at(i);
			start.aStar->priority = 0.0f;
			std::cout << "CurrentnavTilePoistion is " << "X: " << start.getPosition().x << " Y: " << start.getPosition().y;
			return start;
		}
	}

	return NavTile();
}

NavTile* AI::grabNeighbors(NavTile* current_, int index_)
{
	NavTile neighbors;
	Vec2 DIRECTION = Vec2();
	Vec2 difference;
	switch (index_)
	{
	case 0:
		DIRECTION = Vec2(0.0f, -1.0f); // up
		neighbors.setPosition(DIRECTION);
		difference = neighbors.getPosition() + current_->getPosition();
		break;
	case 1:
		DIRECTION = Vec2(-1.0f, 0.0f); // left
		neighbors.setPosition(difference);
		difference = neighbors.getPosition() + current_->getPosition();
		break;
	case 2:
		DIRECTION = Vec2(0.0f, 1.0f); // down
		neighbors.setPosition(difference);
		difference = neighbors.getPosition() + current_->getPosition();
		break;
	case 3:
		DIRECTION = Vec2(1.0f, 0.0f); // right
		neighbors.setPosition(difference);
		difference = neighbors.getPosition() + current_->getPosition();
		break;
	case 4:
		DIRECTION = Vec2(-1.0f, -1.0f); // up diagonal left
		neighbors.setPosition(difference);
		difference = neighbors.getPosition() + current_->getPosition();
		break;
	case 5:
		DIRECTION = Vec2(1.0f, -1.0f); // up diagonal right
		neighbors.setPosition(difference);
		difference = neighbors.getPosition() + current_->getPosition();
		break;
	case 6:
		DIRECTION = Vec2(1.0f, 1.0f);// down diagonal right
		neighbors.setPosition(difference);
		difference = neighbors.getPosition() + current_->getPosition();
		break;
	case 7:
		DIRECTION = Vec2(-1.0f, 1.0f); // down diagonal left
		neighbors.setPosition(difference);
		difference = neighbors.getPosition() + current_->getPosition();
		break;
	default:
		break;
	}

	for (int i = 0; i < weightedgraph.size(); i++)
	{
		//if any position in the weighted graph doesn't equal any one of the  neighbor position cases return nothing
		if (weightedgraph.at(i).getPosition() == neighbors.getPosition())
		{
			return &neighbors;
		}
	}

	return nullptr;

}

void AI::Huristic(NavTile currentNode_, NavTile goalNode_)
{
	Vec2 huristic;

	NavTile originTile = start;

	float g = originTile.aStar->priority + currentNode_.aStar->priority;
	float h = max(abs(currentNode_.getPosition().x - goalNode_.getPosition().x),
		abs(currentNode_.getPosition().y - goalNode_.getPosition().y));
	float f = g + h;

	currentNode_.aStar->priority = f;

}

void AI::a_starPathFinding(NavTile goal_)
{
	pathFinding = true;
	start = grabOriginTile();
	goal = goal_;
	std::priority_queue<A_Star_Node_Priority, std::deque<A_Star_Node_Priority>, ComparePriority> openList;
	std::priority_queue<A_Star_Node_Priority, std::deque<A_Star_Node_Priority>, ComparePriority> closedList;
	std::vector<NavTile> navHolder;
	NavTile* currentNode = new NavTile();
	NavTile* otherNode = new NavTile();

	currentNode = &start;

	/*Push everything from the weighted graph into the OpenList*/
	for (int i = 0; i < weightedgraph.size(); i++)
	{
		A_Star_Node_Priority currentNode =*weightedgraph.at(i).aStar;
		openList.push(currentNode);
	}
	while (!openList.empty())
	{
		if (currentNode == &goal_)
		{
			break;
		}
		currentNode = currentNode->giveAddress(openList.top());
		for (int i = 0; i < 8; i++)
		{
			otherNode = grabNeighbors(currentNode, i);
			// my way of saying if the move is invaild 
			if (otherNode != nullptr)
			{
				Huristic(*otherNode, goal_);
			}
		}
		//once you have checked all neighbours pop off the current node
		A_Star_Node_Priority c = openList.top();
		c.print();
		closedList.push(c);
		openList.pop();
	}
	for (int i = 0; i < weightedgraph.size(); i++)
	{
		if (weightedgraph.at(i).aStar == &closedList.top())
		{
			navHolder.push_back(weightedgraph.at(i));
		}
		closedList.pop();
	}

	path = navHolder;
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
std::map<GameObject*, Vec2> AIManager::getClosestDistanceBetweenAgents()
{
	std::vector<GameObject*> Agents;
	std::map<GameObject*, bool> checkAgentPosition;
	std::map<GameObject*, Vec2> newAgentDistance;
	std::vector<Vec2>positionsV;
	std::vector<Vec2>distanceV;
	Vec2 originPosition;

	if (AIAgentContainer.size() > 0)
	{
		for (int i = 0; i < AIAgentContainer.size(); i++)
		{
			Agents.push_back(AIAgentContainer.at(i)); //reference to the gameObjects i.e Agents
			checkAgentPosition.insert(std::make_pair(Agents.at(i), false)); // A map to see if positions are being checked
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

void AIManager::setPath(AI* agent_, std::vector<Tile*> mapData_,int goal_)
{
	Grid grid = Grid();
	NavTile goal; 
	grid.BuildMesh(mapData_);
	agent_->setWeightedGraph(grid.getNavData());
	goal= agent_->getNavTileAt(goal_);
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
	for (int i = 0; i < AIAgentContainer.size(); i++)
	{
		dynamic_cast<AI*>(AIAgentContainer.at(i))->Steer();
		dynamic_cast<AI*>(AIAgentContainer.at(i))->Seperate();

	}
}

