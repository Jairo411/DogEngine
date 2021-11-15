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

bool PlayerController::OnDestroy()
{
    return false;
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
