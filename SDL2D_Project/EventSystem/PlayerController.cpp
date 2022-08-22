#include "PlayerController.h"

PlayerController::PlayerController()
{
    mouseInput = MouseInput();
    keyBoardInput = KeyBoardInput();
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
