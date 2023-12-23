#ifndef SKELETON_H
#define SKELETON_H
#include "GameObject.h"
#include "../Components/C_2DTransform.h"
#include "../Components/C_RectangleCollider.h"
#include "../Components/C_Sprite.h"
/*2021-07-09
	Not prefect, going to reimplement this class.*/
class DogEngine;
class Skeleton : public GameObject
{
public:
	Skeleton();
	Skeleton(int x, int y);
	virtual ~Skeleton();
	/*New Code*/
	void OnCreate()override;
	void OnDestroy()override;
	/*Old Code*/
	void Inti();
	void handleCollison();
	virtual void Update(float dt) override;
	virtual void Render() override;
	/*virtual void Steer();
	virtual void Seperate();*/
private:
	//New 
	C_Transform2D transform;
	C_RectangleCollider collider;
	C_Sprite sprite;

	//OLD 
	/*Member variables*/
	float dt; //remove 
	float speed; // remove 
	float prediction; // remove
	/*Objects Members*/
	vector2 targetPos;	//remove
	/*Get rid of this */
	enum class AnimationStates
	{
		ATTACK = 0,
		DEAD,
		HIT,
		IDLE,
		REACT,
		WALK
	}; // remove
	AnimationStates animState; //remove 
	/*virtual void PlayAnimations(AnimationStates state_);*/
	/*Vec2 getTargetDirection();
	Vec2 nodeDirection(std::vector<NavTile> directionSet);
	Vec2 getSeperationDirection(Vec2 pos_);*/
};


#endif
