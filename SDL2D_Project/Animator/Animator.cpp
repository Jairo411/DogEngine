#include "Animator.h"
#include "../DogEngine/DogEngine.h"	

Animator::~Animator()
{

}

bool Animator::IntiAnimations(const char* AnimSetName_, const char* relativeDir_, const char firstChar_)
{
	/*
	This checks to see if Animations or textures are in the 2D Vector object.
	if Gameobject has no Animation textures then function returns false.
	*/
	IntiSprite();
	if (sprite.animationSet.size() == 0)
	{
		std::string textReader;
		std::string fileElements;
		ifstream input;
		input.open(AnimSetName_);
		/*Reads txt and checks if has a char that matches with what I put in:
		A's will in the next line will have a const char locations that will read and input those values inside a a map/vector.
		the filestream will check a line in the file, if there is a N which will mean new animation set, and place it inside a new col/row  of a 2D map/vector.
		 */
		if (input.is_open())
		{
			int index = 0;
			std::vector<SDL_Texture*> newSet;
			this->sprite.animationSet.push_back(newSet);
			do
			{
				input >> textReader;
				if (textReader.at(0) == firstChar_)
				{
					std::string RelativeDir;
					fileElements = textReader;
					RelativeDir = relativeDir_ + fileElements;
					sprite.animationSet.at(index).push_back(TextureManager::LoadTexture(RelativeDir.c_str()));
				}
				else if (textReader.at(0) == 'N')
				{
					index++;
					std::vector<SDL_Texture*> newSet;
					sprite.animationSet.push_back(newSet);
				}

			} while (textReader.at(0) != 'E');
			input.close();
		}
		CreateStates();
		return true;
	}
	return false;
}

void Animator::IntiSprite()
{
	sprite.animationSet = vector<vector<SDL_Texture*>>();
	sprite.spriteContainer = std::map<int, Uint32>();
	sprite.stringID = std::map<int, string>();
	sprite.spriteFrames = 0;
	sprite.frameSpeed = 100;
}

void Animator::ChangeStateName(std::string temp_, int ID_)
{
	sprite.stringID.at(ID_) = temp_;
}

void Animator::ChangeFrameSpeed(Uint32 frameTicks_)
{
	sprite.frameSpeed = frameTicks_;
}

void Animator::CreateStates()
{
	/*Depending on the amount of sets of animations, the Animator will create a state for it */
	std::string StateID;
	for (int i = 0; i < sprite.animationSet.size(); i++)
	{
		sprite.stringID.insert(pair<int, std::string>(i, "state" + i));
	}
}

