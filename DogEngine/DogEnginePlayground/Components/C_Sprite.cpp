#include "C_Sprite.h"
#include "../../DogEngine/DogEngine.h"
#include "../GameObjects/GameObject.h"
C_Sprite::C_Sprite() : objCast(nullptr) ,spriteData(Spritedata())
{
}

C_Sprite::~C_Sprite()
{
}

void C_Sprite::OnCreate(BaseObj* owner_)
{
	Parent = owner_;
	objCast = dynamic_cast<GameObject*>(owner_);
}

void C_Sprite::OnDestroy()
{
	objCast = nullptr;
	delete objCast;
}

void C_Sprite::Update(float deltaTime_)
{
	vector2 newPos = objCast->getPosition();
	spriteData.rect.second.x = (int)newPos.x * deltaTime_; //casting newPos to int because SDLRect is in int
	spriteData.rect.second.y = (int)newPos.y * deltaTime_; // casting newPos to int because SDLREct is in int 
	/// <summary>
	///  DisplayRect.w = SourceRect.w;
	///  DisplayRect.h = SourceRect.h;
	/// </summary>
	/// <param name="deltaTime_"></param>
	spriteData.rect.second.w = spriteData.rect.first.w;
	spriteData.rect.second.h = spriteData.rect.first.h;
}


void C_Sprite::Render()
{
	RendererManager::GetInstance()->GetRenderAPI<SDLRenderer*>()->DrawTexture(spriteData.spriteTexture, &spriteData.rect.first, &spriteData.rect.second);
}

void C_Sprite::SetInfo(const Spritedata info_)
{
	spriteData = info_;
}

void C_Sprite::SetTexture(const char* p_)
{
	spriteData.spriteTexture = TextureManager::GetInstance()->LoadTexture(p_);
}

void C_Sprite::SetImageSize(SDL_Rect src_)
{

	spriteData.rect.first = src_;

	spriteData.rect.second.x = spriteData.rect.first.x;
	spriteData.rect.second.y = spriteData.rect.first.y;
}
