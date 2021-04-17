#include "Skeleton.h"
#include "../Game/Game.h"


Skeleton::Skeleton()
{
	setPosition(0, 0);
	speed = 0;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect0.x = 0;
	destRect0.y = 0;
}

Skeleton::Skeleton(int x, int y)
{
	setPosition(x, y);
	speed = 20;
	srcRect.x = 0;
	srcRect.y = 0;


	srcRect0.x = 0;
	srcRect0.y = 0;
	srcRect0.w = 60;//IMAGESIZE
	srcRect0.h = 60; //IMAGESIZE

	objTexture = nullptr;
	srcRect.w = 40;
	srcRect.h = 40;

	destRect.x = srcRect.x;
	destRect.y = srcRect.y;

	animState = AnimationStates::WALK;

	ptr = this;
	col = RectCollider(srcRect0.w, srcRect0.h);
	GameObject::ObjHolder.push_back(ptr);
	nameID += to_string(ObjHolder.size());
	Inti();
}

Skeleton::~Skeleton()
{

}

void Skeleton::Inti()
{
	SDL_Texture* tempIMG;
	SDL_Texture* actualIMG;


	IntiAnimations("C:/Users/jalbm/source/repos/SDL2D_Project/SDL2D_Project/Assets/EnemySprites/Skeleton/Sprite Sheets/SkeletonAnimations.txt", "./Assets/EnemySprites/Skeleton/Sprite Sheets/", 'S');
	int sourceX = 0;
	int sourceY = 0;
	int tempH, tempW;
	int lengthOfSprite;


	destRect.h = srcRect.h;
	destRect.w = srcRect.w;



	int totalSize = 0;
	int lastWidthVar = 0;

	for (int i = 0; i < sprite.animationSet.size(); i++)
	{
		//This works because I only place one texture in each 
		// 2 dimeson or slot. 
		actualIMG = sprite.animationSet.at(i).at(0);
		SDL_QueryTexture(actualIMG, NULL, NULL, &tempW, &tempH);
		switch (i)
		{
		case 0:
			destRect.w = 43;
			srcRect.w = destRect.w;
			break;
		case 1:
			destRect.w = 30;
			srcRect.w = destRect.w;
			break;
		case 2:
			destRect.w = 30;
			srcRect.w = destRect.w;
			break;
		case 3:
			destRect.w = 24;
			srcRect.w = destRect.w;
			break;
		case 4:
			destRect.w = 22;
			srcRect.w = destRect.w;
			break;
		case 5:
			destRect.w = 22;
			srcRect.w = destRect.w;
			break;
		default:
			break;
		}
		lengthOfSprite = tempW / destRect.w;
		for (int j = 0; j < lengthOfSprite; j++)
		{
			switch (i)
			{
			case 0:
				sourceX = 43 * j;
				sourceY = 0;
				break;
			case 1:
				sourceX = 33 * j;
				sourceY = 0;
				break;
			case 2:
				sourceX = 30 * j;
				sourceY = 0;
				break;
			case 3:
				sourceX = 24 * j;
				sourceY = 0;
				break;
			case 4:
				sourceX = 22 * j;
				sourceY = 0;
				break;
			case 5:
				sourceX = 22 * j;
				sourceY = 0;
				break;
			default:
				break;
			}

			srcRect.x = sourceX;
			srcRect.y = sourceY;

			tempIMG = TextureManager::LoadTexture(srcRect, actualIMG);
			sprite.animationSet.at(i).push_back(tempIMG);
			totalSize++;
		}
		sourceX = 0;
		totalSize++;
	} //you have to move this over somewhere it's more readable 
}

void Skeleton::Update(float DeltaTime_)
{
	if (dynamic_cast<IObserverable*>(this))
	{
		Notify();
	}
	if (getDisable() == false)
	{
		destRect0.x = realPosition.x;
		destRect0.y = realPosition.y;
		destRect0.w = srcRect0.w;
		destRect0.h = srcRect0.h;
	}
	else if (getDisable() == true)
	{
		Disable();
	}
	col.CollisonUpdate(this->realPosition);
	UpdatePostion();
}

void Skeleton::Render()
{

	PlayAnimations(AnimationStates::WALK);

	if (getDisable() == false)
	{
		SDL_RenderCopy(Window::RenderContext->renderer, objTexture, &srcRect0, &destRect0);
		col.CollisonRender();
		navCollider.CollisonRender();
	}
	else if (getDisable() == true)
	{
		SDL_RenderCopy(Window::RenderContext->renderer, nullObjTexture, &srcRect0, &destRect0);
	}
}

void Skeleton::handleCollison()
{

}

void Skeleton::Disable()
{

}

// so steer gets defined in there respective GameObject class but they don't get called in the, yes but they don't get called in there GameObject classes 
void Skeleton::Steer()
{
	if (pathFinding == true)
	{
		velocity = nodeDirection(path) * speed;
		realPosition = (realPosition + velocity * Game::timer->GetDeltaTime());
	}

	if (realPosition != getTargetDirection() && seperateFlag == false && pathFinding == false)
	{
		chaseFlag = true;
		velocity = getTargetDirection() * speed;
		realPosition = (realPosition + velocity * Game::timer->GetDeltaTime());// this should be an equation of motion but you need to have a decent timer class for this 
	}
	else if (realPosition != getTargetDirection() && seperateFlag == true && pathFinding == false)
	{
		Seperate();
	}
}

void Skeleton::Seperate()
{

}


Vec2 Skeleton::getTargetDirection()
{
	if (targetObj != nullptr)
	{
		Vec2 dir = targetObj->getPosition() - getPosition();
		if (dir.GetMag() > 1.0)
		{
			targetPos = dir.Normalize();
			return targetPos;
		}
		dir = Vec2(0.0f, 0.0f);
		return dir;
	}
}

Vec2 Skeleton::nodeDirection(std::vector<NavTile> directionSet)
{

	Vec2 dir;
	Vec2 normalize;
	if (directionSet.at(indexPath).getPosition() == getPosition())
	{

		indexPath++;
		std::cout << "Index :" << indexPath << std::endl;

	}

	if (indexPath == directionSet.size())
	{
		pathFinding = false;
		dir = Vec2(0.0f, 0.0f);
		return dir;
	}
	dir = directionSet.at(indexPath).getPosition() - getPosition();

	normalize = dir.Normalize();

	return normalize;
}

Vec2 Skeleton::getSeperationDirection(Vec2 pos_)
{
	Vec2 tempPos = realPosition - pos_;
	Vec2 normalizedPos = tempPos.Normalize();
	return normalizedPos;
}

void Skeleton::PlayAnimations(AnimationStates state_) // These in both the player and the enemy classes need to be over an animations class
{
	Uint32 ticks = 10 * Game::timer->GetCurrentTicks();
	Uint32 frame;

	switch (state_)
	{
	case Skeleton::AnimationStates::ATTACK:
		frame = ticks % 18;
		objTexture = sprite.animationSet.at(0).at(frame);
		break;
	case Skeleton::AnimationStates::DEAD:
		frame = ticks % 15;
		objTexture = sprite.animationSet.at(1).at(frame);
		break;
	case Skeleton::AnimationStates::HIT:
		frame = ticks % 8;
		objTexture = sprite.animationSet.at(2).at(frame);
		break;
	case Skeleton::AnimationStates::IDLE:
		frame = ticks % 11;
		objTexture = sprite.animationSet.at(3).at(frame);
		break;
	case Skeleton::AnimationStates::REACT:
		frame = ticks % 4;
		objTexture = sprite.animationSet.at(4).at(frame);
		break;
	case Skeleton::AnimationStates::WALK:
		frame = ticks % 13;
		objTexture = sprite.animationSet.at(5).at(frame);
		break;
	default:
		break;
	}
}
