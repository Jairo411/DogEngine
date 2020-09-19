#ifndef COLLIDER_H
#define COLLIDER_H
#include "SDL.h"
#include <math.h>
#include "Math/Vec2.h"
class Game;
class Collider
{
	// only need to use square colliders 
public:
	//for a collison rectangle/Square;

	Collider();
	Collider(int area_);//Square Collider
	Collider(int width_, int height_); //Rectangle Collider
	Collider(int x_, int y_, int size_);//Collider for semi static postions;
	//for a collison circle;
	//Collider(int d_);

	void CollisonUpdate(int colPosX_,int colPosY_);
	//Only going to be used for game objects 
	void CollisonRender();
	void SetCollisonObjectType(int col_);
	void SetCollisonType(int col);


	void MouseEventListener(int event);
	SDL_Rect* getCollider();
	//void CollisonUpdate();
	//Only going to be used for game objects 



	/*make this into a virtual class possibly to add to the gameobjects doesn't seem like you need these enums 
	but because I look everything up online Im currently semi copying this stuff. 

	Its quite possible that you need to just simply use the gameobjects width and size in order to add collision to the objects 
	*/
	~Collider(); 
	
private: 
	int x, y;
	int area;
	int collisonObjectType;
	int collisonType;
	SDL_Rect srcRect;
	Vec2 middlePoint;
	enum CollisonObjectType
	{
		NONE=0,
		GAMEOBJECT,
		Projectile
	};

	enum CollisonType
	{
		NO_COl=0,
		Game_COL,
		Projectile_COL,
		EventListener
	};
};

#endif // !COLLIDER_H
