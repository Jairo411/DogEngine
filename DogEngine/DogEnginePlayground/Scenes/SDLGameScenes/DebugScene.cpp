#include "DebugScene.h"

SpriteMapData galaxySpriteMapData = SpriteMapData();
SDL_Rect srcRect = SDL_Rect();
SDL_Rect dstRect = SDL_Rect();
TextureInfo info = TextureInfo();
DebugScene::DebugScene()
{	
	/*Building my debugscene
	*/
	
	galaxySpriteMapData.height = 300;
	galaxySpriteMapData.width = 15000;
	galaxySpriteMapData.sizeOfCut = 300;
	galaxySpriteMapData.path = "C:/Users/jalbm/Documents/Visual Studio 2022/DogEngine/DogEngine/Assets/Map Sprites/galaxy_sp.png";

	
	info = DogEngine

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

	

	//DGEngine::core::DogEngine::GetInstance()->rendererManager->GetRenderAPI<SDLRenderer*>()->SetRenderDrawColour(200, 200, 200, 200);
	//DGEngine::core::DogEngine::GetInstance()->rendererManager->GetRenderAPI<SDLRenderer*>()->RenderClear();

	//DGEngine::core::DogEngine::GetInstance()->rendererManager->GetRenderAPI<SDLRenderer*>()->DrawTexture(info.texture, &srcRect, &dstRect);

	//DGEngine::core::DogEngine::GetInstance()->rendererManager->GetRenderAPI<SDLRenderer*>()->RenderPresent();

}

