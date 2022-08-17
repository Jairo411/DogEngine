#include "DogEngine.h"
#include "AI/AI.h"

SDL_Rect* srcR, dstR;
RendererManager* DogEngine::rendererManager = nullptr;
Timer* DogEngine::timer = nullptr;
Window* DogEngine::window = nullptr;
Serializer* DogEngine::EngineSerializer = nullptr;
TextureManager* DogEngine::textureManager = nullptr;
SceneManager* DogEngine::sceneManager = nullptr;
ThreadManager* DogEngine::threadManager = nullptr;
AudioManager* DogEngine::audioManager = nullptr;
ObjectManager* DogEngine::GameObjectManager = nullptr;
bool DogEngine::initialized = false;

bool DogEngine::isRunning = false;


DogEngine::DogEngine()
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
	threadManager = ThreadManager::GetInstance();
	GameObjectManager = ObjectManager::GetInstance();

	engineGUI = new GUI(); // I need to look into this 
	event_ = new SDL_Event();

	threadManager->setMaxAmountOfThreads(4);
	threadManager->AddThreadAble(this);
//	threadManager->StartThread(static_cast<Game*>(this)); //when using the std renderer you re-add this process
	
	audioManager->AddSong("./Martin Stig Andersen - Limbo (Original Videogame Soundtrack) - 01 Menu.wav");
	audioManager->playFirstSong();

	//Testing file locations 
	//ResoureAllocator<SDL_Texture*> tex = ResoureAllocator<SDL_Texture*>("./Assets/Character/Sprites/adventurer-attack1-00.png");
	//resourceManager->GetInstance()->AccessGenericContainer()->Push_Back <ResoureAllocator<SDL_Texture*>>(tex);

	//Test environment
	//FileDirectoryHandler fileDirectory;
	//std::string filePath;
	//filePath = "./Assets/Character/Sprites";
	//fileDirectory.ChangeDirectory(filePath);
	//fileDirectory.PrintDirectoryContents();
	//fileDirectory.PrintDirectoryPath();
	//system("pause");
	//Test environment

	initialized = false;	
	OnCreate("DogEngine 0.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
}




bool DogEngine::setIsRunning(bool tempBool_)
{
	isRunning = tempBool_;
	return isRunning;
}



DogEngine::~DogEngine()
{


}

void DogEngine::OnCreate(const char* title, int posx, int posy, int width, int height, bool fullscreen)
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

	//Use gameScene when testing out scene features. 
	//std::shared_ptr<Scene0> gameScene = std::make_shared<Scene0>();
	//Use tempScene when testing out engine features.
	std::shared_ptr<Scene1> tempScene = std::make_shared<Scene1>();

	unsigned int gameSceneID = sceneManager->Add(tempScene);

	timer->Start();
	timer->SetLogicLoopSpeed(60);
	sceneManager->SwitchTo(gameSceneID);
	GameLoop();


}
void DogEngine::OnDestroy()
{
}
void DogEngine::GameLoop()
{
	int currentRenderFlag = NULL;
	int passRenderFlag = NULL;

	currentRenderFlag = rendererManager->getRenderValue();


	while (isRunning == true)
	{
		if (currentRenderFlag != rendererManager->getRenderValue())
		{
			currentRenderFlag = passRenderFlag;


			rendererManager->setRenderer(currentRenderFlag);
		}
		timer->UpdateSteadyClock();
		timer->UpdatePerformanceClock();

		handleCollisions();
		HandleEvents(); // I handle my input here 

		timer->IncrementUpdateLag(timer->GetDelta());


		while (timer->GetUpdateLag()>=timer->getMS_Machine_UpdateFPS())
		{

			double positiveTimeValue = timer->getMS_Machine_UpdateFPS();

			FixedUpdate(positiveTimeValue);// Physics Update happen through here anddd animations too. 

			Update(positiveTimeValue); // GameLogic happens all through this update.


			double negativeTimeValue = timer->getMS_Machine_UpdateFPS() * -1.0;

			timer->IncrementUpdateLag(negativeTimeValue); //reason I have to create a temp negative variable is because my setUpdateLag function has += operator when setting values, so I have to add a negative nun
		}	
		
		Render(); // when everything has been finished render that is one call draw



		passRenderFlag = rendererManager->getRenderValue();
	}

	clean();

}

void DogEngine::HandleEvents()
{
	engineGUI->HandleEvents(event_);
	sceneManager->HandleEvents();
	window->HandleEvents();
	if (window->getIsClose())
	{
		clean();
	}
}

void DogEngine::Update(float deltaTime_)
{
	sceneManager->Update(deltaTime_);
	window->Update(deltaTime_);
}

void DogEngine::FixedUpdate(float deltaTime_)
{
	sceneManager->FixedUpdate(deltaTime_);
}

void DogEngine::handleCollisions()
{
	sceneManager->handleCollison();
}

void DogEngine::Render()
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

void DogEngine::clean()
{
	SDL_DestroyWindow(window->getWindowContext());
	SDL_DestroyRenderer(rendererManager->GetRenderAPI<SDLRenderer*>()->GetRenderer());
	threadManager->StopThread(static_cast<ThreadAble*>(sceneManager));
	delete this;
	SDL_Quit();
	std::cout << "Engine Cleaned" << std::endl;
}
