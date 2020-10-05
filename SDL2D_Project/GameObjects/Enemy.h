#ifndef ENEMY_H
#define ENEMY_H
#include "GameObject.h"
#include "../TextureManager/TextureManager.h"
#include "../Physics/Collider.h"
#include "../Game/AI/AI.h"

using namespace std;

class Game;
class Enemy: public GameObject
{
public:
	~Enemy();
	void Disable();
protected:
	int x, y; // this is going to be removed soon...
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
	//Could enter generics here 
};

class Skeleton : public Enemy, public AI
{
public:
	Skeleton();
	Skeleton(int x, int y);
	~Skeleton();
	void Inti();
	void Update(float deltaTime_);
	void Render();
	void handleCollison();
	void UpdateAI();
	void SetTarget(Vec2 target_);
	
private:
	float speed;
	Vec2 targetPos;
	Collider col;	
	SDL_Rect srcRect0, destRect0;
	void PlayAnimations(int state_);
	Vec2 getTarget();
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
