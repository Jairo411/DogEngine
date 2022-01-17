#ifndef COLLIDER_H
#define COLLIDER_H
#include "SDL.h"
#include <math.h>
#include <vector>
#include <string>
#include "../Math/Vec2.h"
/*2021-07-09
	probably going to get rid of this class,yah.*/
class DogEngine;
class RectCollider
{
public:

	RectCollider(); //default Collider square
	RectCollider(int squareArea_);//Square Collider
	RectCollider(int width_, int height_); //Rectangle Collider
	RectCollider(int width_, int height_, const char* colliderName_);
	RectCollider(int x_, int y_, int size_);// Square Collider for static postions;
	RectCollider(int x_, int y_, int size_, const char* colliderName_);

	void CollisonUpdate(int colPosX_,int colPosY_); // don't use this 
	void CollisonUpdate(Vec2 position_);
	void CollisonRender();
	void SetCollisonObjectType(int col_);
	void SetCollisonType(int col);

	//TIGGER FOR COLLIDER
	void MouseEventListener(int event);

	SDL_Rect* getCollider();
	~RectCollider(); 
	
private: 
	int x, y;
	int collisonObjectType;
	int collisonType;
	SDL_Rect srcRect;
	Vec2 middlePoint;
	std::string tag;
	

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


class CircleCollider
{
public:
	CircleCollider();
	CircleCollider(float radius_); // GameObjects that move
	CircleCollider(int x_, int y_, float radius_); // static positions 
	void Update(Vec2 position_);
	void Render();
	~CircleCollider();
private:
	std::vector<Vec2> positions;
	float oX, oY; // Origin of the circle 
	float x, y;
	float radius;//radius 
};

#endif // !COLLIDER_H
