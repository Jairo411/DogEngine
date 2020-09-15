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
<<<<<<< HEAD
<<<<<<< HEAD
	bool MouseEventListener(int event);
	SDL_Rect* getCollider();

||||||| 50f9777
	void MouseEventListener(int event);
=======
	bool MouseEventListener(int event);
	SDL_Rect* getCollider();
	Collider(int x_, int y_);
	void CollisonUpdate();
	//Only going to be used for game objects 
	void CollisonRender();

>>>>>>> 48d7615b797d99609e19fadd6cf40cd1ccacf523
||||||| c9d9634... 2020-09-03
	bool MouseEventListener(int event);
	SDL_Rect* getCollider();
=======
	void MouseEventListener(int event);
>>>>>>> parent of c9d9634... 2020-09-03
	/*make this into a virtual class possibly to add to the gameobjects doesn't seem like you need these enums 
	but because I look everything up online Im currently semi copying this stuff. 

	Its quite possible that you need to just simply use the gameobjects width and size in order to add collision to the objects 
	*/
<<<<<<< HEAD
<<<<<<< HEAD

||||||| 50f9777



=======
>>>>>>> 48d7615b797d99609e19fadd6cf40cd1ccacf523
||||||| c9d9634... 2020-09-03
=======



>>>>>>> parent of c9d9634... 2020-09-03
	/*Math Functions*/
<<<<<<< HEAD
<<<<<<< HEAD
//	SDL_Rect FindMidPointOfObject(SDL_Rect temp_,SDL_Rect temp1_);
//	SDL_Rect FindMidPointOfObject(int x1_, int x2_, int y1_, int y2_);
||||||| 50f9777
	SDL_Rect FindMidPointOfObject(SDL_Rect temp_,SDL_Rect temp1_);
	SDL_Rect FindMidPointOfObject(int x1_, int x2_, int y1_, int y2_);
=======
>>>>>>> 48d7615b797d99609e19fadd6cf40cd1ccacf523
||||||| c9d9634... 2020-09-03
//	SDL_Rect FindMidPointOfObject(SDL_Rect temp_,SDL_Rect temp1_);
//	SDL_Rect FindMidPointOfObject(int x1_, int x2_, int y1_, int y2_);
=======
	SDL_Rect FindMidPointOfObject(SDL_Rect temp_,SDL_Rect temp1_);
	SDL_Rect FindMidPointOfObject(int x1_, int x2_, int y1_, int y2_);
>>>>>>> parent of c9d9634... 2020-09-03
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
