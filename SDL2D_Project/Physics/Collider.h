#ifndef COLLIDER_H
#define COLLIDER_H
class Collider
{
	/*make this into a virtual class possibly to add to the gameobjects doesn't seem like you need these enums 
	but because I look everything up online Im currently semi copying this stuff. 

	Its quite possible that you need to just simply use the gameobjects width and size in order to add collision to the objects 
	*/
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
	Collider();
};

#endif // !COLLIDER_H
