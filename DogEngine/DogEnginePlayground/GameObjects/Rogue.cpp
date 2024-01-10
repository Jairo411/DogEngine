#include "Rogue.h"
#include "../../DogEngine/DogEngine.h"
Rogue::Rogue() 
{

	//new code 
	transform = C_Transform2D();
	collider = C_RectangleCollider();
	sprite = C_Sprite();

	sprite.OnCreate(this);
	sprite.SetTexture("./Assets/Character/Sprites/adventurer-attack1-00.png");

	collider.SetSize(50, 80);
	
	this->AddComponent<C_Transform2D>(transform);
	this->AddComponent<C_RectangleCollider>(collider);
	this->AddComponent<C_Sprite>(sprite);
	
}

Rogue::Rogue(const char* textureSheet, int x, int y)
{
	/* Basic intializations of a member variables */
	//Seralization is a seperate process and needs to be decouple from this logic. 
	className = typeid(*this).name(); // you should put this code inside your seralizer
	className.erase(0,6); // you should put this code inside your seralizer
	

	UpdatePostion();


	this->AddComponent<C_Sprite>();
	this->GetComponent<C_Sprite>()->SetTexture("./Assets/Character/Sprites/adventurer-attack1-00.png");


	this->AddComponent<C_RectangleCollider>();
	this->GetComponent<C_RectangleCollider>()->SetSize(50, 80);


}

void Rogue::OnCreate()
{
}

void Rogue::OnDestroy()
{
}

Rogue::~Rogue()
{

}

void Rogue::Update(float dt_)
{
	position.x += 66; 
	this->GetComponent<C_Sprite>()->Update(dt_);
	this->GetComponent<C_RectangleCollider>()->Update(dt_);
	UpdatePostion();
	
}


void Rogue::Render()
{
	/*This is in the loop*/
	switch (DogEngine::rendererManager->GetInstance()->getRenderValue())
	{
	default:
		break;

	case 0: //SDL
			this->GetComponent<C_Sprite>()->Render();
			this->GetComponent<C_RectangleCollider>()->Render();
		break;
	case 1: //OPENGL

		break;
	case 2: // VULKAN

		break;
	}
}
