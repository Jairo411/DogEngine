#include "GUI.h"
#include "Window.h"
#include "../DogEngine.h"
GUI::GUI()
{
	mouseX = 0;
	mouseY = 0;
	wheel = 0;
	buttons = 0;
	io = nullptr;
	consoleapp = ConsoleApp();
}

GUI::~GUI()
{

}

void GUI::OnCreate()
{
	ImGui::CreateContext();
	switch (DogEngine::rendererManager->GetInstance()->getRenderValue())
	{
	default:
		break;

	case 0: //SDL
		ImGuiSDL::Initialize(DogEngine::rendererManager->GetInstance()->GetRenderAPI<SDLRenderer*>()->GetRenderer(), 800, 600);
		break;
	case 1://OPENGL
		break;
	case 2://VULKAN
		break;
	}
}

void GUI::OnDestroy()
{
}


void GUI::HandleEvents(SDL_Event* e_)
{
	SDL_PollEvent(e_);
	switch (e_->type)
	{
	default:
		break;
	}
}

void GUI::Update(float deltaTime_)
{
	io = &ImGui::GetIO();

	SDL_Event e;
	SDL_PollEvent(&e);
	if (e.type == SDL_WINDOWEVENT)
	{
		if (e.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
		{
			io->DisplaySize.x = static_cast<float>(e.window.data1);
			io->DisplaySize.y = static_cast<float>(e.window.data2);
		}
	}
	else if (e.type == SDL_MOUSEWHEEL)
	{
		wheel = e.wheel.y;
	}

	buttons = SDL_GetMouseState(&mouseX, &mouseY);


	io->DeltaTime = deltaTime_;
	io->MousePos = ImVec2(static_cast<float>(mouseX), static_cast<float>(mouseY));
	io->MouseDown[0] = buttons & SDL_BUTTON(SDL_BUTTON_LEFT);
	io->MouseDown[1] = buttons & SDL_BUTTON(SDL_BUTTON_RIGHT);
	io->MouseWheel = static_cast<float>(wheel);


	//io.MousePos = getMousePositionx and getMousePositiony probably use a static thingy over here
	
}

void GUI::Render()
{
	ImGui::NewFrame();

	if (DisplayWindowMenuBar())
		DisplayConsole();

	ImGui::ShowDemoWindow();
	ImGui::Render();
	ImGuiSDL::Render(ImGui::GetDrawData());
	SDL_RenderPresent(DogEngine::rendererManager->GetInstance()->GetRenderAPI<SDLRenderer*>()->GetRenderer());

}

bool GUI::DisplayWindowMenuBar()
{
	ImGui::BeginMainMenuBar();
	if (ImGui::BeginMenu("File"))
	{
		if (ImGui::MenuItem("New")) {}
		if (ImGui::MenuItem("Open", "ctrl+o")) {}
		if (ImGui::MenuItem("Open recent"))
		{

		}
		if (ImGui::MenuItem("Save", "ctrl+s")) {}
		if (ImGui::MenuItem("Quit")) {}
		ImGui::EndMenu();
	}

	ImGui::MenuItem("View");
	ImGui::MenuItem("Project");
	ImGui::MenuItem("Info");

	ImGui::EndMainMenuBar();
	return true;
}

void GUI::DisplayConsole()
{
	bool* pO;
	pO = nullptr;
	consoleapp.Draw("Example: console", pO);
}
