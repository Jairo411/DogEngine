#include "DogEngine.h"
//#include "AI/AI.h"
#include "../DogEnginePlayground/Scenes/SDLGameScenes/Scene0.h"
#include "../DogEnginePlayground/Scenes/SDLGameScenes/Scene1.h"
#include "../DogEnginePlayground/Scenes/SDLGameScenes/Scene2.h"
#include "../DogEnginePlayground/Scenes/SDLGameScenes/DebugScene.h"




DGEngine::core::DogEngine * DGEngine::core::DogEngine::instance = nullptr;
RendererManager* DGEngine::core::DogEngine::rendererManager = nullptr;
Timer* DGEngine::core::DogEngine::timer = nullptr;
Window* DGEngine::core::DogEngine::window = nullptr;
Serializer* DGEngine::core::DogEngine::engineSerializer = nullptr;
TextureManager* DGEngine::core::DogEngine::textureManager = nullptr;
SceneManager* DGEngine::core::DogEngine::sceneManager = nullptr;
ThreadManager* DGEngine::core::DogEngine::threadManager = nullptr;
AudioManager* DGEngine::core::DogEngine::audioManager = nullptr;

bool DGEngine::core::DogEngine::initialized = false;
bool DGEngine::core::DogEngine::isRunning = false;


DGEngine::core::DogEngine::DogEngine()
{
	
	IntializeEngineSystems();
	isRunning = true;
	///instantiations
	engineGUI = new GUI();
	event_ = new SDL_Event();


	/*
	*	threadManager->setMaxAmountOfThreads(4);
	* threadManager->AddThreadAble(this);	
	* threadManager->StartThread(static_cast<Game*>(this)); //when using the std renderer you re-add this process
	*/

	/*
	* Setting up engine file directory 
	*Test environment
	* FileDirectoryHandler fileDirectory;
	* std::string filePath;
	* filePath = "./Assets/Character/Sprites";
	* fileDirectory.ChangeDirectory(filePath);
	* fileDirectory.PrintDirectoryContents();
	* fileDirectory.PrintDirectoryPath();
	* system("pause");
	* Test environment
	*/
	


	CurrentSetUp();
	OnCreate("DogEngine 0.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
}

void DGEngine::core::DogEngine::IntializeEngineSystems()
{
	///Singletons instantiations
	timer = Timer::GetInstance();
	sceneManager = SceneManager::GetInstance();
	window = Window::GetInstance();
	rendererManager = RendererManager::GetInstance();
	engineSerializer = Serializer::GetInstance();
	textureManager = TextureManager::GetInstance();
	audioManager = AudioManager::GetInstance();
	threadManager = ThreadManager::GetInstance();
	gameObjectManager = ObjectManager::GetInstance();
	eventManager = EventManager::GetInstance();
	initialized = true;
}

void DGEngine::core::DogEngine::CurrentSetUp()
{
	MouseInput* mouseInput = new MouseInput();
	KeyBoardInput* keyBoardInput = new KeyBoardInput();

	ListenerInfo mouseInfo;
	ListenerInfo keyboardInfo;

	mouseInfo.index = 0;
	mouseInfo.order = 0;
	mouseInfo.listener = (EventListener*)mouseInput;
	

	keyboardInfo.index = 1;
	keyboardInfo.order = 1;
	keyboardInfo.listener = (EventListener*)keyBoardInput;


	eventManager->SetEvent(event_);
	eventManager->AddListener(keyboardInfo);
	eventManager->AddListener(mouseInfo);


	eventManager->OnCreate();

}



//Should see if I really need this function
bool DGEngine::core::DogEngine::setIsRunning(bool tempBool_)
{
	isRunning = tempBool_;
	return isRunning;
}



DGEngine::core::DogEngine::~DogEngine()
{


}

DGEngine::core::DogEngine* DGEngine::core::DogEngine::GetInstance()
{
	if (instance==nullptr)
	{
		instance = new DogEngine();
	}
	return instance;
}

void DGEngine::core::DogEngine::OnCreate(const char* title, int posx, int posy, int width, int height, bool fullscreen)
{
	//Window and render intialization
	window->setWindowProperties(posx, posy, width, height,SDL_WINDOWPOS_CENTERED);
	window->SetWindowTitle(title);
	window->SetFlag(SDL_RENDERER_ACCELERATED); 
	window->OnCreate();
	rendererManager->GetInstance()->setWindow(window);
	rendererManager->GetInstance()->SetRenderer(static_cast<int>(RenderAPI::SDLAPI)); 
	window->SetGUI(engineGUI);


	std::shared_ptr<Scene0> tScene = std::make_shared<Scene0>();
	unsigned int gameSceneID = sceneManager->Add(tScene);


	//Timer intialization 
	timer->Start();
	timer->SetLogicLoopSpeed(60);
	sceneManager->SwitchTo(gameSceneID);

	
	GameLoop();


}
void DGEngine::core::DogEngine::OnDestroy()
{
}
void DGEngine::core::DogEngine::GameLoop()
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

void DGEngine::core::DogEngine::HandleEvents()
{
	eventManager->HandleEvents();
}

void DGEngine::core::DogEngine::Update(float deltaTime_)
{
	sceneManager->Update(deltaTime_);
	window->Update(deltaTime_);
}


void DGEngine::core::DogEngine::handleCollisions()
{
	sceneManager->handleCollison();
}

void DGEngine::core::DogEngine::CheckRenderer()
{
	if (currentRenderFlag != rendererManager->getRenderValue())
	{
		currentRenderFlag = passRenderFlag;
		rendererManager->SetRenderer(currentRenderFlag);
	}
}

void DGEngine::core::DogEngine::Render()
{
	if (rendererManager->GetInstance()->getRenderValue() == static_cast<int>(RenderAPI::SDLAPI))
	{
		//till I figure out why my engine keeps crashing when I do SDL clear calls here, ill leave this empty. 
	}
	else if (rendererManager->GetInstance()->getRenderValue() == static_cast<int>(RenderAPI::OPENGLAPI))
	{
		rendererManager->GetInstance()->GetRenderAPI<OpenGLRenderer*>()->RefreshWindow();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	else if (rendererManager->GetInstance()->getRenderValue() == static_cast<int>(RenderAPI::VULKANAPI))
	{

	}
	sceneManager->Render();
}

void DGEngine::core::DogEngine::clean()
{
	SDL_DestroyWindow(window->getWindowContext());
	SDL_DestroyRenderer(rendererManager->GetRenderAPI<SDLRenderer*>()->GetRenderer());
	delete this;
	SDL_Quit();
	std::cout << "Engine Cleaned" << std::endl;
}

void DGEngine::core::DogEngine::RunInstructions()
{
	while (getThreadAssignment() == true)
	{
		Render();
	}
}
