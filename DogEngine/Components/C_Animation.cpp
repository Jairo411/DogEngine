#include "C_Animation.h"

C_Animation::C_Animation()
{
	imageHolder=std::vector<SDL_Texture*>();
	secondsOfAnimations = 0.0f;
}

C_Animation::~C_Animation()
{
}

void C_Animation::OnCreate(BaseObj* owner_)
{
	Parent = owner_;
	
}

void C_Animation::OnDestroy()
{
}

void C_Animation::AddImage(SDL_Texture* texture_)
{
	imageHolder.push_back(texture_);
}

void C_Animation::RemoveImage(SDL_Texture* texture_)
{
	std::vector<SDL_Texture*>::iterator it;
	it = imageHolder.begin();
	for (it; it!=imageHolder.end(); it++)
	{
		if (*it=texture_)
		{
			imageHolder.erase(it);
		}
	}
}

void C_Animation::SetAnimationLength(float animationLength_)
{
	secondsOfAnimations = animationLength_;
}
