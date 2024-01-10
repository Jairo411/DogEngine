#include "Window.h"
#include "../DogEngine.h"
#include <SDL_syswm.h>

int Window::ScreenHeight = 0; 
int Window::ScreenWidth = 0;
Window* Window::instance = nullptr;

Window::Window()
{
}


void Window::SetGUIEvent(SDL_Event* GUIEvent_)
{

}

void Window::SetGUI(GUI* GUIContext_)
{
	GUIContext = GUIContext_;
	GUIContext->OnCreate();
}

Window::Window(SDL_Window *window_)
{
	ScreenHeight = 0; 
	ScreenWidth = 0;
	window= window_;
	SDL_GetWindowSize(window, &ScreenWidth, &ScreenHeight);
}


void Window::OnCreate()
{
	if (windowFlag ==SDL_WINDOW_FULLSCREEN)
	{
		std::cout << "FullScreen : ON" << std::endl;
		
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL initialized " << std::endl;
		
		window = SDL_CreateWindow(WindowTitle.c_str(),posX,posY,ScreenWidth,ScreenHeight,windowFlag);
		PrintWindowProperties();
	}
	else
	{
		std::cout << "SDL Couldn't initialize" << std::endl;
	}
}

void Window::OnDestroy()
{
}

void Window::setWindowProperties(int xPosition_, int yPosition_, int width_, int height_, int flag_)
{
	posX = xPosition_;
	posY = yPosition_;
	ScreenWidth = width_;
	ScreenHeight = height_;
	windowFlag = flag_;
}

void Window::SetWindowTitle(const char* title_)
{
	WindowTitle = title_;
}

void Window::SetFlag(int flag_)
{
	windowFlag = flag_;
}

void Window::PrintWindowProperties()
{
	std::cout << "Window Width: " << ScreenWidth << " " << "Window Height: " << ScreenHeight << std::endl;
	if (posX == SDL_WINDOWPOS_CENTERED)
	{
		std::cout << "Current Window X Position: " << "CENTERED" << " " << "Current Window Y Position " << "CENTERED" << std::endl;
	}
	else
	{
		std::cout << "Current Window X Position: " << posX << " " << "Current Window Y Position " << posY << std::endl;
	}
	std::cout << "Current Window Flag: " << windowFlag << std::endl;
}


Window* Window::GetInstance()
{
	if (instance==nullptr)
	{
		instance = new Window();
	}
	return instance;
}

int Window::getScreenHeight()
{
	return ScreenHeight;
}

int Window::getScreenWidth()
{
	return ScreenWidth;
}

SDL_Window* Window::getWindowContext()
{
	return window;
}

void Window::SetWindowContext(SDL_Window* windowContext_)
{
	window = windowContext_;
}


Window::~Window()
{

}


void Window::Render()
{
	switch (DogEngine::rendererManager->GetInstance()->getRenderValue())
	{
		default:
		break;
		/// SDL Render Process
		case 0:
		{
		/*
		DogEngine::rendererManager->GetInstance()->GetRenderAPI<SDLRenderer*>()->SetRenderDrawColour(100, 0, 15, 100);
		DogEngine::rendererManager->GetInstance()->GetRenderAPI<SDLRenderer*>()->DrawRect(&middleRect);
		DogEngine::rendererManager->GetInstance()->GetRenderAPI<SDLRenderer*>()->SetRenderDrawColour(0, 0, 0, 225);*/
		GUIContext->Render();
		break;
		}
	/// OpenGL Render Process
		case 1:
		{
		break;
		}
	/// Vulkan Render Process
		case 2:
		{
		break;
		}
	}
}

void Window::Update(float deltaTime_)
{
	
	GUIContext->Update(deltaTime_);
}

void Window::HandleEvents()
{
	
}

bool Window::getIsClose()
{
	return isClose;
}

