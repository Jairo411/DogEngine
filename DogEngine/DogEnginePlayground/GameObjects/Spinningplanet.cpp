#include "spinningplanet.h"

SpinningPlanet::SpinningPlanet()
{
	sprite = C_Sprite();

	sprite.OnCreate(this);

	sprite.SetTexture("./Assets/Debug_p/stillplanet.png");
	this->AddComponent<C_Sprite>(sprite);
}

SpinningPlanet::~SpinningPlanet()
{
}

void SpinningPlanet::OnCreate()
{
	
}

void SpinningPlanet::OnDestroy()
{
}

void SpinningPlanet::Render()
{
	this->GetComponent<C_Sprite>()->Render();
}

void SpinningPlanet::Update(float dt_)
{
}
