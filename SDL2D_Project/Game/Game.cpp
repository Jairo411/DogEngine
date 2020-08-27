#include "Game.h"

SDL_Rect* srcR, dstR;
Player* player;
Skeleton* enemy;
MapLayer* mapA;
SDL_Renderer* Game::renderer = nullptr;
TileSet* tileSet;

Game::Game()
{

	
}


Game::~Game()
{


}

void Game::init(const char * title, int posx, int posy, int widith, int height, bool fullscreen)
{
	int flags = 0;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}


	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystem Initialised!..." << std::endl;
		window = SDL_CreateWindow(title, posx, posy, widith, height, flags);
		if (window)
		{
			std::cout << "Window created!" << std::endl;
			
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 225, 225, 225, 225);
			std::cout << "Renderer Created!" << std::endl;
		}
		isRunning = true;
		actualWindow = new Window(window);
		std::cout <<"Width: "<< actualWindow->getScreenWidth() <<" Height: "<<actualWindow->getScreenHeight() << std::endl;
		
	}
	else {
		isRunning = false;
	}
	player= new Player("Assets/Character/Sprites/adventurer-attack1-00.png",0,0);
	//player->setDisable(true);
	enemy = new Skeleton(30, 30);
	//This just set the size of the game world 
	mapA = new MapLayer("BaseLayer", 0, true,60,30);
	
	
	

		
}

void Game::handleEvents()
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
		player->keyPressed(false,event.key.keysym.sym);
		player->keyBoardInput(player->InputKeyBoardHolder.begin()->first);
		break;
	case SDL_MOUSEBUTTONDOWN:
		if (actualWindow->mouseInput(event.button.button))
		{
			
		} 
		if (player->mouseInput(event.button.button))
		{

		}
		break;
	case SDL_MOUSEBUTTONUP:
			player->mouseInput(NULL);
		
		break;
	default:
		break;
	}
}

void Game::update()
{
	cnt++;
	player->Update();
	enemy->Update();
	mapA->OnUpdate();
	
	

}

void Game::render()
{
	SDL_RenderClear(renderer);
	mapA->OnRender();
	player->Render();
	enemy->Render();
	actualWindow->OnRender();
	SDL_RenderPresent(renderer);
	
}

void Game::clean()
{
	delete player;
	delete mapA;
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	delete this;
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}
