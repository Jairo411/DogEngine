#ifndef C_ANIMATIONSETHEADER
#define C_ANIMATIONSETHEADER
#include <list>
#include "Component.h"
/*This Component is suppose to be used in conjunction with the sprite renderer class*/
class C_Animation;
class GameObject;
class AnimationSet : public Component
{
public:
	AnimationSet();
	virtual ~AnimationSet();
	virtual void OnCreate(BaseObj* owner_);
	virtual void OnDestroy();
	virtual void Update(float deltaTime_);
	virtual void FixedUpdate(float deltaTime_) {}
	virtual void Render() {}
	void AddAnimation(C_Animation* Animation_);
	void RemoveAnimation(C_Animation* Animation_);
private:
	std::list<C_Animation*> Animations;
};
#endif // !C_ANIMATIONSETHEADER
