#include "Scene0.h"


Rogue* player = nullptr;
Skeleton* enemy = nullptr;
Skeleton* enemy0 = nullptr;
Skeleton* enemy1 = nullptr;
MapLayer* mapA = nullptr;
OpenGLTestGameObj* obj = nullptr;
OpenGLTestGameObj1* obj1 = nullptr;

Scene0::Scene0()
{

	switch (Game::rendererManager->GetInstance()->getRenderValue())
	{
	default:
		break;

	case 0:

		Game::EngineSerializer->GetInstance()->CreateScene(9, "SCENE9");
		Game::EngineSerializer->GetInstance()->CreateScene(10, "SCENE10");
		Game::EngineSerializer->GetInstance()->CreateScene(11, "SCENE11");

		//SDL
		/* Intial Object Creations*/
		player = new Rogue("./Assets/Character/Sprites/adventurer-attack1-00.png", 0, 60);
		enemy = new Skeleton(180, 100);
		enemy0 = new Skeleton(300, 50);
		enemy1 = new Skeleton(400, 200);


		Game::EngineSerializer->GetInstance()->AddGameObject(player);
		Game::EngineSerializer->GetInstance()->AddGameObject(enemy0);

		/*Observer Pattern Implemented*/
		mapA = new MapLayer(Game::window);

		//Game::EngineSerializer->GetInstance()->AssignID(GameObject::OBJHolder);
		break;

	case 1:
		//OPENGL
	obj = new OpenGLTestGameObj();
		break;
	}
}

Scene0::~Scene0()
{
}

void Scene0::OnCreate()
{

	switch (Game::rendererManager->GetInstance()->getRenderValue())
	{
	default:
		break;
	case 0:
		/*Observer Pattern Implemented*/
	//enemy->Attach(new GameObserver(enemy));
	//enemy0->Attach(new GameObserver(enemy0));
	//enemy1->Attach(new GameObserver(enemy1));

	/* Setting GameObject Functionality*/
		enemy->SetTarget(player);
		enemy0->SetTarget(player);
		Game::AI_Manager->getInstance()->getTotalAgents();
		Game::AI_Manager->getInstance()->setPath(dynamic_cast<AI*>(enemy1), mapA->getTiles(), 200);

		Game::initialized = true;


		break;
	case 1:

		break;
	}

}

void Scene0::OnDestroy()
{

}

void Scene0::OnActivate()
{
}

void Scene0::OnDeactivate()
{
}

void Scene0::HandleEvents()
{
	
}
void Scene0::HandleCollison()
{

}
void Scene0::Update(float deltaTime_)
{
	//Hackish way of me seperating my opengl render process from my sdl one this is not a final design choice 
	switch (Game::rendererManager->getRenderValue())
	{
	default:
		break;

	case 0:
		player->Update(deltaTime_);
		enemy->Update(deltaTime_);
		enemy0->Update(deltaTime_);
		enemy1->Update(deltaTime_);
		mapA->Update(deltaTime_);
		Game::AI_Manager->getInstance()->OnUpdate(deltaTime_);
		break;
	case 1:

		break;
	}
	
}

void Scene0::FixedUpdate(float deltaTime_)
{
}



void Scene0::Render()
{
	//Hackish way of me seperating my opengl render process from my sdl one this is not a final design choice 

	switch (Game::rendererManager->getRenderValue())
	{
	default:
		break;

	case 0:

		Game::rendererManager->GetInstance()->GetRenderAPI<SDLRenderer*>()->SetRenderDrawColour(225, 225, 225, 225);
		Game::rendererManager->GetInstance()->GetRenderAPI<SDLRenderer*>()->RenderClear();
		mapA->Render();
		player->Render();
		enemy->Render();
		enemy0->Render();
		enemy1->Render();
		Game::window->Render();
		Game::rendererManager->GetInstance()->GetRenderAPI<SDLRenderer*>()->RenderPresent();
		break;
	case 1: 
		obj->Render();
		break;
	}
	
	
}
