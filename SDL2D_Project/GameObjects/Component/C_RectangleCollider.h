#ifndef COMPONENTCOLLIDIER_H 
#define COMPONENTCOLLIDIER_H
#include "Component.h"
#include "../../Math/Vec2.h"
#include <SDL.h>
class GameObject;
class Game;
/*
* So the RectangleCollider works pretty simple. 
* Basically you input the size of the collider width and height.
* then it will intialize the collider. Using the GameObject Parent screen coordinates which are in unit pixels.
* The position of the rectangle is calculated by taking the GameObject's screen coords, and the GameObject's image width, then adding the image's width
* to the GameObject's screen coords. Which then pushes the retangle collider to be centered on, the GameObject's image. 
* Most of the time.
* obviously this intialize display, is just something to make development in the engine faster. 
*/
class C_RectangleCollider : public Component
{
public:
	C_RectangleCollider();
	virtual void OnCreate(BaseObj* owner_);
	virtual ~C_RectangleCollider();
	virtual void OnDestroy();
	virtual void Update(float deltatime_);
	virtual void FixedUpdate(float deltatime_);
	virtual void Render();
	void SetSize(int width_, int height_);
 private:
	int width, height;
	int offsetX, offsetY;
	Vec2 position; // the position of the rectangle, should be relative to the gameObject position 
	SDL_Rect SquareCol;
	GameObject* ObjCast; // each component should have a GameObject pointer, since all my components are suppose to connect to a game
};
#endif // !COMPONENTCOLLIDIER_H 
