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
	 void PlayAnimations(int state_);
private:  
	int posX;
	int posY;
	int amountOfAniamtions;
	int AnimState;
	bool disableObject;
//	vector<SDL_Texture*> run;
	SDL_Texture *objTexture;
	SDL_Rect srcRect, dstRect;
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

