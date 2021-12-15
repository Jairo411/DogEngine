#include "C_Sprite.h"
#include "../GameObject.h"
#include "../../TextureManager/TextureManager.h"
C_Sprite::C_Sprite()
{
	width = 0;
	height = 0;
	texture = nullptr;
	Objcast = nullptr;
}

C_Sprite::~C_Sprite()
{
}

void C_Sprite::OnCreate(BaseObj* owner_)
{
	Parent = owner_;
	Objcast = dynamic_cast<GameObject*>(owner_);

}

void C_Sprite::OnDestroy()
{
	Objcast = nullptr;
	texture = nullptr;
	delete texture;
	delete Objcast;
}

void C_Sprite::Update(float deltaTime_)
{
	Vec2 newPos = Objcast->getPosition();
	dstRect.x = newPos.x * deltaTime_;
	dstRect.y = newPos.y * deltaTime_;
	dstRect.w = SrcRect.w;
	dstRect.h = SrcRect.h;
}

void C_Sprite::FixedUpdate(float deltaTime_)
{

}

void C_Sprite::Render()
{
	Game::rendererManager->GetInstance()->GetRenderAPI<SDLRenderer*>()->DrawTexture(texture, &SrcRect, &dstRect);
}

void C_Sprite::SetTexture(const char* fileDirectory_)
{
	texture = TextureManager::LoadTexture(fileDirectory_);
}

void C_Sprite::SetImageSize(SDL_Rect src_)
{

	SrcRect = src_;

	dstRect.x = SrcRect.x;
	dstRect.y = SrcRect.y;
}
