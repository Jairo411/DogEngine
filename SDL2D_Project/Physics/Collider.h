#ifndef COLLIDER_H
#define COLLIDER_H
#include "SDL.h"
#include <math.h>
#include <vector>
#include "../Math/Vec2.h"
class Game;
class RectCollider
{
public:

	RectCollider(); //default Collider square
	RectCollider(int squareArea_);//Square Collider
	RectCollider(int width_, int height_); //Rectangle Collider
	RectCollider(int x_, int y_, int size_);// Square Collider for static postions;

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
