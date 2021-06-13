#include "Game.h"
#include "AI/AI.h"
SDL_Rect* srcR, dstR;
SDL_Renderer* Game::renderer = nullptr;
Timer* Game::timer = nullptr;
Window* Game::actualWindow = nullptr;
bool Game::isRunning = false;
std::string SceneName = "swagScene";

Game::Game()
{
	isRunning = true;
	timer = new Timer();
	sceneManager = new SceneManager();
	init("Andre's Quest ", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
}


bool Game::setIsRunning(bool tempBool_)
{
	isRunning = tempBool_;
	return isRunning;
}

Game::~Game()
{


}

void Game::init(const char* title, int posx, int posy, int width, int height, bool fullscreen)
{
	int flags = 0;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystem Initialised!..." << std::endl;
		actualWindow = new Window(SDL_CreateWindow(title, posx, posy, width, height, flags));
		
		if (actualWindow->GetWindow())
		{
			std::cout << "Window created!" << std::endl;

		}
		actualWindow->SetRenderer(SDL_CreateRenderer(actualWindow->GetWindow(), -1, 0));
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 225, 225, 225, 225);
			std::cout << "Renderer Created!" << std::endl;
		}
		isRunning = true;
		std::cout << "Width: " << actualWindow->getScreenWidth() << " Height: " << actualWindow->getScreenHeight() << std::endl;
	}
	else {
		isRunning = false;
	}

	std::shared_ptr<Scene0> gameScene = std::make_shared<Scene0>();

	unsigned int gameSceneID = sceneManager->Add(gameScene);

	timer->Start();
	sceneManager->SwitchTo(gameSceneID);
	GameLoop();


}
void Game::GameLoop()
{
	
	while (isRunning == true)
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
	sceneManager->HandleEvents();
}

void Game::OnUpdate(float deltaTime_)
{
	sceneManager->Update(deltaTime_);
}

void Game::handleCollisions()
{
	sceneManager->handleCollison();
}

void Game::OnRender()
{
	sceneManager->Render();
}

void Game::clean()
{
	SDL_DestroyWindow(actualWindow->GetWindow());
	SDL_DestroyRenderer(actualWindow->GetRenderer());
	delete this;
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}
