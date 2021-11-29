#include "Game.h"
#include "AI/AI.h"

SDL_Rect* srcR, dstR;
RendererManager* Game::rendererManager = nullptr;
Timer* Game::timer = nullptr;
Window* Game::window = nullptr;
Serializer* Game::EngineSerializer = nullptr;
TextureManager* Game::textureManager = nullptr;
SceneManager* Game::sceneManager = nullptr;
ThreadManager* Game::threadManager = nullptr;
AudioManager* Game::audioManager = nullptr;
bool Game::initialized = false;

bool Game::isRunning = false;


Game::Game()
{
	isRunning = true;
	timer = Timer::GetInstance();//Im making all of these managers /Single entity type classes as singletons
	sceneManager = SceneManager::GetInstance();
	window = Window::GetInstance();
	rendererManager = RendererManager::GetInstance();
	EngineSerializer = Serializer::GetInstance();
	textureManager = TextureManager::GetInstance();
	audioManager = AudioManager::GetInstance();
	engineGUI = new GUI(); // I need to look into this 
	threadManager = ThreadManager::GetInstance();
	threadManager->setMaxAmountOfThreads(4);
	threadManager->AddThreadAble(sceneManager);
	threadManager->StartThread(static_cast<ThreadAble*>(sceneManager));
//	threadManager->StartThreadA<Game*>(static_cast<ThreadAble*>(this),this);
	
	audioManager->AddSong("./Martin Stig Andersen - Limbo (Original Videogame Soundtrack) - 01 Menu.wav");
	audioManager->playFirstSong();


	//threadManager->AddThreadA<eneManager*>(sceneManager);
	//threadManager->AddThreadAble(static_cast<ThreadAble*>(sceneManager));
	//threadManager->StartThread(static_cast<ThreadAble*>(sceneManager));

	initialized = false;	
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

//	timer->SetFPS(60);
	timer->Start();
	timer->SetLogicLoopSpeed(60);
	sceneManager->SwitchTo(gameSceneID);
	//threadManager->StartThread(static_cast<ThreadAble*>(sceneManager), call);
	GameLoop();


}
void Game::OnDestroy()
{
}
void Game::GameLoop()
{
	int currentRenderFlag = NULL;
	int passRenderFlag = NULL;

	///TEST ZONEEEEE

	currentRenderFlag = rendererManager->getRenderValue();

	//static_cast<ThreadAble*>(sceneManager)->setThreadAble(true);
	//std::thread t1 = static_cast<ThreadAble*>(sceneManager)->createThread();

	///TEST ZONEEEEE 


	while (isRunning == true)
	{
		if (currentRenderFlag != rendererManager->getRenderValue())
		{
			currentRenderFlag = passRenderFlag;

			rendererManager->OnDestroy();

			rendererManager->OnCreate();
			rendererManager->setRenderer(currentRenderFlag);
		}
		timer->UpdateSteadyClock();
		timer->UpdatePerformanceClock();

		handleCollisions();
		HandleEvents(); // I handle my input here 

		timer->IncrementUpdateLag(timer->GetDelta());


		while (timer->GetUpdateLag()>=timer->getMS_Machine_Update())
		{

			double positiveTimeValue = timer->getMS_Machine_Update();

//			FixedUpdate(positiveTimeValue);// Physics Update happen through here anddd animations too. 

			Update(positiveTimeValue); // GameLogic happens all through this update.


			double negativeTimeValue = timer->getMS_Machine_Update() * -1.0;

			timer->IncrementUpdateLag(negativeTimeValue); //reason I have to create a temp negative variable is because my setUpdateLag function has += operator when setting values, so I have to add a negative nun
		}	
		
	//	Render(); // when everything has been finished render that is one call draw



		passRenderFlag = rendererManager->getRenderValue();
	}

	clean();

}

void Game::HandleEvents()
{
	/*SceneManager handleEvents is spefically for events that I set up for that current Scene*/
	window->HandleEvents();
	sceneManager->HandleEvents();

	if (window->getIsClose())
	{
		clean();
	}
}

void Game::Update(float deltaTime_)
{
	sceneManager->Update(deltaTime_);
	window->Update(deltaTime_);
	//std::cout << "Machine Updating: " << timer->GetDelta() << std::endl;
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
	timer->IncrementFrames();

}

void Game::clean()
{
	SDL_DestroyWindow(window->getWindowContext());
	SDL_DestroyRenderer(rendererManager->GetRenderAPI<SDLRenderer*>()->GetRenderer());
	threadManager->StopThread(static_cast<ThreadAble*>(sceneManager));
	delete this;
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}
