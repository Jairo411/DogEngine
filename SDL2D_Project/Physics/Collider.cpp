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
	collisonObjectType = NONE  ;
	collisonType = NONE;
}

Collider::Collider(int x_, int y_,int size_)
{
	x = x_;
	y = y_;
	area = x * y;
	
	collisonObjectType = ColiderObject::NONE;
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

	x = colPosX;
	y = colPosY;

	srcRect.x = x;
	srcRect.y = y;


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
	//SDL_SetRenderDrawColor(Game::renderer, 225, 225, 225, 255);
	SDL_RenderDrawRect(Game::renderer, &srcRect);
	SDL_SetRenderDrawColor(Game::renderer, 33, 191, 75, 0);
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
	switch (MOUSE)
	{
	case Collider::MOUSE:
		switch (EventListener)
		{
			
		}
		break;
	}
}


SDL_Rect Collider::FindMidPointOfObject(SDL_Rect temp_,SDL_Rect temp_1)
{
	int x1_, x2_, y1_, y2_;

	x1_ = temp_.x;
	y1_ = temp_.y;

	x2_ = temp_1.x;
	y2_ = temp_1.y;

	int midPoint0,midPoint1;

	midPoint0 = sqrt(x1_ + y1_);

	midPoint1 = sqrt(x2_ + y2_);

	SDL_Rect middleRect;

	middleRect.x = midPoint0;
	middleRect.y = midPoint1;

	return middleRect;
}

Collider::~Collider()
{
}

