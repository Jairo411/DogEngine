#include "AnimationSet.h"
#include "C_Animation.h"
#include "../GameObject.h"

AnimationSet::AnimationSet()
{
	Animations = std::list<C_Animation*>();
}

AnimationSet::~AnimationSet()
{

}

void AnimationSet::OnCreate(BaseObj* owner_)
{
	Parent = owner_;
	GameObject* ptr = static_cast<GameObject*>(Parent);
}

void AnimationSet::OnDestroy()
{
}

void AnimationSet::Update(float deltaTime_)
{
}

void AnimationSet::AddAnimation(C_Animation* Animation_)
{
	Animations.push_back(Animation_);
}

void AnimationSet::RemoveAnimation(C_Animation* Animation_)
{
	Animations.remove(Animation_);
}
