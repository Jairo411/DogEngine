#include "C_RectangleCollider.h"
#include "../GameObject.h"


C_RectangleCollider::C_RectangleCollider(BaseObj* owner) : Component(owner) 
{
	Start();
}

C_RectangleCollider::~C_RectangleCollider()
{
}

void C_RectangleCollider::Start()
{
	position = Vec2(0, 0);
	width = 30;
	height = 30;

	middlepoint = Vec2(width / 2, height / 2);
}

void C_RectangleCollider::Update(float deltatime)
{
	Vec2 newPos;
	newPos = dynamic_cast<GameObject*>(owner)->getPosition();
}

void C_RectangleCollider::Render()
{

}

void C_RectangleCollider::ChangeSize(int width_, int height_)
{
	width = width_;
	height = height_;
}
