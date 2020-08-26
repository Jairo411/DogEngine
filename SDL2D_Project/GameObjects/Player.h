#ifndef PLAYER_HEADER
#define PLAYER_HEADER


#include "GameObject.h"
#include "../Input/Input.h"

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
	 Player(const char * textureSheet, int x, int y);
	 ~Player();
	 void Update();
	 void Render();
	 void Disable();
	 bool keyBoardInput(int key);
	 bool mouseInput(int key);
	 bool controllerInput(int key);
	 Uint32 GetAnimTicks();
private:  
	int posX;
	int posY;
	int amountOfAniamtions;
	int AnimState;
	bool disableObject;
	Uint32 currentAnimTicks;
	Uint32 WaitAnimationsTicks(Uint32 wait_);
//	vector<SDL_Texture*> run;
	SDL_Texture *objTexture;
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

