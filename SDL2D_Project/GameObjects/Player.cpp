#include "Player.h"
#include "../TextureManager/TextureManager.h"

Player::Player(const char * textureSheet, int x, int y)
{
	objTexture = TextureManager::LoadTexture(textureSheet);
	AnimState = IDLE0;
	posX = x;
	posY = y;
	srcRect.w = 100;
	srcRect.h = 74;
	srcRect.x = 0;
	srcRect.y = 0;
	amountOfAniamtions = 0;
	intiAnimation("C:/Users/jalbm/source/repos/SDL2D_Project/SDL2D_Project/Assets/Character/Sprites/Animations.txt","./Assets/Character/Sprites/",'a');
	if (this->objTexture != NULL)
	{
		textureIsOn = true;
		std::cout << "Object texture was intialized" << std::endl;
	}
	else {
		textureIsOn = false;
		std::cout << "Object texture wasn't found" << std::endl;
	}
	
}

Player::~Player()
{
	objTexture = nullptr;

}

void Player::Update()
{
	/*Over here add somesort of function in order to change the objTexture variable of Player Character Model*/
	//Note you need to get your FPS working properly in order to to proper animate your character 

	PlayAnimations(AnimState);

	if (getDisable()==false)
	{
		destRect.x = posX;
		destRect.y = posY;
		destRect.w = srcRect.w;
		destRect.h = srcRect.h;
	}
	else if (getDisable()==true)
	{
		Disable();
	}
}

void Player::Render()
{
	/*This is in the loop*/
	if (getDisable()==false)
	{
		SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
	}
	else if (getDisable()==true)
	{
		SDL_RenderCopy(Game::renderer, nullObjTexture, &srcRect, &destRect);
	}
}

void Player::Disable()
{
	/* You can store all the vaules in here */
	disableObject = true;
}


bool Player::keyBoardInput(int key)
{
	/*You have to fix this create allow the Input to accept two forms of Input 
	*/
	if (disableObject==true)
	{
		return false;
	}
	if (key!=NULL)
	{

	
		if (key == SDLK_a)
		{
			posX -= 1;
			AnimState = RUN;
			return true;
		}
		else if (key == SDLK_d)
		{
			posX += 1;
			AnimState = RUN;
			return true;
		}
		else if (key == SDLK_w)
		{
			posY -= 1;
			AnimState = RUN;
			return true;
		}
		else if (key == SDLK_s)
		{
			posY += 1;
			AnimState = RUN;
			return true;
		}
		else if (key == SDLK_SPACE) {
			AnimState = JUMP;
			/*some Jump formula over here */
			return true;
		}
		/* If reached here that means that the Animation is over */
	}
	else 
	{
		AnimState = IDLE0;
		return true;
	}
}

bool Player::mouseInput(int key)
{
	if (disableObject==true)
	{
		return false;
	}
	if (key!=NULL)
	{
		if (key == SDL_BUTTON_LEFT)
		{
			AnimState = ATTACK0;
			return true;
		}
		if (key==SDL_BUTTON_RIGHT)
		{
			AnimState = ATTACK1;
			return true;
		}
		if (key==SDL_BUTTON_MIDDLE)
		{
			AnimState = ATTACK2;
			return true;
		}
	}
	else 
	{
		if (GetAnimTicks() == 0)
		{
			WaitAnimationsTicks(0);
			AnimState = IDLE0;
			return true;
		}
	}
}

bool Player::controllerInput(int key)
{
	return false;
}
Uint32 Player::GetAnimTicks()
{
	return currentAnimTicks;
}
//This might be a way of hard coding this 
/* function doesn't hold anything, just tells vectors what size they are and plays animations*/
void Player::PlayAnimations(int state_)
{
	Uint32 ticks = SDL_GetTicks();
	Uint32 seconds = ticks / 100;
	Uint32 sprite;
	switch (state_)
	{
	case Player::ATTACK0:
		//Each click should cycle through the attacks
		sprite = seconds % 4;
		objTexture = animationSet.at(0).at(sprite);
		break;
	case Player::ATTACK1:
		//Each click should cycle through the attacks
		sprite = seconds % 6;
		objTexture = animationSet.at(1).at(sprite);
		break;
	case Player::ATTACK2:
		//Each click should cycle through the attacks
		sprite = seconds % 6;
		objTexture = animationSet.at(2).at(sprite);
		break;
	case Player::CLIMB:
		sprite = seconds % 5;
		objTexture = animationSet.at(3).at(sprite);
		break;
	case Player::CORNERGRAB:
		sprite = seconds % 4;
		objTexture = animationSet.at(4).at(sprite);
		break;
	case Player::CORNERJUMP:
		sprite = seconds % 3;
		objTexture = animationSet.at(5).at(sprite);
		break;
	case Player::CROUCH:
		sprite = seconds % 4;
		objTexture = animationSet.at(6).at(sprite);
		break;
	case Player::DEATH:
		sprite = seconds % 7;
		objTexture = animationSet.at(7).at(sprite);
		break;
	case Player::FALL:
		sprite = seconds % 2;
		objTexture = animationSet.at(8).at(sprite);
		break;
	case Player::HURT:
		sprite = seconds % 3;
		objTexture = animationSet.at(9).at(sprite);
		break;
	case Player::IDLE0:
		sprite = seconds % 3;
		objTexture = animationSet.at(10).at(sprite);
		break;
	case Player::IDLE1:
		sprite = seconds % 4;
		objTexture = animationSet.at(11).at(sprite);
		break;
	case Player::JUMP:
		sprite = seconds % 4;
		objTexture = animationSet.at(12).at(sprite);
		break;
	case Player::RUN:
		sprite = seconds % 6;
		objTexture = animationSet.at(13).at(sprite);
		break;
	case Player::SLIDE:
		sprite = seconds % 2;
		objTexture = animationSet.at(13).at(sprite);
		break;
	default:
		sprite = seconds % 3;
		objTexture = animationSet.at(10).at(sprite);
		break;
	}
	if (state_==ATTACK0)
	{
		WaitAnimationsTicks(sprite);
	}
	else if (state_ == ATTACK1)
	{
		WaitAnimationsTicks(sprite);
	}
	else if (state_ == ATTACK2)
	{
		WaitAnimationsTicks(sprite);
	}
}

Uint32 Player::WaitAnimationsTicks(Uint32 wait_)
{
	currentAnimTicks = wait_+15;
	return currentAnimTicks;
}


