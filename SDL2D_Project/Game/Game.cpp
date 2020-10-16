#include "Game.h"

SDL_Rect* srcR, dstR;
Player* player;
Skeleton* enemy;
MapLayer* mapA;
SDL_Renderer* Game::renderer = nullptr;
Timer* Game::timer = nullptr;

TileSet* tileSet;



Game::Game()
{
	isRunning = true;
	timer = new Timer();
	actualWindow = new Window();
	init("Andre's Quest ", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
}



Game::~Game()
{


}

void Game::init(const char * title, int posx, int posy, int width, int height, bool fullscreen)
{
	int flags = 0;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystem Initialised!..." << std::endl;
		window = SDL_CreateWindow(title, posx, posy, width, height, flags);
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


	
	player= new Player("Assets/Character/Sprites/adventurer-attack1-00.png",400,200);

	enemy = new Skeleton(30, 30);
	enemy->SetTarget(player);
	//This just set the size of the game world
	mapA = new MapLayer(actualWindow);

	timer->Start();
	GameLoop();


}
void Game::GameLoop()
{
;
	while (isRunning==true)
	{
		timer->UpdateGeneralFrameTicks();
		HandleEvents();
		handleCollisions();
		OnRender();
		OnUpdate(timer->GetDeltaTime());
		SDL_Delay(timer->GetSleepTime(FPS));
	}
	
	clean();

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
		player->KeyBoardInput(player->InputKeyBoardHolder.begin()->first);
				//std::cout << "Key is still pressed" << std::endl;
		break;
	case SDL_KEYUP:
		player->keyPressed(false,event.key.keysym.sym);
		player->KeyBoardInput(player->InputKeyBoardHolder.begin()->first);
		break;
	case SDL_MOUSEBUTTONDOWN:
		player->MousePressed(true, event.button.button);
		player->MouseInput(player->InputMouseHolder.begin()->first);
		if (actualWindow->MouseInput(event.button.button))
		{	
		}
		mapA->keyCode = event.button.button;
		break;
	case SDL_MOUSEBUTTONUP:
		player->keyPressed(false, event.key.keysym.sym);
		player->MouseInput(player->InputMouseHolder.begin()->first);
		break;
	default:
		break;
	}
	
}

void Game::OnUpdate(float deltaTime_)
{
	cnt++;
	player->Update(deltaTime_);
	enemy->Update(deltaTime_);
	mapA->OnUpdate(deltaTime_);
	Vec2 tempV = player->getPosition();// put this either inside the Player class or window Class 
	Vec2 enemyPos = enemy->getPosition();

	cout << "Enemy Pos" << endl;
	//cout << "X:" << enemyPos.x << " Y: " << enemyPos.y << endl;
	//cout << "Player Pos" << endl;
	//cout << "X: " <<tempV.x<<"Y: "<<tempV.y << endl;
	//cout << "Size of Obj holder: " << GameObject::ObjHolder.size() << endl;


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
	player->DrawLine(player->getPosition(), enemy->getPosition());
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
