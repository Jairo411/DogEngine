#include "C_Animation.h"

C_Animation::C_Animation()
{
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
	imageHolder.push_back(texture_);
}

void C_Animation::SetAnimationLength(float animationLength_)
{
	secondsOfAnimations = animationLength_;
}
