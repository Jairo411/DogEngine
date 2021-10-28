#include "Game.h"
#include "AI/AI.h"

SDL_Rect* srcR, dstR;
RendererManager* Game::rendererManager = nullptr;
Timer* Game::timer = nullptr;
Window* Game::window = nullptr;
Serializer* Game::EngineSerializer = nullptr;
TextureManager* Game::textureManager = nullptr;
bool Game::isRunning = false;


Game::Game()
{
	isRunning = true;
	timer = new Timer(); //Im making all of these managers /Single entity type classes as singletons
	sceneManager = new SceneManager();
	window = Window::GetInstance();
	rendererManager = RendererManager::GetInstance();
	EngineSerializer = Serializer::GetInstance();
	textureManager = TextureManager::getInstance();
	engineGUI = new GUI();
	OnCreate("Andre's Quest ", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
}



bool Game::setIsRunning(bool tempBool_)
{
	isRunning = tempBool_;
	return isRunning;
}

Game::~Game()
{


}

void Game::OnCreate(const char* title, int posx, int posy, int width, int height, bool fullscreen)
{
	int flags = 0;
	window->setWindowProperties(posx, posy, width, height, fullscreen);
	window->setWindowTitle(title);
	window->setFlag(NULL);
	window->OnCreate();
	rendererManager->GetInstance()->setWindow(window);
	rendererManager->GetInstance()->setRenderer(0);
	window->SetGUI(engineGUI);

	isRunning = true;


	std::shared_ptr<Scene0> gameScene = std::make_shared<Scene0>();

	unsigned int gameSceneID = sceneManager->Add(gameScene);

	timer->SetFPS(60);
	timer->Start();
	sceneManager->SwitchTo(gameSceneID);
	GameLoop();


}
void Game::OnDestroy()
{
}
void Game::GameLoop()
{
	int currentRenderFlag = NULL;
	int passRenderFlag = NULL;

	currentRenderFlag = rendererManager->getRenderValue();
	while (isRunning == true)
	{
		if (currentRenderFlag !=rendererManager->getRenderValue())
		{
			currentRenderFlag = passRenderFlag;

			rendererManager->OnDestroy();
			
			rendererManager->OnCreate();
			rendererManager->setRenderer(currentRenderFlag);
		}

		timer->UpdateSteadyClock();
		timer->UpdatePerformanceClock();
		HandleEvents();
		handleCollisions();
		FixedUpdate(timer->GetDelta());// Physics Update happen through here anddd animations too. 
		Update(timer->GetDelta()); // GameLogic happens all through this update.
		Render();
		passRenderFlag = rendererManager->getRenderValue();
	//	SDL_Delay(timer->GetSleepTime(FPS));
	}

	clean();

}

void Game::HandleEvents()
{
	SDL_Event e;

	SDL_PollEvent(&e);
	switch (e.type)
	{
	default:
		break;
	case SDL_WINDOWEVENT: 
		if (e.window.type == SDL_WINDOWEVENT_CLOSE)
		{

		}
		break;
	}
	
	sceneManager->HandleEvents();
}

void Game::Update(float deltaTime_)
{
	sceneManager->Update(deltaTime_);
}

void Game::FixedUpdate(float deltaTime_)
{
	sceneManager->FixedUpdate(deltaTime_);
}

void Game::handleCollisions()
{
	sceneManager->handleCollison();
}

void Game::Render()
{
	sceneManager->Render();
	
	rendererManager->GetInstance()->incrementFrames();
}

void Game::clean()
{
	SDL_DestroyWindow(window->getWindowContext());
	SDL_DestroyRenderer(rendererManager->GetRenderAPI<SDLRenderer*>()->GetRenderer());
	delete this;
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}
