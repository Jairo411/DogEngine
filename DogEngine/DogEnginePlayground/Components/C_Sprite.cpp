#include "C_Sprite.h"
#include "../DogEngine/DogEngine.h"
#include "../GameObjects/GameObject.h"
C_Sprite::C_Sprite() : objCast(nullptr) ,info(SpriteInfo())
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
	spriteRect.second.x = (int)newPos.x * deltaTime_; //casting newPos to int because SDLRect is in int
	spriteRect.second.y = (int)newPos.y * deltaTime_; // casting newPos to int because SDLREct is in int 
	/// <summary>
	///  DisplayRect.w = SourceRect.w;
	///  DisplayRect.h = SourceRect.h;
	/// </summary>
	/// <param name="deltaTime_"></param>
	spriteRect.second.w = spriteRect.first.w;
	spriteRect.second.h = spriteRect.first.h;
}


void C_Sprite::Render()
{
	SDL_Texture* tex = assetInfo.getResource()->texture;
	DogEngine::rendererManager->GetInstance()->GetRenderAPI<SDLRenderer*>()->DrawTexture(tex, &spriteRect.first, &spriteRect.second, info.angle, &info.center, info.flip);
}

void C_Sprite::SetInfo(const SpriteInfo info_)
{
	info = info_;
}

void C_Sprite::SetTexture(std::string fileDirectory_)
{
	assetInfo= TextureManager::LoadTexture(fileDirectory_.c_str());
	assetInfo.setFileDirectoryLocation(fileDirectory_);
}

void C_Sprite::SetImageSize(SDL_Rect src_)
{

	spriteRect.first = src_;

	spriteRect.second.x = spriteRect.first.x;
	spriteRect.second.y = spriteRect.first.y;
}
