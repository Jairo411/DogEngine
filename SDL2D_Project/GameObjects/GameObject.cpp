#include "GameObject.h"

GameObject::GameObject()
{
	transform = Transform2D();

	this->AddComponent<Transform2D>(transform);
}

GameObject::~GameObject()
{
}

void GameObject::UpdatePostion()
{
	
}

void GameObject::setPosition(int x_, int y_)
{
	vector2 tempVec = vector2();
	tempVec.x = (float)x_;
	tempVec.y = (float)y_;
}

void GameObject::setPosition(vector2 position_)
{
	position = position_;
}

vector2 GameObject::getPivotPosition()
{
	return this->pivotPosition;
}

vector2 GameObject::getPosition()
{
	return position;
}



