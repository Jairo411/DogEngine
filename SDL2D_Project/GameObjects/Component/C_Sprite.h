#ifndef C_Sprite_H
#define C_Sprite_H
#include <SDL.h>
#include <SDL_image.h>
#include "Component.h"
#include "../../Game/ResourceAllocator.h"
class TextureManager;
class GameObject;
class C_Sprite : public Component
{
public:
	C_Sprite();
	virtual ~C_Sprite();
	virtual void OnCreate(BaseObj* owner_);
	virtual void OnDestroy();
	virtual void Update(float deltaTime_);
	virtual void FixedUpdate(float deltaTime_);
	virtual void Render();
	void SetTexture(int id);
	void SetTexture(const char* fileDirectory_ );
	void SetImageSize(SDL_Rect src_);
 private:
	int width;
	int height;
	double angle;
	SDL_RendererFlip flipType;
	SDL_Rect SrcRect, dstRect;
	SDL_Point center;
	GameObject* Objcast;
	SDL_Texture* texture;
};





#endif // !C_Sprite_H
