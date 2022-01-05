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
ResourceManager* Game::resourceManager = nullptr;
bool Game::initialized = false;

bool Game::isRunning = false;


Game::Game()
{
	isRunning = true;

	///Singleton instantiation
	timer = Timer::GetInstance();
	sceneManager = SceneManager::GetInstance();
	window = Window::GetInstance();
	rendererManager = RendererManager::GetInstance();
	EngineSerializer = Serializer::GetInstance();
	textureManager = TextureManager::GetInstance();
	audioManager = AudioManager::GetInstance();
	resourceManager = ResourceManager::GetInstance();
	threadManager = ThreadManager::GetInstance();

	engineGUI = new GUI(); // I need to look into this 


	threadManager->setMaxAmountOfThreads(4);
	threadManager->AddThreadAble(this);
//	threadManager->StartThread(static_cast<Game*>(this)); //when using the std renderer you re-add this process
	
	audioManager->AddSong("./Martin Stig Andersen - Limbo (Original Videogame Soundtrack) - 01 Menu.wav");
	audioManager->playFirstSong();

	//Testing file locations 
	//ResoureAllocator<SDL_Texture*> tex = ResoureAllocator<SDL_Texture*>("./Assets/Character/Sprites/adventurer-attack1-00.png");
	//resourceManager->GetInstance()->AccessGenericContainer()->Push_Back <ResoureAllocator<SDL_Texture*>>(tex);

	

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

	timer->Start();
	timer->SetLogicLoopSpeed(60);
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
		
		Render(); // when everything has been finished render that is one call draw



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
	if (rendererManager->GetInstance()->getRenderValue() == 0)
	{
		//till I figure out why my engine keeps crashing when I do SDL clear calls here, ill leave this empty. 
	}
	else if (rendererManager->GetInstance()->getRenderValue() == 1)
	{
		rendererManager->GetInstance()->GetRenderAPI<OpenGLRenderer*>()->RefreshWindow();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	else if (rendererManager->GetInstance()->getRenderValue() == 2)
	{

	}
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
