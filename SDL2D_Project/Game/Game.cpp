#include "Game.h"
#include "AI/AI.h"

SDL_Rect* srcR, dstR;
RendererManager* Game::rendererManager = nullptr;
Timer* Game::timer = nullptr;
Window* Game::window = nullptr;
Serializer* Game::EngineSerializer = nullptr;
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
	window->setWindowProperties(posx, posy, width, height, fullscreen);
	window->setWindowTitle(title);
	window->setFlag(NULL);
	window->OnCreate();
	rendererManager->GetInstance()->setWindow(window);
	rendererManager->GetInstance()->setRenderer(0);
	//	window->SetRenderer();
	isRunning = true;
	//if (fullscreen)
	//{
	//	flags = SDL_WINDOW_FULLSCREEN;
	//}

	//if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	//{
	//	std::cout << "Subsystem Initialised!..." << std::endl;
	////	windowProp->win = SDL_CreateWindow(title, posx, posy, width, height, flags);
	////	window->GetInstance()->setWindowProperties(*windowProp);
	//	
	//	if (window->GetInstance()->GetWindow())
	//	{
	//		std::cout << "Window created!" << std::endl;

	//	}
	//	else
	//	{
	//		throw std::runtime_error("Window Failed");
	//	//	std::cout <<&std::runtime_error::what << std::endl;
	//	}
	//	renderProp->renderer = SDL_CreateRenderer(window->GetInstance()->GetWindow(), -1,0);
	//	renderer->getInstance()->setRenderProp(*renderProp);
	//	if (renderer->getInstance()->getRenderer()!=nullptr)
	//	{
	//		SDL_SetRenderDrawColor(renderer->getInstance()->getRenderer(), 225, 225, 225, 225);
	//		std::cout << "Renderer Created!" << std::endl;
	//	}
	//	else
	//	{
	//		throw std::runtime_error("Renderer Failed");
	//	//	std::cout<<&std::runtime_error::what<<std::endl;
	//	}
	//	isRunning = true;
	//	std::cout << "Width: " << window->GetInstance()->getScreenWidth() << " Height: " << window->GetInstance()->getScreenHeight() << std::endl;

	std::shared_ptr<Scene0> gameScene = std::make_shared<Scene0>();

	unsigned int gameSceneID = sceneManager->Add(gameScene);

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

		timer->UpdateGeneralFrameTicks();
		HandleEvents();
		handleCollisions();
		FixedUpdate(timer->GetDeltaTime());// Physics Update happen through here anddd animations too. 
		Update(timer->GetDeltaTime()); // GameLogic happens all through this update.
		Render();

		passRenderFlag = rendererManager->getRenderValue();
	//	SDL_Delay(timer->GetSleepTime(FPS));
	}

	clean();

}

void Game::HandleEvents()
{
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
}

void Game::clean()
{
	SDL_DestroyWindow(window->getWindowContext());
	SDL_DestroyRenderer(rendererManager->GetRenderer<SDL_Renderer*>());
	delete this;
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}
