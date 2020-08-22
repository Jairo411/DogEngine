#include "Game.h"

SDL_Texture* playerTex;
SDL_Rect* srcR, dstR;
Player* player;
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
		if (player->keyBoardInput(event.key.keysym.sym))
		{
				std::cout << "Key is still pressed" << std::endl;
			
		}
		// Creating my Debug system when I press t, Ill be able to test certain functionality that I wouldn't be able to naturally. 
		else if (player->keyBoardInput(event.key.keysym.scancode) == SDL_SCANCODE_T)
		{

		}
		//std::cout << "Keys Down" << event.key.keysym.sym << std::endl;
		break;
	case SDL_MOUSEBUTTONDOWN:
		if (actualWindow->mouseInput(event.button.button))
		{
		}
		if (player->mouseInput(event.button.button))
		{

		}
	default:
		break;
	}
}

void Game::update()
{
	cnt++;
	player->Update();

	

}

void Game::render()
{
	SDL_RenderClear(renderer);
	mapA->OnUpdate();
	player->Render();
	//actualWindow->OnRender();
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
