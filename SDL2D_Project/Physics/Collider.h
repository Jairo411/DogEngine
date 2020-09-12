#ifndef COLLIDER_H
#define COLLIDER_H
#include "SDL.h"
#include <math.h>
class Game;
class Collider
{
	// only need to use square colliders 
public:
	//for a collison rectangle/Square;
	Collider();
	Collider(int PosX, int PosY,int size_);//Square Collider
	//for a collison circle;
	Collider(int d_);

	void CollisonUpdate(int colPosX_,int colPosY_);
	//Only going to be used for game objects 
	void CollisonRender();
	void SetCollisonObjectType(int col_);
	void SetCollisonType(int col);
	bool MouseEventListener(int event);
	SDL_Rect* getCollider();
	Collider(int x_, int y_);
	void CollisonUpdate();
	//Only going to be used for game objects 
	void CollisonRender();

	/*make this into a virtual class possibly to add to the gameobjects doesn't seem like you need these enums 
	but because I look everything up online Im currently semi copying this stuff. 

	Its quite possible that you need to just simply use the gameobjects width and size in order to add collision to the objects 
	*/
	/*Math Functions*/
	~Collider();

private: 
	int x, y;
	int area;
	int collisonObjectType;
	int collisonType;
	SDL_Rect srcRect;
	enum ColiderObject
	{
		NONE = 0,
		GAMEOBJECT,
		MOUSE,
	};
private: 
	int x, y;
	int area;
	enum CollisonObject 
	{
		Default=0,
		GameObject
	};
	enum CollisonType
	{
		Projectile = 0,
		Fall
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
