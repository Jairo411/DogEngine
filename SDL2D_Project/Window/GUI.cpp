#include "GUI.h"
#include "Window.h"
#include "../Game/Game.h"
GUI::GUI()
{

}

GUI::~GUI()
{

}

void GUI::OnCreate()
{
	ImGui::CreateContext();
	ImGuiSDL::Initialize(Game::rendererManager->GetInstance()->GetRenderAPI<SDLRenderer*>()->GetRenderer(), 800, 600);
	io = ImGui::GetIO();
	io.DisplaySize.x = 100;
	io.DisplaySize.y = 100;
}

void GUI::OnDestroy()
{
}

void GUI::HandleEvents(SDL_Event* e_)
{
	if (e_ != NULL)
	{
		switch (e_->type)
		{
			/*	case SDL_WINDOWEVENT:
					if (e_->window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
					{
						io.DisplaySize.x = static_cast<float>(e_->window.data1);
						io.DisplaySize.x = static_cast<float>(e_->window.data2);
					}
					break;*/
		case SDL_MOUSEBUTTONDOWN:
		{
			io.MousePos = ImVec2(static_cast<float>(mouseX), static_cast<float>(mouseY));
			const int buttons = SDL_GetMouseState(&mouseX, &mouseY);
			io.MouseDown[0] = buttons & SDL_BUTTON(SDL_BUTTON_LEFT);
			io.MouseDown[1] = buttons & SDL_BUTTON(SDL_BUTTON_RIGHT);
			break;
		}
		default:
			break;
		}
	}
}

void GUI::Update()
{
	io.DeltaTime = Game::timer->GetDeltaTime();
	//io.MousePos = getMousePositionx and getMousePositiony probably use a static thingy over here
	
}

void GUI::Render()
{
	ImGui::NewFrame();
	ImGui::ShowDemoWindow();
	ImGui::Render();
	ImGuiSDL::Render(ImGui::GetDrawData());

}
