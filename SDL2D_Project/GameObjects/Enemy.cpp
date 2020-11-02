#include "Enemy.h"
#include "../Game/Game.h"
Enemy::~Enemy()
{
}



void Enemy::Disable()
{

}



void Enemy::ChangeSrcSize(int src_w, int src_h)
{
	src_w = srcRect.h;
	src_h = srcRect.w;
	
}

Skeleton::Skeleton()
{

}

Skeleton::Skeleton(int x, int y)
{
	setPosition(x, y);
	speed = 40;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect0.x = 0;
	destRect0.y = 0;
	srcRect0.w = 55;
	srcRect0.h = 55;

	objTexture = nullptr;
	srcRect.w = 40;
	srcRect.h = 40;

	destRect.x = srcRect.x;
	destRect.y = srcRect.y;

	animState = AnimationStates::WALK;

	ptr = this;
	col = Collider(55);
	GameObject::ObjHolder.push_back(ptr);
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
		Pop_Front(sprite.animationSet.at(i));
		totalSize++;
	} //you have to move this over somewhere it's more readable 
}

void Skeleton::Update(float DeltaTime_)
{
	if (getDisable() == false)
	{
		destRect0.x = Cposition.x;
		destRect0.y = position.y;
		destRect0.w = srcRect0.w;
		destRect0.h = srcRect0.h;
	}
	else if (getDisable() == true)
	{
		Disable();
	}
	col.CollisonUpdate(position.x, position.y);
	UpdatePostion();
	Chase();
}

void Skeleton::Render()
{
	
	PlayAnimations(AnimationStates::WALK);

	if (getDisable() == false)
	{
		SDL_RenderCopy(Game::renderer, objTexture, &srcRect0, &destRect0);
		col.CollisonRender();
	}
	else if (getDisable() == true)
	{
		SDL_RenderCopy(Game::renderer, nullObjTexture, &srcRect0, &destRect0);
	}
}

void Skeleton::handleCollison()
{

}

void Skeleton::Chase()
{

	if (position!=getTarget())
	{
		chaseFlag = true;
		Vec2 pVelocity;
		Pursue();
		velocity = getTarget() * speed;
		pVelocity = velocity * prediction;
		position = (position + velocity * Game::timer->GetDeltaTime());// this should be an equation of motion but you need to have a decent timer class for this 
	}
}

void Skeleton::Pursue()
{
	if (position!=getTarget()&&chaseFlag==true)
	{
		/* Input Purse function here*/
		float maxPrediciton = 5.0f;
		Vec2 target = getTarget();
		if (speed <=(target.GetMag()/maxPrediciton))
		{
			prediction = maxPrediciton;
		}
		else
		{
			prediction = target.GetMag() / speed;
		}
	}
}


Vec2 Skeleton::getTarget()
{
	if (targetObj != nullptr)
	{
		Vec2 dir = targetObj->getPosition() - position;
		targetPos = dir.Normalize();
		return targetPos;
	}
	else {
		return Vec2(); // Right now this will just make the Vector 2 have a pos of (0,0), 
					   // you'll want to return a function that will make it not chase
	}
}

void Skeleton::PlayAnimations(AnimationStates state_) // These in both the player and the enemy classes need to be over an animations class
{
	Uint32 ticks = 10 * Game::timer->GetCurrentTicks();
	Uint32 frame;

	switch (state_)
	{
	case Skeleton::AnimationStates::ATTACK:
		frame = ticks % 18;
		objTexture=sprite.animationSet.at(0).at(frame);
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
