#include "C_RectangleCollider.h"
#include "../../Game/Game.h"
#include "../GameObject.h"



C_RectangleCollider::C_RectangleCollider()
{
	width = 0;
	height = 0;
	SquareCol = SDL_Rect();
	ObjCast = nullptr;
}

void C_RectangleCollider::OnCreate(BaseObj* owner_)
{
	Parent = owner_;
	ObjCast = dynamic_cast<GameObject*>(Parent);
	position= ObjCast->getPosition();
}

C_RectangleCollider::~C_RectangleCollider()
{
	OnDestroy();
}

void C_RectangleCollider::OnDestroy()
{
}

void C_RectangleCollider::Update(float deltatime)
{
	Vec2 newPos;
	newPos.x = ObjCast->getPosition().x * deltatime;
	newPos.y = ObjCast->getPosition().y * deltatime;
	newPos.x += (float)offsetX;
	SquareCol.x = newPos.x;
	SquareCol.y = newPos.y;
}

void C_RectangleCollider::FixedUpdate(float deltatime_)
{
}

void C_RectangleCollider::Render()
{
	Game::rendererManager->GetInstance()->GetRenderAPI<SDLRenderer*>()->DrawRect(&SquareCol);
}

void C_RectangleCollider::SetSize(int width_, int height_)
{
	width = width_;
	height = height_;

	offsetX = width / 2;
	offsetY = height / 2;

	SquareCol.x = position.x + (float)offsetX;
	SquareCol.y = position.y;

	SquareCol.w = width;
	SquareCol.h = height;
	

}
