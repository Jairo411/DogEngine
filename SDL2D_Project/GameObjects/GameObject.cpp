#include "GameObject.h"
#include "../TextureManager/TextureManager.h"
#include "../DesignPattern/Observer.h"

std::list<GameObject*>GameObject::OBJHolder = std::list<GameObject*>();

GameObject::GameObject()
{
	posX = 0;
	posY = 0;
	Position = Vec2(posX, posY);
	nameIdentifier = "GameObject";
	TextureDisplayRectInfo.first = &srcRect;
	TextureDisplayRectInfo.second = &dstRect;
	//	Going to use the Gameobject base class to check if inhereted object has name or not
}

GameObject::~GameObject()
{
	//GameObserver* temp;
	//temp = dynamic_cast<GameObserver*>(this);
	//Detach(temp);
	//temp = nullptr;;
	//delete temp;
}

void GameObject::UpdatePostion()
{
	posX = Position.x;
	posY = Position.y;
	PivotPosition = moveMiddle(Vec2(posX, posY));
}

void GameObject::DrawLine(Vec2 start_, Vec2 end_)
{
}

SDL_Texture* GameObject::getTexture()
{
	if (objTexture==NULL)
	{
		std::cout << "Object doesn't have texture" << std::endl;
	}
	return objTexture;
}

SDLDisplayRects GameObject::getTextureDisplayInfo()
{
	return TextureDisplayRectInfo;
}

Vec2 GameObject::moveMiddle(Vec2 pos_)
{
	Vec2 center;
	center.x = (pos_.x + this->srcRect.w / 2);
	center.y = (pos_.y + this->srcRect.h / 2);
	return center;
}

void GameObject::setPosition(int x_, int y_)
{
	posX = x_;
	posY = y_;
	Position = Vec2(posX, posY);
	PivotPosition = moveMiddle(Vec2(posX, posY));
}

void GameObject::setPosition(Vec2 vPosition)
{
	Vec2 center = moveMiddle(vPosition);
	posX = center.x;
	posY = center.y;
	Position = center;
}

/*Observer Pattern Implemented*/
//void GameObject::Attach(IObserver* observer_)
//{
//	currentObserver = observer_;
//	IObserverable::observerableContainer.push_back(observer_);
//}
//
//void GameObject::Detach(IObserver* observer_)
//{
//	IObserverable::observerableContainer.remove(observer_);
//	std::cout << "Observer has been removed from: " << getName().c_str() << endl;
//	system("pause");
//}
///*Observer Pattern Implemented*/
//void GameObject::Notify()
//{
//	if (!observerableContainer.empty())
//	{
//		observerableContainer.front()->Update();
//	}
//}

Vec2 GameObject::getPivotPosition()
{
	return this->PivotPosition;
}

Vec2 GameObject::getPosition()
{
	return Position;
}



