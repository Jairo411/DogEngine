#include "DogEngine.h"
#include "AI/AI.h"

DogEngine* DogEngine::instance = nullptr;
RendererManager* DogEngine::rendererManager = nullptr;
InputManager* DogEngine::inputManager = nullptr;
Timer* DogEngine::timer = nullptr;
Window* DogEngine::window = nullptr;
Serializer* DogEngine::engineSerializer = nullptr;
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

	///Singletons instantiation
	timer = Timer::GetInstance();
	sceneManager = SceneManager::GetInstance();
	window = Window::GetInstance();
	rendererManager = RendererManager::GetInstance();
	engineSerializer = Serializer::GetInstance();
	textureManager = TextureManager::GetInstance();
	audioManager = AudioManager::GetInstance();
	threadManager = ThreadManager::GetInstance();
	GameObjectManager = ObjectManager::GetInstance();
	inputManager = InputManager::GetInstance();

	engineGUI = new GUI();
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

DogEngine* DogEngine::GetInstance()
{
	if (instance==nullptr)
	{
		instance = new DogEngine();
	}
	return instance;
}

void DogEngine::OnCreate(const char* title, int posx, int posy, int width, int height, bool fullscreen)
{
	window->setWindowProperties(posx, posy, width, height, fullscreen);
	window->setWindowTitle(title);
	window->setFlag(NULL); //Change this to the enum values you have. 
	window->OnCreate();
	rendererManager->GetInstance()->setWindow(window);
	rendererManager->GetInstance()->SetRenderer(0); //Change this to the enum values you have. 
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
	currentRenderFlag = rendererManager->getRenderValue();
	while (isRunning == true)
	{
	passRenderFlag = rendererManager->getRenderValue();
	CheckRenderer();
		/// <summary>
		/// At the beginning of each loop, DogEngine's timer will update itself.
		/// the 'time' being updated in these two methods are from two seperate clocks, 
		/// both can be considered to be stopwatches, but one is considered to be a more accurate 
		/// in terms of the calulation of time. 
		/// 
		/// - The performance clock will manage all the engine functionality as, it is important for the time to be as accruate as possible.
		/// - The steady clock i.e (not performance clock) will be used to represent time in our game worlds. 
		/// 
		///  Both clocks start at the same time(not true, but you know what I mean.)after the window has been created. 
		/// </summary>
		timer->UpdatePerformanceClock();
		timer->UpdateSteadyClock();
		handleCollisions();
		HandleEvents(); 
		/// <summary>
		/// What is happening here, is the implemetation of a fixed time step, in my game logic. 
		/// we tell the engine to keep track of how much time has passed compared to, what time step we want our game logic to run at. (I hope that isn't confusing.)
		/// 
		/// The while loop here represents a single time step, (I know a while loop, being used like this is hard to see.)
		/// So everything else that happens before and after the while loop, is processed at a WAYYY(can't extaggerate more) faster rate then the gamelogic. 
		/// like..
		/// Rendering.
		/// Collisions. 
		/// Events. 
		/// </summary>
		timer->Increment_Time_Pass_Since_Update(timer->GetDelta());
		while (timer->GetUpdateLag()>=timer->Get_Engine_Logic_Update_Speed())
		{
			double positiveTimeValue = timer->Get_Engine_Logic_Update_Speed();
			double negativeTimeValue = timer->Get_Engine_Logic_Update_Speed() * -1.0;

			Update(positiveTimeValue);
			timer->Increment_Time_Pass_Since_Update(negativeTimeValue); 		
		}	
		Render(); 
		timer->IncrementFrames();
	}
	clean();
}

void DogEngine::HandleEvents()
{
	/// <summary>
	/// Engine Specific events. 
	/// </summary>
	engineGUI->HandleEvents(event_);
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


void DogEngine::handleCollisions()
{
	sceneManager->handleCollison();
}

void DogEngine::CheckRenderer()
{
	if (currentRenderFlag != rendererManager->getRenderValue())
	{
		currentRenderFlag = passRenderFlag;
		rendererManager->SetRenderer(currentRenderFlag);
	}
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

void DogEngine::RunInstructions()
{
	while (getThreadAssignment() == true)
	{
		Render();
	}
}
