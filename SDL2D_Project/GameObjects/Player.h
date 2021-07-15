#ifndef PLAYER_H
#define PLAYER_H


#include "GameObject.h"
#include "../Animator/Animator.h"
#include "../Input/Input.h"
#include "../Physics/Collider.h"
/*2021-07-09 
	Not prefect, but  will intentioned going to reimplement this class.*/
class TextureManager;
class Player : public GameObject , public Input , public Animator
{
public:
	 Player();
	 Player(const char * textureSheet, int x, int y);
	 ~Player();
	 /*Texture Display functions*/
	 virtual void Update(float DeltaTime_) override;
	 virtual void Render() override;

	 void Disable() override;
	 /* Collison Handler*/
	 void handleCollison(); 
	 /* Keyboard Handler */
	 bool KeyBoardInput(int key);
	 bool MouseInput(int key);
	 bool ControllerInput(int key);
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
	/*Members*/
	int amountOfAnimations;
	float delta;
	bool disableObject;
	/*Objects/Classes*/
	RectCollider collider;
	Uint32 FrameTicks;
	SDL_Rect srcRect0, dstRect0;
	GameObject* playerPtr;
	CircleCollider circleCol;
	AnimationStates animState;
	/*Functions*/
	virtual void PlayAnimations(AnimationStates temp_);
	Uint32 WaitAnimationsTicks(Uint32 wait_);
	

};

#endif // !PLAYER_HEADER

