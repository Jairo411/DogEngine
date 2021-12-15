#ifndef C_Sprite_H
#define C_Sprite_H
#include <SDL.h>
#include <SDL_image.h>
#include "Component.h"

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
	void SetTexture(const char* fileDirectory_ );
	void SetImageSize(SDL_Rect src_);
 private:
	int width;
	int height;
	SDL_Rect SrcRect, dstRect;
	GameObject* Objcast;
	SDL_Texture* texture;
};
#endif // !C_Sprite_H
