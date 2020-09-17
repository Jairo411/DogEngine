#include "Game.h"

SDL_Rect* srcR, dstR;
Player* player;
Skeleton* enemy;
MapLayer* mapA;
SDL_Renderer* Game::renderer = nullptr;

TileSet* tileSet;

Game::Game()
{
	/*isRunning = false;
	std::shared_ptr<Scene0> gameScene0 = std::make_shared<Scene0>();

	unsigned int gameSceneID = sceneManager.Add(gameScene0);

	sceneManager.SwitchTo(gameSceneID);
	*/


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
		actualWindow = new Window(window);
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
		std::cout <<"Width: "<< actualWindow->getScreenWidth() <<" Height: "<<actualWindow->getScreenHeight() << std::endl;

	}
	else {
		isRunning = false;
	}


	player= new Player("Assets/Character/Sprites/adventurer-attack1-00.png",10,0);
	
//	GameObject::ObjHolder.push_back(player);;
	enemy = new Skeleton(30, 30);
//	GameObject::ObjHolder.push_back(enemy);
	//This just set the size of the game world
	mapA = new MapLayer("BaseLayer", 0, true,60,30);




}

void Game::HandleEvents()
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
		player->MousePressed(true, event.button.button);
		player->mouseInput(player->InputMouseHolder.begin()->first);
		if (actualWindow->mouseInput(event.button.button))
		{	
		}
		mapA->keyCode = event.button.button;
		break;
	case SDL_MOUSEBUTTONUP:
		player->keyPressed(false, event.key.keysym.sym);
		player->mouseInput(player->InputMouseHolder.begin()->first);
		break;
	default:
		break;
	}
	
}

void Game::OnUpdate()
{
	cnt++;

	player->Update();
	enemy->Update();
	mapA->OnUpdate();
	//cout << "Size of Obj holder: " << ObjHolder.size() << endl;


}

void Game::handleCollisions()
{
	Uint32 ticks;
	Uint32 seconds;
	Uint32 amountOfOBJs;
	ticks = SDL_GetTicks();
	seconds = ticks / 1;
	amountOfOBJs = seconds % GameObject::ObjHolder.size();

}

void Game::OnRender()
{
	SDL_RenderClear(renderer);
	mapA->OnRender();
	player->Render();
	enemy->Render();
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
