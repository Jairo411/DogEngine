#ifndef ENEMY_H
#define ENEMY_H
#include "GameObject.h"
#include "../TextureManager/TextureManager.h"
#include "../Physics/Collider.h"
using namespace std;

/*This whole fucking class needs to be re-worked and have variables names that make sense*/
class Enemy: public GameObject
{
public:
	~Enemy();
	void Disable();
protected:
	/* You're gonna have to moves this to the Skeleton Class
		Because this shit is not modular in anyway possible*/
	int x, y;
	void ChangeSrcSize(int src_w, int src_h);
	template<typename T>
	inline void Pop_Front(vector<T>& v)
	{
		if (v.size() > 0)
		{
			v.erase(v.begin());
		}
	};
private:

	//Starting right here....
	/*This is called generics look it up, 
	  to see what it actually does please and thank you*/
	
	
};

class Skeleton : public Enemy
{
public:
	Skeleton(int x, int y);
	void Inti();
	void Update();
	void Render();
	void handleCollison();
private:
	Collider col;
	SDL_Rect srcRect0, destRect0;
	void PlayAnimations(int state_);
	enum Animations
	{
		ATTACK = 0,
		DEAD,
		HIT,
		IDLE,
		REACT,
		WALK
	};
};
#endif 