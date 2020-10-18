#include "Scene0.h"

Player* player;
Skeleton* enemy;
MapLayer* mapA;


Scene0::Scene0()
{
	player = nullptr;
	enemy = nullptr;
	mapA = nullptr;
}

void Scene0::OnCreate()
{
	player = new Player("./Assets/Character/Sprites/adventurer-attack1-00.png", 100, 0);
	//player.Disable();
	GameObject::ObjHolder.push_back(player);
	enemy = new Skeleton(100, 30);
	enemy->SetTarget(player);
	GameObject::ObjHolder.push_back(enemy);
	//This just set the size of the game world
	mapA = new MapLayer(Game::actualWindow);
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
		isRunning = false;
		break;
	case SDL_KEYDOWN:
		player->keyPressed(true, event.key.keysym.sym);
		player->KeyBoardInput(player->InputKeyBoardHolder.begin()->first);
		//std::cout << "Key is still pressed" << std::endl;
		break;
	case SDL_KEYUP:
		player->keyPressed(false, event.key.keysym.sym);
		player->KeyBoardInput(player->InputKeyBoardHolder.begin()->first);
		break;
	case SDL_MOUSEBUTTONDOWN:
		player->MousePressed(true, event.button.button);
		player->MouseInput(player->InputMouseHolder.begin()->first);
	//	if (Game::actualWindow->MouseInput(event.button.button))
	//	mapA->keyCode = event.button.button;
		break;
	case SDL_MOUSEBUTTONUP:
		player->keyPressed(false, event.key.keysym.sym);
		player->MouseInput(player->InputMouseHolder.begin()->first);
		mapA->keyCode = event.button.button;
		break;
	}
}
void Scene0::HandleCollison()
{

}
	void Scene0::OnUpdate(float deltaTime_)
{
		cnt++;
		player->Update(deltaTime_);
		enemy->Update(deltaTime_);
		mapA->OnUpdate(deltaTime_);
}

	void Scene0::OnRender()
{
		SDL_RenderClear(Game::renderer);
		mapA->OnRender();
		player->Render();
		enemy->Render();
		Game::actualWindow->OnRender();
		SDL_RenderPresent(Game::renderer);
}


