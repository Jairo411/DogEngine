#include "GUI.h"
#include "Window.h"
#include "../Game/Game.h"
GUI::GUI()
{
	renderContext = nullptr;
}

GUI::~GUI()
{

}

void GUI::Inti(renderer* renderer)
{
	renderContext = renderer;
	ImGui::CreateContext();
	ImGuiSDL::Initialize(Game::renderer->getInstance()->getRenderer(), 800, 600);
	io = ImGui::GetIO();
	
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
}

void GUI::Render()
{
	ImGui::NewFrame();
	ImGui::ShowDemoWindow();
	ImGui::Render();
	ImGuiSDL::Render(ImGui::GetDrawData());

}
