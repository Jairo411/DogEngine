#include "DebugScene.h"
#include "../../../DogEngine/DogEngine.h"


DebugScene::DebugScene()
{	
	/*Building my debugscene
	*/
	

	
	//planet0 = SpinningPlanet();


	AudioManager::GetInstance()->playFirstSong();
	SDL_RendererInfo* info = new SDL_RendererInfo();
	SDL_GetRenderDriverInfo(0, info);

	std::cout << info->name << std::endl;
	stillplanet = TextureManager::LoadTexture("./Assets/Debug_p/stillplanet.png");

	
}

DebugScene::~DebugScene()
{
}

void DebugScene::OnCreate()
{
}

void DebugScene::OnDestroy()
{
}

void DebugScene::OnActivate()
{
}

void DebugScene::OnDeactivate()
{
}

void DebugScene::HandleEvents()
{
}

void DebugScene::HandleCollison()
{

}

void DebugScene::Update(float deltaTime_)
{
}

void DebugScene::Render()
{
	SDL_SetRenderDrawColor(RendererManager::GetInstance()->GetRenderAPI<SDLRenderer*>()->GetRenderer(), 0, 0, 0, 0);
	
	RendererManager::GetInstance()->GetRenderAPI<SDLRenderer*>()->DrawTexture(stillplanet, NULL, NULL);
	




	

}

