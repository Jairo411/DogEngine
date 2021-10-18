#include "Collider.h"
#include "../Game/Game.h"

RectCollider::RectCollider()
{
	x = 0;
	y = 0;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = 0;
	srcRect.h = 0;

	collisonObjectType = CollisonObjectType::NONE;
	collisonType = CollisonType::NO_COl;
}

RectCollider::RectCollider(int squareArea_)
{
	x = 0;
	y = 0;


	collisonObjectType = CollisonObjectType::NONE;
	collisonType = CollisonType::NO_COl;

	srcRect.x = x;
	srcRect.y = y;

	srcRect.w = squareArea_;
	srcRect.h = squareArea_;

}

RectCollider::RectCollider(int width_, int height_)
{
	x = 0;
	y = 0;

	collisonObjectType = CollisonObjectType::NONE;
	collisonType = CollisonType::NO_COl;

	srcRect.x = x;
	srcRect.y = y;

	srcRect.w = width_;
	srcRect.h = height_;

	middlePoint = Vec2(width_ / 2, height_ / 2);
	
}

RectCollider::RectCollider(int width_, int height_, const char* colliderName_)
{
	x = 0;
	y = 0;

	collisonObjectType = CollisonObjectType::NONE;
	collisonType = CollisonType::NO_COl;

	srcRect.x = x;	
	srcRect.y = y;

	srcRect.w = width_;
	srcRect.h = height_;

	tag = colliderName_; 
}

RectCollider::RectCollider(int x_, int y_, int size_)
{
	x = x_;
	y = y_;

	collisonObjectType = CollisonObjectType::NONE;
	collisonType = CollisonObjectType::NONE;

	srcRect.x = x;
	srcRect.y = y;

	srcRect.w = size_;
	srcRect.h = size_;
}

RectCollider::RectCollider(int x_, int y_, int size_, const char* colliderName_)
{
	x = x_;
	y = y_;
	
	collisonObjectType = CollisonObjectType::NONE;
	collisonType = CollisonObjectType::NONE;

	srcRect.x = x;
	srcRect.y = y;

	srcRect.w = size_;
	srcRect.h = size_;

	tag = colliderName_;
}



void RectCollider::CollisonUpdate(int colPosX, int colPosY)
{
	/*This is needs to be worked out and actually thought out .*/
	int xPos, yPos;

	xPos = x + colPosX;
	yPos = y + colPosY;

	srcRect.x = xPos;
	srcRect.y = yPos;

	switch (collisonObjectType)
	{
	case RectCollider::NONE:
		switch (collisonType)
		{
		case RectCollider::NO_COl:
			break;
		case RectCollider::Game_COL:
			break;
		case RectCollider::Projectile_COL:
			break;
		}
		break;
	case RectCollider::GAMEOBJECT:
		switch (collisonType)
		{
		case RectCollider::NO_COl:
			break;
		case RectCollider::Game_COL:
			break;
		case RectCollider::Projectile_COL:
			break;
		}
		break;
	}
}

void RectCollider::CollisonUpdate(Vec2 position_)
{
	srcRect.x = position_.x;
	srcRect.y = position_.y;
}

void RectCollider::CollisonRender()
{
	//SDL_SetRenderDrawColor(Game::rendererManager->GetInstance()->getRenderer(), 33, 191, 75, 0);
	//SDL_RenderDrawRect(Game::rendererManager->GetInstance()->getRenderer(), &srcRect);
	//SDL_SetRenderDrawColor(Game::rendererManager->GetInstance()->getRenderer(), 225, 225, 225, 255);
}


void RectCollider::SetCollisonObjectType(int col_)
{
	collisonObjectType = col_;
}

void RectCollider::SetCollisonType(int col_)
{
	collisonType = col_;
}

void RectCollider::MouseEventListener(int event)
{

}

SDL_Rect* RectCollider::getCollider()
{
	return &srcRect;
}



RectCollider::~RectCollider()
{

}

CircleCollider::CircleCollider()
{
	x = 0;
	y = 0;
	oX = 0;
	oY = 0;
	radius = 0;
}

CircleCollider::CircleCollider(float radius_)
{
	oX = 0;
	oY = 0;
	radius = powf(radius_, 2);
	float startAngle = 0.0f;
	float endAngle = 360.0f;
	for (int i = 0; i < endAngle; i++)
	{
		startAngle = i;
		x = radius * cos(startAngle);
		y = radius * sin(startAngle);
		positions.push_back(Vec2(x, y));
	}
}

CircleCollider::CircleCollider(int x_, int y_, float radius_)
{
	oX = x_;
	oY = y_;
	radius = powf(radius_, 2);
	float startAngle = 0.0f;
	float endAngle = 360.0f;
	for (int i = startAngle; i < endAngle; i++)
	{
		startAngle = i;
		x = oX + radius * cos(startAngle);
		y = oY + radius * sin(startAngle);
		//std::cout << "Circle pos X: " << x << " Circle pos Y: " << y << std::endl;
		positions.push_back(Vec2(x, y));
	}
}


void CircleCollider::Update(Vec2 position_)
{
	positions.clear();
	oX = position_.x;
	oY = position_.y;
	float startAngle = 0.0f;
	float endAngle = 360.0f;
	for (int i = startAngle; i < endAngle; i++)
	{
		startAngle = i;
		x = oX + radius * cos(startAngle);
		y = oY + radius * sin(startAngle);
		//std::cout << "Circle pos X: " << x << " Circle pos Y: " << y << std::endl;
		positions.push_back(Vec2(x, y));
	}
	
}

void CircleCollider::Render()
{
	/*SDL_SetRenderDrawColor(Game::rendererManager->GetInstance()->getRenderer(), 0, 0, 0, 0);
	for (int i = 0; i < positions.size(); i++)
	{
		SDL_RenderDrawPoint(Game::rendererManager->GetInstance()->getRenderer(), positions.at(i).x, positions.at(i).y);
	}
	SDL_SetRenderDrawColor(Game::rendererManager->GetInstance()->getRenderer(), 225, 225, 225, 255);*/
}

CircleCollider::~CircleCollider()
{

}
