#include "Scene0.h"


Player* player;
Skeleton* enemy;
Skeleton* enemy0;
Skeleton* enemy1;
MapLayer* mapA;

Scene0::Scene0()
{
	player = nullptr;
	enemy = nullptr;
	mapA = nullptr;

}

Scene0::~Scene0()
{
}

void Scene0::OnCreate()
{
	/* Intial Object Creations*/
	player = new Player("./Assets/Character/Sprites/adventurer-attack1-00.png", 0, 0);
	enemy = new Skeleton(180, 100);
	enemy0 = new Skeleton(300, 50);
	enemy1 = new Skeleton(400, 200);

	/*Observer Pattern Implemented*/
	enemy->Attach(new GameObserver(enemy));
	enemy0->Attach(new GameObserver(enemy0));
	enemy1->Attach(new GameObserver(enemy1));

	/*Observer Pattern Implemented*/
	mapA = new MapLayer(Game::actualWindow);

	/* Setting GameObject Functionality*/
	enemy->SetTarget(player);
	enemy0->SetTarget(player);
	Game::AI_Manager->getInstance()->getTotalAgents();
	//Game::AI_Manager->getInstance()->setPath(dynamic_cast<AI*>(enemy1),mapA->getTiles(), 200);
	
	

}

void Scene0::OnDestroy()
{

}

void Scene0::HandleEvents()
{
	SDL_Event event;

	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		Game::setIsRunning(false);
		break;
	case SDL_KEYDOWN:
		player->keyPressed(true, event.key.keysym.sym);
		player->KeyBoardInput(player->InputKeyBoardHolder.begin()->first);
		break;
	case SDL_KEYUP:
		player->keyPressed(false, event.key.keysym.sym);
		player->KeyBoardInput(player->InputKeyBoardHolder.begin()->first);
		if (SDLK_0)
		{
			enemy->Remove();
		}
		break;
	case SDL_MOUSEBUTTONDOWN:
		player->MousePressed(true, event.button.button);
		player->MouseInput(player->InputMouseHolder.begin()->first);
		//	if (Game::actualWindow->MouseInput(event.button.button))
		//	mapA->keyCode = event.button.button;
		Game::actualWindow->SetGUIEvent(&event);
		break;
	case SDL_MOUSEBUTTONUP:
		player->keyPressed(false, event.key.keysym.sym);
		player->MouseInput(player->InputMouseHolder.begin()->first);
		break;
	}
}
void Scene0::HandleCollison()
{

}
void Scene0::OnUpdate(float deltaTime_)
{
	player->Update(deltaTime_);
	enemy->Update(deltaTime_);
	enemy0->Update(deltaTime_);
	enemy1->Update(deltaTime_);
	mapA->OnUpdate(deltaTime_);
	Game::AI_Manager->getInstance()->OnUpdate(deltaTime_);
	Game::actualWindow->OnUpdate();
}



void Scene0::OnRender()
{
	{
		SDL_SetRenderDrawColor(Window::RenderContext->renderer, 225, 225, 225, 255);
	}
	SDL_RenderClear(Window::RenderContext->renderer);
	mapA->OnRender();
	player->Render();
	enemy->Render();
	enemy0->Render();
	enemy1->Render();
	Game::actualWindow->OnRender();
	SDL_RenderPresent(Window::RenderContext->renderer);
}
