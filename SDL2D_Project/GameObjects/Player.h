#ifndef PLAYER_HEADER
#define PLAYER_HEADER


#include "GameObject.h"
#include "C:/Users/jalbm/Desktop/SDL2D_Project-0e609616605a8522d711653b03805e45f7af73e8/SDL2D_Project/Input/Input.h"
#include "../Physics/Collider.h"

/*
Player class, tasks that should be done 
-add antimation.
-might need to add physics (box coliders)
Basic functionality ^^^^
********************
Advance Functionality 
-To be written down here.
*/

class TextureManager;
class Player : public GameObject , public Input 
{
public:
	Player();
	 Player(const char * textureSheet, int x, int y);
	 ~Player();
	 void Update();
	 void Render();
	 void Disable();
<<<<<<< HEAD

||||||| 50f9777
	 void handleCollison();
=======
<<<<<<< HEAD
	 void handleCollison();
	 bool keyBoardInput(int key) override;
	 bool mouseInput(int key) override;
	 bool controllerInput(int key) override;
=======
>>>>>>> 48d7615b797d99609e19fadd6cf40cd1ccacf523
	 bool keyBoardInput(int key);
	 bool mouseInput(int key);
	 bool controllerInput(int key);
<<<<<<< HEAD


||||||| 50f9777
=======
>>>>>>> parent of 50f9777... 2020-09-01 1:52
>>>>>>> 48d7615b797d99609e19fadd6cf40cd1ccacf523
	 Uint32 GetAnimTicks();
private:  
	int posX;
	int posY;
	int amountOfAniamtions;
	int AnimState;
	bool disableObject;
	Collider collider;
	Uint32 currentAnimTicks;
	Uint32 WaitAnimationsTicks(Uint32 wait_);
	SDL_Rect endRect;
	void PlayAnimations(int state_);
	
	enum AnimationsStates
	{
		ATTACK0=0,
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

	
};
#endif // !PLAYER_HEADER

