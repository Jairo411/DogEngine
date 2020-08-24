#ifndef ENEMY_H
#define ENEMY_H
#include "GameObject.h"
#include "../TextureManager/TextureManager.h"
using namespace std;

/*This whole fucking class needs to be re-worked and have variables names that make sense*/
class Enemy: public GameObject
{
public:
	Enemy(int x, int y);

	void Update();
	void Render();
	void Disable();
	bool setDisable();
	bool getDisable();
protected:
	/* You're gonna have to moves this to the Skeleton Class
		Because this shit is not modular in anyway possible*/
	enum Animations 
	{
		ATTACK=0,
		DEAD,
		HIT,
		IDLE,
		REACT,
		WALK
	};
private:
	void inti();
	//Keep this 
	void PlayAnimations(int state_);
	//you probably are gonna get rid of the imageSetHolder
	//map<int, SDL_Texture*> imageSetHolder;
	//Starting right here....
	SDL_Rect srcRect0, destRect0;
};

class Skeleton : public Enemy
{
public:
	Skeleton();


};
#endif