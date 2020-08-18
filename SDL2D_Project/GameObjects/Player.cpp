#include "Player.h"
#include "../TextureManager/TextureManager.h"



Player::Player(const char * textureSheet, int x, int y)
{
	objTexture = TextureManager::LoadTexture(textureSheet);
	posX = x;
	posY = y;
	srcRect.w = 100;
	srcRect.h = 74;
	srcRect.x = 0;
	srcRect.y = 0;
	amountOfAniamtions = 0;
	intiAnimation("C:/Users/jalbm/source/repos/SDL2D_Project/SDL2D_Project/Assets/Character/Sprites/Animations.txt");
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
	if (getDisable()==false)
	{
		dstRect.x = posX;
		dstRect.y = posY;
		dstRect.w = srcRect.w;
		dstRect.h = srcRect.h;
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
		SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &dstRect);
	}
	else if (getDisable()==true)
	{
		SDL_RenderCopy(Game::renderer, nullObjTexture, &srcRect, &dstRect);
	}
}

void Player::Disable()
{
	/* You can store all the vaules in here */
}


bool Player::keyBoardInput(int key)
{
	/*You have to fix this create allow the Input to accept two forms of Input 
	*/
	if (getDisable()==true)
	{
		return false;
	}
	if (key!=NULL)
	{
		if (key == SDLK_a)
		{
			posX -= 1;
			
		}
		else if (key == SDLK_d)
		{
			posX += 1;
		}
		else if (key == SDLK_w)
		{
			posY -= 1;
		}
		else if (key == SDLK_s)
		{
			posY += 1;
		}
		return true;
	}
}

bool Player::mouseInput(int key)
{
	return false;
}

bool Player::controllerInput(int key)
{
	return false;
}


