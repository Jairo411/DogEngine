#include "Scene0.h"

Player* player;
Skeleton* enemy;
Skeleton* enemy0;
MapLayer* mapA;


Scene0::Scene0()
{
	player = nullptr;
	enemy = nullptr;
	mapA = nullptr;
}

void Scene0::OnCreate()
{
	player = new Player("./Assets/Character/Sprites/adventurer-attack1-00.png", 150, 150);
	enemy = new Skeleton(100, 30);
	enemy0 = new Skeleton(200, 50);
	enemy0->SetTarget(player);
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
		Game::setIsRunning(false);
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
	player->Update(deltaTime_);
	enemy->Update(deltaTime_);
	enemy0->Update(deltaTime_);
	mapA->OnUpdate(deltaTime_);

	std::cout << "X: " << player->getPosition().x << "Y: " << player->getPosition().y << std::endl;
}



void Scene0::OnRender()
{
	SDL_RenderClear(Game::renderer);
	mapA->OnRender();
	player->Render();
	enemy->Render();
	enemy0->Render();
	Game::actualWindow->OnRender();
	SDL_RenderPresent(Game::renderer);
}


