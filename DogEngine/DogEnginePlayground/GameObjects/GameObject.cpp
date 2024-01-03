#include "GameObject.h"

GameObject::GameObject()
{
	transform = C_Transform2D();

	this->AddComponent<C_Transform2D>(transform);
}

GameObject::~GameObject()
{
}

void GameObject::UpdatePostion()
{
	
}

void GameObject::setPosition(int x_, int y_)
{
	DGEngine::core::vector2 tempVec = DGEngine::core::vector2();
	tempVec.x = (float)x_;
	tempVec.y = (float)y_;
}

void GameObject::setPosition(DGEngine::core::vector2 position_)
{
	position = position_;
}

DGEngine::core::vector2 GameObject::getPivotPosition()
{
	return this->pivotPosition;
}

DGEngine::core::vector2 GameObject::getPosition()
{
	return position;
}



