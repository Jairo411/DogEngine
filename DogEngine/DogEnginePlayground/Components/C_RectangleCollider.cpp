#include "../../DogEngine/DogEngineDefinitions.h"
#include "../../../DogEngine/DogEngine/DogEngine.h"
#include "../GameObjects/GameObject.h"
#include "C_RectangleCollider.h"



C_RectangleCollider::C_RectangleCollider()
{
	width = 0;
	height = 0;
	SquareCol = SDL_Rect();
	objCast = nullptr;
}

void C_RectangleCollider::OnCreate(BaseObj* owner_)
{
	Parent = owner_;
	objCast = dynamic_cast<GameObject*>(Parent);
	position= objCast->getPosition();
}

C_RectangleCollider::~C_RectangleCollider()
{
	OnDestroy();
}

void C_RectangleCollider::OnDestroy()
{
	objCast = nullptr;
	delete objCast;
}

void C_RectangleCollider::Update(float deltatime)
{
	DGEngine::core::vector2 newPos;
	newPos.x = objCast->getPosition().x * deltatime;
	newPos.y = objCast->getPosition().y * deltatime;
	newPos.x += (float)offsetX;
	SquareCol.x = (int)newPos.x;
	SquareCol.y = (int)newPos.y;
}

void C_RectangleCollider::Render()
{	
	DGEngine::core::DogEngine::rendererManager->GetInstance()->GetRenderAPI<SDLRenderer*>()->DrawRect(&SquareCol);
}

void C_RectangleCollider::SetSize(int width_, int height_)
{
	width = width_;
	height = height_;

	offsetX = width / 2;
	offsetY = height / 2;

	SquareCol.x = (int)position.x + (int)offsetX;
	SquareCol.y = (int)position.y;

	SquareCol.w = width;
	SquareCol.h = height;
	

}
