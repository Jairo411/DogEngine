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
	DecisionTreeNode DTN("C:/Users/jalbm/source/repos/SDL2D_Project/SDL2D_Project/Game/AI/DecisionTree/XML-DT/base AI Decision Tree.xml");
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
		Vec2 lowRange = weightedgraph.at(i).getPosition() + Vec2(-10.0f, -10.0f);
		Vec2 highRange = weightedgraph.at(i).getPosition() + Vec2(10.0f, 0.0f);
		isInRange = Converter::inRange(lowRange, highRange, currentAgent->getPosition());
		if (isInRange)
		{
			weightedgraph.at(i).aStar->priority;
			start = weightedgraph.at(i);
			start.aStar->priority = 0.0f;
			std::cout << "CurrentnavTilePoistion is " << "X: " << start.getGridPosition().x << " Y: " << start.getGridPosition().y << endl;
			return start;
		}
	}

	return NavTile();
}

NavTile* AI::grabNeighbors(NavTile* current_, int index_, std::vector<A_Star_Node_Priority> closedV)
{
	Vec2 DIRECTION = Vec2();
	Vec2 difference;

	switch (index_)
	{
	case 0:
		DIRECTION = Vec2(0.0f, -1.0f); // up
		difference = DIRECTION + current_->getGridPosition();
		break;
	case 1:
		DIRECTION = Vec2(-1.0f, 0.0f); // left
		difference = DIRECTION + current_->getGridPosition();
		break;
	case 2:
		DIRECTION = Vec2(0.0f, 1.0f); // down

		difference = DIRECTION + current_->getGridPosition();
		break;
	case 3:
		DIRECTION = Vec2(1.0f, 0.0f); // right

		difference = DIRECTION + current_->getGridPosition();
		break;
	case 4:
		DIRECTION = Vec2(-1.0f, -1.0f); // up diagonal left

		difference = DIRECTION + current_->getGridPosition();
		break;
	case 5:
		DIRECTION = Vec2(1.0f, -1.0f); // up diagonal right

		difference = DIRECTION + current_->getGridPosition();
		break;
	case 6:
		DIRECTION = Vec2(1.0f, 1.0f);// down diagonal right

		difference = DIRECTION + current_->getGridPosition();
		break;
	case 7:
		DIRECTION = Vec2(-1.0f, 1.0f); // down diagonal left

		difference = DIRECTION + current_->getGridPosition();
		break;
	default:
		break;
	}


	for (int i = 0; i < weightedgraph.size(); i++)
	{
		//if any position in the weighted graph doesn't equal any one of the  neighbor position cases return nothing

		if (weightedgraph.at(i).getGridPosition() == difference)
		{
			return &weightedgraph.at(i);
		}
	}

	return nullptr;

}

void AI::Huristic(NavTile currentNode_, NavTile goalNode_)
{

	Vec2 huristic;

	NavTile originTile = start;
	currentNode_.aStar->priority = 1.0f;

	float g = gVaule(currentNode_);
	float h = max(abs(currentNode_.getGridPosition().x - goalNode_.getGridPosition().x),
		abs(currentNode_.getGridPosition().y - goalNode_.getGridPosition().y));

	currentNode_.f = g + h;
	currentNode_.aStar->priority = currentNode_.f;
//	currentNode_.aStar->print();
}

float AI::gVaule(NavTile distanceFromOrigin_)
{
	NavTile originTile = start;
	float g = max(abs(originTile.getGridPosition().x - goal.getGridPosition().x),
		abs(originTile.getGridPosition().y - goal.getGridPosition().y));
	g += 1.0f;
	return g;
}

void AI::a_starPathFinding(NavTile goal_)
{
	pathFinding = true;
	start = grabOriginTile();
	goal = goal_;
	std::cout << "NavTile goal position is " << "X: " << goal.getGridPosition().x << " Y: " << goal.getGridPosition().y << endl;
	std::priority_queue<A_Star_Node_Priority, std::deque<A_Star_Node_Priority>, ComparePriority> openList;
	std::priority_queue<A_Star_Node_Priority, std::deque<A_Star_Node_Priority>, ComparePriority> closedList;
	std::vector<NavTile> navHolder;
	std::vector<A_Star_Node_Priority> closedV;
	NavTile* currentNode = new NavTile();
	NavTile* otherNode = new NavTile();
	bool flag = false;
	//putting a start Node in the beginning of my list
	currentNode = &start;
	openList.push(*currentNode->aStar);

	while (flag == false)
	{
		if (openList.size() > 0)
		{
			for (int i = 0; i < weightedgraph.size(); i++)
			{
				Node* nodeTograb;
				nodeTograb = openList.top().node;
				if (weightedgraph.at(i).aStar->node == nodeTograb)
				{
					currentNode = &weightedgraph.at(i);
				}
			}
		}

		if (currentNode->n != goal.n)
		{
			//Check all of its neighbors 
			for (int i = 0; i < 8; i++)
			{
				if (closedV.size() == 0)
				{
					otherNode = grabNeighbors(currentNode, i, closedV);
					Huristic(*otherNode, goal_);
					openList.push(*otherNode->aStar);
				}
				else if (closedV.size() > 0)
				{
					for (int j = 0; j < closedV.size(); j++)
					{
						if (currentNode->n != closedV.at(j).node)
						{
							otherNode = grabNeighbors(currentNode, i, closedV);
							Huristic(*otherNode, goal_);
							openList.push(*otherNode->aStar);
						}
					}
				}
			}

			A_Star_Node_Priority c = openList.top();

			closedV.push_back(c);
			closedList.push(c);

			openList.pop();

		}
		else if (currentNode->n == goal.n)
		{
			openList.empty();
			flag = true;
		}
	}

	for (int i = 0; i < closedV.size(); i++)
	{
		for (int j = 0; j < weightedgraph.size(); j++)
		{
			if (weightedgraph.at(j).aStar->node == closedV.at(i).node)
			{
				navHolder.push_back(weightedgraph.at(j));
				closedList.pop();
			}
		}
	}
	
//	std::reverse(std::begin(navHolder),std::end(navHolder));

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

