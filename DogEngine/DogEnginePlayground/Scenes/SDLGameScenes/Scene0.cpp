#include "Scene0.h"



Scene0::Scene0()
{

	/*Rogue* player = nullptr;
	Skeleton* enemy = nullptr;
	Skeleton* enemy0 = nullptr;
	Skeleton* enemy1 = nullptr;
	MapLayer* mapA = nullptr;
	OpenGLTestGameObj* obj = nullptr;
	OpenGLTestGameObj1* obj1 = nullptr;*/


	/* 11-07-2023
	* I am currently using a switch case to switch between "scenes" inside a scene.... 
	* This design is also in the render function, just remove this functionality and refactor it properly to your engine. 
	* NOTES:
	* - You have to initalize all gameobjects then add them to the Gameobject manager, then add them to the scene, i'm pretty sure you can use RAII here. 
	* - Everything in the scenes should purely handle surface level game logic, no engine logic.
	* 
	* - Put a summarize comment on both update and render, to describe how they are suppose to be used. Scene shouldn't have alot of code in the render function. 
	* Everything in the render function is a bit redundant and explicit. Majority of rendering should techically already be decided once the game objects have be 
	* intialized. 
	*/

	

}

Scene0::~Scene0()
{
}

void Scene0::OnCreate()
{


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
	
	
}



void Scene0::Render()
{
	/*DogEngine::rendererManager->GetInstance()->GetRenderAPI<SDLRenderer*>()->RenderPresent();
	DogEngine::rendererManager->GetInstance()->GetRenderAPI<SDLRenderer*>()->SetRenderDrawColour(30, 10, 70, 100);
	DogEngine::rendererManager->GetInstance()->GetRenderAPI<SDLRenderer*>()->RenderClear();*/
}
