#include "PlayerController.h"
#include "../../Input/ComputerInput.h"

PlayerController::PlayerController()
{
    mouseInput = new MouseInput();
    keyBoardInput = new KeyBoardInput();
}

PlayerController::~PlayerController()
{
    Parent = nullptr;
    delete Parent;
}

void PlayerController::OnCreate(BaseObj* parent_)
{
    Parent = parent_;
}

void PlayerController::OnDestroy()
{
    
}

void PlayerController::Update()
{
}

void PlayerController::FixedUpdate()
{
}

void PlayerController::Render()
{
}
