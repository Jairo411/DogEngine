#include "C_CircleCollider.h"
#include "../GameObjects/GameObject.h"
#include "../../DogEngine/DogEngine.h"

C_CircleCollider::C_CircleCollider()
{
	diameter = 0;
	radius = 0.0f;
	area = 0.0f;
	circumfrence = 0.0f;
	ObjCast = nullptr;
	origin = vector2();
}


void C_CircleCollider::OnCreate(BaseObj* owner_) 
{
	Parent = owner_;
	ObjCast = dynamic_cast<GameObject*>(Parent);
	origin = ObjCast->getPosition();
}

C_CircleCollider::~C_CircleCollider()
{
}

void C_CircleCollider::OnDestroy()
{
}

void C_CircleCollider::Update(float deltaTime_)
{
	vector2 newPos;
	newPos = ObjCast->getPosition()*deltaTime_;
	newPos.x += offSetX;
	newPos.y += offSetY;
	origin.x = newPos.x;
	origin.y = newPos.y;
}

void C_CircleCollider::Render()
{

	//DogEngine::rendererManager->GetRenderAPI<SDLRenderer*>()->DrawCircle(origin.x, origin.y, radius);
}

void C_CircleCollider::SetDistance(int radius_)
{
	radius = radius_;
	
	diameter = radius * 2;
	
	offSetX = diameter / 2;
	offSetY = diameter / 2;

	float pie2 = M_PI * 2;
	circumfrence = pie2 * radius;

	area = (radius * radius);
	area *= M_PI;



}
