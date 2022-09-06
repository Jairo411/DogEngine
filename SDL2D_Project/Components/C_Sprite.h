#ifndef C_Sprite_H
#define C_Sprite_H
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "Component.h"
#include "../DogEngine/DogEngineDefinitions.h"
#include "../DogEngine/ResourceAllocator.h"
#include "../TextureManager/TextureManager.h"
class DogEngine;
class GameObject;
class C_Sprite : public Component
{
public:
	C_Sprite();
	virtual ~C_Sprite();
	virtual void OnCreate(BaseObj* owner_);
	virtual void OnDestroy();
	virtual void Update(float deltaTime_);
	virtual void Render();
	///full path to the file directory 
	void SetInfo(const SpriteInfo info_);
	void SetTexture(std::string fileDirectory_ ); //Remove this
	void SetImageSize(SDL_Rect src_); // Remove this
 private:
	SpriteRect spriteRect;
	SpriteInfo info;
	GameObject* objCast;
	ResoureAllocator<TextureInfo> assetInfo; //Remove this 
};





#endif // !C_Sprite_H
