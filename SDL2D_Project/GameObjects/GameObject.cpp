#include "GameObject.h"
#include "../TextureManager/TextureManager.h"
#include "../DesignPattern/Observer.h"

std::list<GameObject*>GameObject::OBJHolder = std::list<GameObject*>();

GameObject::GameObject()
{
	posX = 0;
	posY = 0;
	realPosition = Vec2(posX, posY);
	disableObject = false;
	nameIdentifier = "GameObject";
	TextureDisplayRectInfo.first = &srcRect;
	TextureDisplayRectInfo.second = &dstRect;
	//	Going to use the Gameobject base class to check if inhereted object has name or not
}

GameObject::~GameObject()
{
	GameObserver* temp;
	temp = dynamic_cast<GameObserver*>(this);
	Detach(temp);
	temp = nullptr;;
	delete temp;
}

void GameObject::UpdatePostion()
{
	posX = realPosition.x;
	posY = realPosition.y;
	APosition = moveMiddle(Vec2(posX, posY));
}

int GameObject::ReadAmountOfAnimations()
{
	return 0;
}


void GameObject::DrawLine(Vec2 start_, Vec2 end_)
{
//	SDL_RenderClear(Game::rendererManager->GetInstance()->getRenderer());
//	SDL_SetRenderDrawColor(Game::rendererManager->GetInstance()->getRenderer(), 255, 255, 255, SDL_ALPHA_OPAQUE);
//	SDL_RenderDrawLine(Game::rendererManager->GetInstance()->getRenderer(), start_.x, start_.y, end_.x, end_.y);
}

SDL_Texture* GameObject::getTexture()
{
	return objTexture;
}

std::pair<SDL_Rect*, SDL_Rect*> GameObject::getTextureDisplayInfo()
{
	return TextureDisplayRectInfo;
}

bool GameObject::setDisable(bool temp)
{
	return disableObject = temp;
}

bool GameObject::getDisable()
{
	if (disableObject == true)
	{
		return true;
	}
	return false;
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
	realPosition = Vec2(posX, posY);
	Vec2 center = moveMiddle(Vec2(posX, posY));
	APosition = center;
}

void GameObject::setPosition(Vec2 vPosition)
{
	Vec2 center = moveMiddle(vPosition);
	posX = center.x;
	posY = center.y;
	realPosition = center;
}

/*Observer Pattern Implemented*/
void GameObject::Attach(IObserver* observer_)
{
	currentObserver = observer_;
	IObserverable::observerableContainer.push_back(observer_);
}

void GameObject::Detach(IObserver* observer_)
{
	IObserverable::observerableContainer.remove(observer_);
	std::cout << "Observer has been removed from: " << getName().c_str() << endl;
	system("pause");
}
/*Observer Pattern Implemented*/
void GameObject::Notify()
{
	if (!observerableContainer.empty())
	{
		observerableContainer.front()->Update();
	}
}

Vec2 GameObject::getPosition()
{
	return this->APosition;
}



