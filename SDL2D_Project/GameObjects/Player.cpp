#include "Player.h"
#include "../TextureManager/TextureManager.h"

/* How the sprite gets loaded is a problem. */
Player::Player()
{
	/* Basic intializations of a member variables */
	nullObjTexture = TextureManager::LoadTexture("C:/Users/jalbm/source/repos/SDL2D_Project/SDL2D_Project/Assets/Effects/Effects1/1_magicspell_spritesheet.png");
	realPosition = Vec2();
	srcRect.w = 0;
	srcRect.h = 0;
	srcRect.x = 0;
	srcRect.y = 0;
	FrameTicks = NULL;
	amountOfAnimations = 0;
	disableObject = NULL;
	collider = RectCollider();
	ptr = nullptr;
	/* Don't know the point of this to be honest...*/
}

Player::Player(const char* textureSheet, int x, int y)
{
	/* Basic intializations of a member variables */
	objTexture = TextureManager::LoadTexture(textureSheet);
	animState = AnimationStates::IDLE0;
	setPosition(x, y);
	srcRect.w = 100; // IMAGE SIZE ----> MAKE THIS A GAMEOBJECT FUNCTION 
	srcRect.h = 80; // IMAGE SIZE  This is where the image get finished drawed  
	srcRect.x = 0;  // This is where the image start begin drawed 
	srcRect.y = 0; // This is where the image start begin drawed


	destRect.x = srcRect.x;
	destRect.y = srcRect.y;

	amountOfAnimations = 0;
	FrameTicks = NULL;
	disableObject = NULL;

	circleCol = CircleCollider(5.0f);
	collider = RectCollider(srcRect.w,srcRect.h);
	ptr = this;
	IntiAnimations("C:/Users/jalbm/source/repos/SDL2D_Project/SDL2D_Project/Assets/Character/Sprites/Animations.txt", "./Assets/Character/Sprites/", 'a'); //Calling from the Animator class
	if (this->objTexture != NULL)
	{
		textureIsOn = true;
		std::cout << "Object texture was intialized" << std::endl;
	}
	else {
		textureIsOn = false;
		std::cout << "Object texture wasn't found" << std::endl;
	}

	GameObject::ObjHolder.push_back(ptr);
	nameID += to_string(ObjHolder.size());


}

Player::~Player()
{
	objTexture = nullptr;

}

void Player::OnUpdate(float deltaTime_)
{
	/*Over here add somesort of function in order to change the objTexture variable of Player Character Model*/
	//Note you need to get your FPS working properly in order to to proper animate your character
	
	setDelta(deltaTime_);

	PlayAnimations(animState);
	handleCollison();
	delta = deltaTime_;

	if (getDisable() == false)
	{
		destRect.x = realPosition.x;
		destRect.y = realPosition.y;
		destRect.w = srcRect.w;
		destRect.h = srcRect.h;
	}
	else if (getDisable() == true)
	{
		Disable();
	}
	collider.CollisonUpdate(this->realPosition);
	UpdatePostion();
}

void Player::OnRender()
{
	/*This is in the loop*/
	if (nullObjTexture != NULL)
	{
		SDL_RenderCopy(Game::renderer->getInstance()->getRenderer(), nullObjTexture, NULL, NULL);
		//	cout << "You're player Texture isn't working" <<endl;
	}
	if (getDisable() == false)
	{
		SDL_RenderCopy(Game::renderer->getInstance()->getRenderer(), objTexture, &srcRect, &destRect);
		collider.CollisonRender();
	}
	else if (getDisable() == true)
	{
		SDL_RenderCopy(Game::renderer->getInstance()->getRenderer(), nullObjTexture, &srcRect, &destRect);
	}
}

void Player::Disable()
{
	/* You can store all the vaules in here */
	disableObject = true;
}

void Player::handleCollison()
{
}


bool Player::KeyBoardInput(int key)
{
	/*You have to fix this create allow the Input to accept two forms of Input
	*/
	/* Because you handle the movement throught the Keyboard Input it actually is behide
		the movement of the game*/
	if (disableObject == true)
	{
		return false;
	}
	if (key != NULL)
	{
		if (key == SDLK_a)
		{
			realPosition.x -= 3.5;
			animState = AnimationStates::RUN;
		}
		if (key == SDLK_d)
		{
			realPosition.x += 3.5;
			animState = AnimationStates::RUN;
		}
		if (key == SDLK_w)
		{
			realPosition.y -= 3.5;
			animState = AnimationStates::RUN;
		}
		if (key == SDLK_s)
		{
			realPosition.y += 2.5;
			animState = AnimationStates::RUN;
		}
		if (key == SDLK_SPACE) {
			animState = AnimationStates::JUMP;
		}
	}
	else
	{
		animState = AnimationStates::IDLE0;
		return true;
	}
	return false;
}

bool Player::MouseInput(int key)
{
	if (disableObject == true)
	{
		return false;
	}
	if (key != NULL)
	{
		if (key == SDL_BUTTON_LEFT)
		{
			animState = AnimationStates::ATTACK0;
		}
		if (key == SDL_BUTTON_RIGHT)
		{
			animState = AnimationStates::ATTACK1;
		}
		if (key == SDL_BUTTON_MIDDLE)
		{
			animState = AnimationStates::ATTACK2;
		}
		return true;
	}

	return false;
}

bool Player::ControllerInput(int key)
{
	return false;
}

//This might be a way of hard coding this
/* function doesn't hold anything, just tells vectors what size they are and plays animations*/
void Player::PlayAnimations(AnimationStates temp_)
{
	Uint32 ticks = 10*Game::timer->GetCurrentTicks();
	Uint32 frames;
	/*
		Im gonna re-work all this mess, its old and doesnt really make sense. 
	*/
	switch (temp_)
	{
	case AnimationStates::ATTACK0:
		frames = ticks % 4; 
		objTexture = sprite.animationSet.at(0).at(frames);
		break;
	case AnimationStates::ATTACK1:
		frames = ticks % 6;
		objTexture = sprite.animationSet.at(1).at(frames);
		break;
	case AnimationStates::ATTACK2:
		frames = ticks % 6;
		objTexture = sprite.animationSet.at(2).at(frames);
		break;
	case AnimationStates::CLIMB:
		frames =	ticks % 5;
		objTexture = sprite.animationSet.at(3).at(frames);
		break;
	case AnimationStates::CORNERGRAB:
		frames = ticks % 4;
		objTexture = sprite.animationSet.at(4).at(frames);
		break;
	case AnimationStates::CORNERJUMP:
		frames = ticks % 3;
		objTexture = sprite.animationSet.at(5).at(frames);
		break;
	case AnimationStates::CROUCH:
		frames = ticks % 4;
		objTexture = sprite.animationSet.at(6).at(frames);
		break;
	case AnimationStates::DEATH:
		frames = ticks % 7;
		objTexture = sprite.animationSet.at(7).at(frames);
		break;
	case AnimationStates::FALL:
		frames = ticks % 2;
		objTexture = sprite.animationSet.at(8).at(frames);
		break;
	case AnimationStates::HURT:
		frames = ticks % 3;
		objTexture = sprite.animationSet.at(9).at(frames);
		break;
	case AnimationStates::IDLE0:
		frames = ticks % 3;
		objTexture = sprite.animationSet.at(10).at(frames);
		break;
	case AnimationStates::IDLE1:
		frames = ticks % 4;
		objTexture = sprite.animationSet.at(11).at(frames);
		break;
	case AnimationStates::JUMP:
		frames = ticks % 4;
		objTexture = sprite.animationSet.at(12).at(frames);
		break;
	case AnimationStates::RUN:
		frames = ticks % 6;
		objTexture = sprite.animationSet.at(13).at(frames);
		break;
	case AnimationStates::SLIDE:
		frames =	ticks % 2;
		objTexture = sprite.animationSet.at(14).at(frames);
		break;
	default:
		break;
	}
}

Uint32 Player::WaitAnimationsTicks(Uint32 wait_)
{
	FrameTicks = wait_;
	return FrameTicks;
}
