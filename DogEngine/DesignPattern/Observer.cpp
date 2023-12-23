#include "Observer.h"
#include "../GameObjects/GameObject.h"

std::list<IObserver*>IObserverable::observerableContainer = std::list<IObserver*>();

GameObserver::GameObserver(GameObject* component_)
{
	Observerable = dynamic_cast<IObserverable*>(component_);
	
}

void GameObserver::DisplayAllMovementComponents()
{
	GameObject* temp;
	if (dynamic_cast<GameObject*>(Observerable))
	{
		temp = dynamic_cast<GameObject*>(Observerable);
		std::cout << "Displaying: " << temp->getName().c_str() << " X and Y Positions" << std::endl;
	//	std::cout << "X: " << temp->getPivotPosition().x << " Y: " << temp->getPivotPosition().y << std::endl;
	}
}

void GameObserver::Update()
{
	DisplayAllMovementComponents();
}


GameObserver::~GameObserver()
{
}

void IObserverable::Remove()
{
	Detach(currentObserver);
}
