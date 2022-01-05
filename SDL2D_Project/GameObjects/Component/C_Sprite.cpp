#include "C_Sprite.h"
#include "../GameObject.h"
#include "../../TextureManager/TextureManager.h"
C_Sprite::C_Sprite()
{
	width = 0;
	height = 0;
	angle = 0.0;
	texture = nullptr;
	Objcast = nullptr;
	flipType = SDL_FLIP_HORIZONTAL;
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
//	Game::rendererManager->GetInstance()->GetRenderAPI<SDLRenderer*>()->DrawTexture(texture, &SrcRect, &dstRect);
	Game::rendererManager->GetInstance()->GetRenderAPI<SDLRenderer*>()->DrawTexture(texture, &SrcRect, &dstRect, angle, &center, flipType);
}

void C_Sprite::SetTexture(int id)
{
	assert((id < 0) && "Resource ID can't be less than zero");



}

void C_Sprite::SetTexture(std::string fileDirectory_)
{
	texture = TextureManager::LoadTexture(fileDirectory_.c_str());
	center.x = SrcRect.w / 2;
	center.y = SrcRect.h / 2;
}

void C_Sprite::SetImageSize(SDL_Rect src_)
{

	SrcRect = src_;

	dstRect.x = SrcRect.x;
	dstRect.y = SrcRect.y;
}
