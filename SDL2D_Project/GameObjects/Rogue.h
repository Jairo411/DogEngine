#ifndef ROUGE_H
#define ROGUE_H
#include "GameObject.h"
#include "../Components/C_2DTransform.h"
#include "../Components/C_RectangleCollider.h"
#include "../Components/C_Sprite.h"
/*2021-07-09 
	Not prefect, but  will intentioned going to reimplement this class.
	Rename this to PlayerController
	*/
class DogEngine;
class Rogue : public GameObject
{
public:
	 Rogue();
	 [[deprecated("Don't use this")]]
	 Rogue(const char * textureSheet, int x, int y);
	 /*New Code*/
	 virtual void OnCreate() override;
	 virtual void OnDestroy() override;
	 virtual  ~Rogue();
	 /*Texture Display functions*/
	 //new Code
	 virtual void Render() override;
	 virtual void Update(float dt_) override;
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
	C_Transform2D transform;
	C_RectangleCollider collider;
	C_Sprite sprite;
};

#endif // !ROGUE

