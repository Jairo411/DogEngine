#include "GameObject.h"
#include "../TextureManager/TextureManager.h"

vector<GameObject*>GameObject::ObjHolder = vector<GameObject*>();
  
GameObject::GameObject()
{
	posX = 0;
	posY = 0;
	realPosition = Vec2(posX, posY);
	disableObject = false;
	nameID = "";
//	Going to use the Gameobject base class to check if inhereted object has name or not
}

void GameObject::UpdatePostion()
{
	posX = realPosition.x;
	posY = realPosition.y;
	APosition = moveMiddle(Vec2(posX,posY));
}

int GameObject::ReadAmountOfAnimations()
{
	return 0;
}

void GameObject::setDelta(float deltaTime_)
{
	deltaTime = deltaTime_;
}

float GameObject::getDelta()
{
	return deltaTime;
}

void GameObject::DrawLine(Vec2 start_, Vec2 end_)
{
	SDL_RenderClear(Game::renderer);
	SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawLine(Game::renderer, start_.x,start_.y,end_.x, end_.y);
}

SDL_Texture* GameObject::getTexture()
{
	return objTexture;
}

bool GameObject::setDisable(bool temp)
{
	return disableObject= temp;
}

bool GameObject::getDisable()
{
	if (disableObject==true)
	{
		return true;
	}
	return false;	
}

Vec2 GameObject::moveMiddle(Vec2 pos_)
{
	Vec2 center;
	center.x = (pos_.x + this->srcRect.w/2);
	center.y = (pos_.y + this->srcRect.h/2);
	return center;
}

void GameObject::setPosition(int x_, int y_)
{
	posX = x_;
	posY = y_;
	realPosition = Vec2(posX, posY);
	Vec2 center = moveMiddle(Vec2(posX, posY));
	APosition = center;
}

void GameObject::setPosition(Vec2 vPosition)
{
	Vec2 center =moveMiddle(vPosition);
	posX = center.x;
	posY = center.y;
	realPosition = center;
}

Vec2 GameObject::getPosition()
{
	return this->APosition;
}




