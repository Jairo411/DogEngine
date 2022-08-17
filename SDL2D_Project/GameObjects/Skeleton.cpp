#include "Skeleton.h"
#include "../DogEngine/DogEngine.h"


Skeleton::Skeleton()
{
	setPosition(0, 0);
	speed = 0;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect0.x = 0;
	dstRect0.y = 0;
}

Skeleton::Skeleton(int x, int y)
{
	setPosition(x, y);
	srcRect.x = 0;
	srcRect.y = 0;
	speed = 0.1f;

	className = typeid(*this).name();
	className.erase(0, 6);

	srcRect0.x = 0;
	srcRect0.y = 0;
	srcRect0.w = 60;//IMAGESIZE
	srcRect0.h = 60; //IMAGESIZE

	objTexture = nullptr;
	srcRect.w = 40;
	srcRect.h = 40;

	dstRect.x = srcRect.x;
	dstRect.y = srcRect.y;

	animState = AnimationStates::WALK;

	//temporary pointer so my engine doesn't break
	GameObject::OBJHolder.push_back(this);

	Inti();
}

Skeleton::~Skeleton()
{

}

void Skeleton::OnCreate()
{
}

void Skeleton::OnDestroy()
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


	dstRect.h = srcRect.h;
	dstRect.w = srcRect.w;



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
			dstRect.w = 43;
			srcRect.w = dstRect.w;
			break;
		case 1:
			dstRect.w = 30;
			srcRect.w = dstRect.w;
			break;
		case 2:
			dstRect.w = 30;
			srcRect.w = dstRect.w;
			break;
		case 3:
			dstRect.w = 24;
			srcRect.w = dstRect.w;
			break;
		case 4:
			dstRect.w = 22;
			srcRect.w = dstRect.w;
			break;
		case 5:
			dstRect.w = 22;
			srcRect.w = dstRect.w;
			break;
		default:
			break;
		}
		lengthOfSprite = tempW / dstRect.w;
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

			//tempIMG = TextureManager::LoadTexture(srcRect, actualIMG);
			sprite.animationSet.at(i).push_back(tempIMG);
			totalSize++;
		}
		sourceX = 0;
		totalSize++;
	} //you have to move this over somewhere it's more readable 
}

void Skeleton::Update(float DeltaTime_)
{
	/* I like this but IObserverable Should be in the Game Object class*/
	dt = DeltaTime_;
	dt /= 1000.0;
	if (dynamic_cast<IObserverable*>(this))
	{
		//Notify();
	}
	dstRect0.x = Position.x;
	dstRect0.y = Position.y;
	dstRect0.w = srcRect0.w;
	dstRect0.h = srcRect0.h;
	
	UpdatePostion();
}

void Skeleton::fixedUpdate(float dt_)
{
}

void Skeleton::Render()
{
	switch (DogEngine::rendererManager->getRenderValue())
	{
	default:
		break;

	case 0: // SDL

		PlayAnimations(AnimationStates::WALK);


		DogEngine::rendererManager->GetInstance()->GetRenderAPI<SDLRenderer*>()->DrawTexture(objTexture, &srcRect0, &dstRect0);
	

		break;

	case 1: // OPENGL

		break;

	case 2: // VULKAN

		break;
	}


}

void Skeleton::handleCollison()
{

}

// so steer gets defined in there respective GameObject class but they don't get called in the, yes but they don't get called in there GameObject classes 
void Skeleton::Steer()
{
	if (pathFinding == true)
	{
		velocity = nodeDirection(path);
		Position = (Position + velocity * dt);
	}

	if (Position != getTargetDirection() && seperateFlag == false && pathFinding == false)
	{
		chaseFlag = true;

		velocity = getTargetDirection();

		Position = (Position + velocity * dt);// this should be an equation of motion but you need to have a decent timer class for this
	//	std::cout << "real position" << realPosition <<std::endl;
	}
	else if (Position != getTargetDirection() && seperateFlag == true && pathFinding == false)
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
		Vec2 dir = targetObj->getPivotPosition() - getPivotPosition();
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
	if (directionSet.at(indexPath).getPosition() == getPivotPosition())
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
	dir = directionSet.at(indexPath).getPosition() - getPivotPosition();

	normalize = dir.Normalize();

	return normalize;
}

Vec2 Skeleton::getSeperationDirection(Vec2 pos_)
{
	Vec2 tempPos = Position - pos_;
	Vec2 normalizedPos = tempPos.Normalize();
	return normalizedPos;
}

void Skeleton::PlayAnimations(AnimationStates state_) // These in both the player and the enemy classes need to be over an animations class
{
	/*Uint32 ticks = 10 * DogEngine::timer->GetCurrentTicks();
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
	}*/
}
