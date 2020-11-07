#ifndef SKELETON_H
#define SKELETON_H
#include "GameObject.h"
#include "../TextureManager/TextureManager.h"
#include "../Physics/Collider.h"
#include "../Game/AI/AI.h"
#include "../Animator/Animator.h"

using namespace std;


class Skeleton : public GameObject, public AI , public Animator
{
public:
	Skeleton();
	Skeleton(int x, int y);
	~Skeleton();
	void Inti();
	void handleCollison();
	virtual void Disable();
	virtual void Update(float deltaTime_);
	virtual void Render();
	virtual void Steer(); //defined here but not called in the regular update
	virtual void Seperate();
private:
	/*Member variables*/
	float speed;
	float prediction;
	/*Objects Members*/
	Vec2 targetPos;
	RectCollider col;	
	SDL_Rect srcRect0, destRect0;
	enum class AnimationStates
	{
		ATTACK = 0,
		DEAD,
		HIT,
		IDLE,
		REACT,
		WALK
	};
	AnimationStates animState;
	/*Functions*/
	virtual void PlayAnimations(AnimationStates state_);
	Vec2 getTargetDirection();
	Vec2 getSeperationDirection(Vec2 pos_);
};

struct SkeletonStats
{

};

#endif
