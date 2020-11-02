#ifndef ENEMY_H
#define ENEMY_H
#include "GameObject.h"
#include "../TextureManager/TextureManager.h"
#include "../Physics/Collider.h"
#include "../Game/AI/AI.h"
#include "../Animator/Animator.h"

using namespace std;

class Enemy: public GameObject
{
public:
	~Enemy();
	void Disable();
protected:
	void ChangeSrcSize(int src_w, int src_h);
	template<typename T> //I forgot what this does, and it seems to have a functional purpose
	inline void Pop_Front(vector<T>& v)
	{
		if (v.size() > 0)
		{
			v.erase(v.begin());
		}
	};
private:
	//Could enter generics here 
};

class Skeleton : public Enemy, public AI , public Animator
{
public:
	Skeleton();
	Skeleton(int x, int y);
	~Skeleton();
	void Inti();
	void handleCollison();
	virtual void Update(float deltaTime_);
	virtual void Render();
	virtual void Chase();
	virtual void Pursue();
	
private:
	/*Member variables*/
	float speed;
	float prediction;
	/*Objects Members*/
	Vec2 targetPos;
	Collider col;	
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
	Vec2 getTarget();
};

struct SkeletonStats
{

};

#endif
