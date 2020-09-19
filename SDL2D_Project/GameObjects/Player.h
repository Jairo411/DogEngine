#ifndef PLAYER_HEADER
#define PLAYER_HEADER


#include "GameObject.h"
#include "../Input/Input.h"
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
	 void Update() override;
	 void Render() override;
	 void Disable() override;
	 void handleCollison();


	 bool KeyBoardInput(int key);
	 bool MouseInput(int key);
	 bool controllerInput(int key);

	 Uint32 GetAnimTicks();

private:  
	int posX;
	int posY;
	int amountOfAniamtions;
	int AnimState;
	bool disableObject;
	Collider collider;
	Uint32 FrameTicks;
	Uint32 WaitAnimationsTicks(Uint32 wait_);
	SDL_Rect endRect;
	GameObject* playerPtr;
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

