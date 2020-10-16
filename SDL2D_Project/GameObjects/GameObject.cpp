#include "GameObject.h"
#include "../TextureManager/TextureManager.h"

vector<GameObject*>GameObject::ObjHolder = vector<GameObject*>();
  
GameObject::GameObject()
{
	posX = 0;
	posY = 0;
	position = Vec2(posX, posY);
	disableObject = false;
	nameID = "";
	
//	Going to use the Gameobject base class to check if inhereted object has name or not
}

void GameObject::UpdatePostion()
{
	posX = position.x;
	posY = position.y;
}

bool GameObject::intiAnimation(const char* AnimTxtFile, const char* tempRelativeDir, const char firstChar)
{
	/*
	This checks to see if Animations or textures are in the 2D Vector object.
	if Gameobject has no Animation textures then function returns false.
	*/
	if (animationSet.size()==0)
	{
			string textReader;
			string fileElements;
			ifstream input;
			input.open(AnimTxtFile);
			
		
			/*Reads txt and checks if has A:
			A's will in the next line will have a const char locations that will read and input those values inside a a map/vector.
			the filestream will check a line in the file, if there is a N which will mean new animation set, and place it inside a new col/row  of a 2D map/vector.
			 */
			if (input.is_open())
			{
				int index=0;
				vector<SDL_Texture*> newSet;
				animationSet.push_back(newSet);
				do
				{
					input >> textReader;
					if (textReader.at(0) == firstChar)
					{
						string RelativeDir;
						fileElements = textReader;
						RelativeDir = tempRelativeDir + fileElements;
						animationSet.at(index).push_back(TextureManager::LoadTexture(RelativeDir.c_str()));
					}
					else if (textReader.at(0) == 'N')
					{
						index++;
						vector<SDL_Texture*> newSet;
						animationSet.push_back(newSet);
					}

				} while (textReader.at(0)!='E');
				input.close();
			}
		
		return true;
	}
	return false;
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

int GameObject::getX()
{
	return posX;
}

int GameObject::getY()
{
	return posY;
}

Vec2 GameObject::moveMiddle(Vec2 pos_)
{
	Vec2 center;
	center.x = (pos_.x + this->srcRect.w);
	center.y = (pos_.y + this->srcRect.h);
	return center;
}

void GameObject::setPosition(int x_, int y_)
{
	posX = x_;
	posY = y_;
	Vec2 center = moveMiddle(Vec2(posX, posY));
	position = center;
	
}

void GameObject::setPosition(Vec2 vPosition)
{
	Vec2 center =moveMiddle(vPosition);
	posX = center.x;
	posY = center.y;
	position = center;
}

Vec2 GameObject::getPosition()
{
	return position;
}




