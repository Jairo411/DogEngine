#ifndef COLLIDER_H
#define COLLIDER_H
class Collider
{
	// only need to use square colliders 
public:
	//for a collison rectangle/Square;
	Collider(int x_, int y_);
	void CollisonUpdate();
	//Only going to be used for game objects 
	void CollisonRender();

	/*make this into a virtual class possibly to add to the gameobjects doesn't seem like you need these enums 
	but because I look everything up online Im currently semi copying this stuff. 

	Its quite possible that you need to just simply use the gameobjects width and size in order to add collision to the objects 
	*/
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

};

#endif // !COLLIDER_H
