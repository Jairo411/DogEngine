#ifndef CIRCLECOLLIDER_H
#define CIRCLECOLLIDER_H
#include "Component.h"
#include "../../Math/Vec2.h"
class GameObject;
class Game;
/*
*So the CircleCollider works almost the same as the RectangleCollider,
* we give this component the radius, which then allows us to intialize this Collider. 
* algebraically a circle inscribed within a square, has the same length in the diameter as any side of the square. diameter=side 
* so with this logic, I blit images to the screen using SDL_rect which are squares and rectangles (depending on the input I give it), 
* I can essentially cover my "Square SDL images" using that diameter logic. 
* Since some of the "Square" images aren't going to be squares, i'm purposfully adding some arbitrary values. 
* there is a relation with me getting the normal width of a square then substracting "yes I know SUBTRACTING" the width with pie. Don't know why it could just be magic.
* obviously this intialize colldier value that display the collider is just a intialization, with the engine support coming, it will just be something that might make things easier for
* the user.
*/
class C_CircleCollider : public Component
{
public:
	C_CircleCollider();
	virtual ~C_CircleCollider();
	virtual void OnCreate(BaseObj* owner_);	
	virtual void OnDestroy();
	virtual void Update(float deltaTime_);
	virtual void FixedUpdate(float DeltaTime_);
	virtual void Render();
	void SetDistance(int radius_); 

	
private:
	int diameter;
	int offSetX; 
	int offSetY;
	float radius;
	float area;
	float circumfrence;
	Vec2 origin;
	GameObject* ObjCast; 
};
#endif // !CIRCLECOLLIDER_H

