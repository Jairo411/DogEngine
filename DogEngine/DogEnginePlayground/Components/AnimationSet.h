#ifndef C_ANIMATIONSET_H
#define C_ANIMATIONSET_H
#include <list>
#include "../GameObjects/GameObject.h"
#include "Component.h"
#include "C_Animation.h"
/*This Component is suppose to be used in conjunction with the sprite renderer class*/
class AnimationSet : public Component
{
public:
	AnimationSet();
	virtual ~AnimationSet();
	virtual void OnCreate(BaseObj* owner_);
	virtual void OnDestroy();
	virtual void Update(float deltaTime_);
	virtual void Render() {}
	void AddAnimation(C_Animation* Animation_);
	void RemoveAnimation(C_Animation* Animation_);
private:
	std::list<C_Animation*> Animations;
};
#endif // !C_ANIMATIONSET_H
