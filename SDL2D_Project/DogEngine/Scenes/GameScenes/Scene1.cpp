#include "Scene1.h"

Scene1::Scene1()
{
}

Scene1::~Scene1()
{
}

void Scene1::OnCreate()
{

}

void Scene1::OnDestroy()
{
}

void Scene1::OnActivate()
{
}

void Scene1::OnDeactivate()
{
}

void Scene1::HandleEvents()
{
}

void Scene1::HandleCollison()
{
}

void Scene1::Update(float deltaTime_)
{
}


void Scene1::Render()
{
	DogEngine::rendererManager->GetInstance()->GetRenderAPI<SDLRenderer*>()->RenderPresent();
	DogEngine::rendererManager->GetInstance()->GetRenderAPI<SDLRenderer*>()->SetRenderDrawColour(100,30,40,100);
	DogEngine::rendererManager->GetInstance()->GetRenderAPI<SDLRenderer*>()->RenderClear();

}
