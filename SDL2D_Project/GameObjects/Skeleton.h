#ifndef SKELETON_H
#define SKELETON_H
#include "GameObject.h"
#include "../Game/AI/AI.h"
#include "Map/Map.h"
#include "../Graphics/TextureManager.h"
#include "../Animator/Animator.h"
#include "../Physics/Collider.h"
#include "../Math/Converter.h"

using namespace std;

/*2021-07-09
	Not prefect, but  will intentioned going to reimplement this class.*/
class Skeleton : public GameObject, public AI , public Animator
{
public:
	Skeleton();
	Skeleton(int x, int y);
	~Skeleton();
	/*New Code*/
	void OnCreate()override;
	void OnDestroy()override;
	/*Old Code*/
	void Inti();
	void handleCollison();
	virtual void Disable();
	virtual void Update(float dt);
	virtual void fixedUpdate(float dt_);
	virtual void Render();
	virtual void Steer();
	virtual void Seperate();
private:
	/*Member variables*/
	float speed;
	float prediction;
	/*Objects Members*/
	Vec2 targetPos;
	RectCollider col;	
	SDL_Rect srcRect0, dstRect0;
	/*Get rid of this */
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
	Vec2 nodeDirection(std::vector<NavTile> directionSet);
	Vec2 getSeperationDirection(Vec2 pos_);
};


#endif
