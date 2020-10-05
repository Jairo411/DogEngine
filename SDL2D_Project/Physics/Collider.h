#ifndef COLLIDER_H
#define COLLIDER_H
#include "SDL.h"
#include <math.h>
#include "Math/Vec2.h"
class Game;
class Collider
{
public:

	Collider(); //default Collider square
	Collider(int area_);//Square Collider
	Collider(int width_, int height_); //Rectangle Collider
	Collider(int x_, int y_, int size_);//Collider for semi static postions;
	//Collider(int d_); //for a collison circle;

	void CollisonUpdate(int colPosX_,int colPosY_);
	void CollisonRender();
	void SetCollisonObjectType(int col_);
	void SetCollisonType(int col);

	//TIGGER FOR COLLIDER
	void MouseEventListener(int event);

	SDL_Rect* getCollider();
	~Collider(); 
	
private: 
	int x, y;
	int collisonObjectType;
	int collisonType;
	SDL_Rect srcRect;
	Vec2 middlePoint;

	//TYPE OF COLLIDER
	enum CollisonObjectType
	{
		NONE=0,
		GAMEOBJECT,
		Projectile
	};
	//TYPE OF COLLISION
	enum CollisonType
	{
		NO_COl=0,
		Game_COL,
		Projectile_COL,
		EventListener
	};
};

#endif // !COLLIDER_H
