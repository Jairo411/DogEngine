#include "Collider.h"
#include "../Game/Game.h"

Collider::Collider()
{
	x = 0;
	y = 0;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = 0;
	srcRect.h = 0;
	
	area = 0;
	collisonObjectType = CollisonObjectType::NONE;
	collisonType = CollisonType::NO_COl;
}

Collider::Collider(int x_, int y_,int size_)
{
	x = x_;
	y = y_;

	area = x * y;

	
	collisonObjectType = CollisonObjectType::NONE;
	collisonType = CollisonType::NO_COl;

	srcRect.x = x;
	srcRect.y = y;

	srcRect.w = size_;
	srcRect.h = size_;

}

Collider::Collider(int d_)
{

}

void Collider::CollisonUpdate(int colPosX,int colPosY)
{
	/*This is needs to worked out and actually thought out .*/
	int xPos, yPos;

	xPos = x + colPosX;
	yPos = y + colPosY;


	srcRect.x = xPos;
	srcRect.y = yPos;


	switch (collisonObjectType)
	{
	case Collider::NONE:
		switch (collisonType)
		{
		case Collider::NO_COl:
			break;
		case Collider::Game_COL:
			break;
		case Collider::Projectile_COL:
			break;
		}
		break;
	case Collider::GAMEOBJECT:
		switch (collisonType)
		{
		case Collider::NO_COl:
			break;
		case Collider::Game_COL:
			break;
		case Collider::Projectile_COL:
			break;
		}
		break;
	}
}

void Collider::CollisonRender()
{
	SDL_SetRenderDrawColor(Game::renderer, 33, 191, 75, 0);
	SDL_RenderDrawRect(Game::renderer, &srcRect);
	SDL_SetRenderDrawColor(Game::renderer, 225, 225, 225, 255);
}
	

void Collider::SetCollisonObjectType(int col_)
{
	collisonObjectType = col_;
}

void Collider::SetCollisonType(int col_)
{
	collisonType = col_;
}

void Collider::MouseEventListener(int event)
{
	
}

SDL_Rect* Collider::getCollider()
{
	return &srcRect;
}



Collider::~Collider()
{

}


