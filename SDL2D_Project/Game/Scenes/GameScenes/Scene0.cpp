#include "Scene0.h"

Player* player;
Skeleton* enemy;
MapLayer* mapA;


Scene0::Scene0()
{
	
	//OnCreate();
}

void Scene0::OnCreate()
{
	player = new Player("./Assets/Character/Sprites/adventurer-attack1-00.png", 10, 0);
	//player.Disable();
	GameObject::ObjHolder.push_back(player);
	enemy = new Skeleton(100, 30);
	GameObject::ObjHolder.push_back(enemy);
	//This just set the size of the game world
	mapA = new MapLayer("BaseLayer", 0, true, 55, 35);
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
		player->keyBoardInput(player->InputKeyBoardHolder.begin()->first);
		//std::cout << "Key is still pressed" << std::endl;
		break;
	case SDL_KEYUP:
		player->keyPressed(false, event.key.keysym.sym);
		player->keyBoardInput(player->InputKeyBoardHolder.begin()->first);
		break;
	case SDL_MOUSEBUTTONDOWN:
		player->MousePressed(true, event.button.button);
		player->mouseInput(player->InputMouseHolder.begin()->first);
		if (Game::actualWindow->mouseInput(event.button.button))
		{
		}
		mapA->keyCode = event.button.button;
		break;
	case SDL_MOUSEBUTTONUP:
		player->keyPressed(false, event.key.keysym.sym);
		player->mouseInput(player->InputMouseHolder.begin()->first);
		mapA->keyCode = event.button.button;
		break;
	}
}
void Scene0::HandleCollison()
{
	Uint32 ticks;
	Uint32 seconds;
	Uint32 amountOfOBJs;
	ticks = SDL_GetTicks();
	seconds = ticks / 1;
	amountOfOBJs = seconds % GameObject::ObjHolder.size();
}
	void Scene0::OnUpdate()
{
		cnt++;
		player->Update();
		enemy->Update();
		mapA->OnUpdate();
}

	void Scene0::OnRender()
{
		SDL_RenderClear(Game::renderer);
		mapA->OnRender();
		player->Render();
		enemy->Render();
		//actualWindow->OnRender();
		SDL_RenderPresent(Game::renderer);
}


