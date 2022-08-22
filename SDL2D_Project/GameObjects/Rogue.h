#ifndef PLAYER_H
#define PLAYER_H
#include "GameObject.h"
#include "../Animator/Animator.h"
#include "../EventSystem/Event.h"
#include "../Physics/Collider.h"
/*2021-07-09 
	Not prefect, but  will intentioned going to reimplement this class.
	Rename this to PlayerController
	*/
class TextureManager;
class Rogue : public GameObject , public Animator
{
public:
	 Rogue();
	 Rogue(const char * textureSheet, int x, int y);
	 /*New Code*/
	 virtual void OnCreate()override;
	 virtual void OnDestroy()override;
	 ~Rogue();
	 /*Texture Display functions*/
	 //new Code
	 virtual void Render()override;
	 virtual void Update(float dt_) override;
	 virtual void fixedUpdate(float dt_) override;
	 enum class AnimationStates
	 {
		 ATTACK0 = 0,
		 ATTACK1,
		 ATTACK2,
		 CLIMB,
		 CORNERGRAB,
		 CORNERJUMP,
		 CROUCH,
		 DEATH,
		 FALL,
		 HURT,
		 IDLE0,
		 IDLE1,
		 JUMP,
		 RUN,
		 SLIDE,
	 };
private:  
	//Look at this stuff here
	/*Members*/
	float speed;
	int amountOfAnimations;
	bool disableObject;
	/*Objects/Classes*/
	Uint32 FrameTicks;
	SDL_Rect srcRect0, dstRect0;
	GameObject* playerPtr;
	AnimationStates animState;
	/*Functions*/
	virtual void PlayAnimations(AnimationStates temp_);
	Uint32 WaitAnimationsTicks(Uint32 wait_);
	

};

#endif // !PLAYER_HEADER

