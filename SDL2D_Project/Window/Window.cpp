#include "Window.h"
#include "../DogEngine/DogEngine.h"
#include <SDL_syswm.h>

int Window::ScreenHeight = 0; 
int Window::ScreenWidth = 0;
SDL_Point Window::middleOfScreen = SDL_Point();
Window* Window::instance = nullptr;

Window::Window()
{
	ScreenHeight = 0;
	ScreenWidth = 0;
	SquareSize = 0;
	middleOfScreen.x = 0;
	middleOfScreen.y = 0;
	window = nullptr;
	keyBoardInput = KeyBoardInput();
	mouseInput = MouseInput();
	
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
	SquareSize = 40;
	window= window_;
	

	SDL_GetWindowSize(window, &ScreenWidth, &ScreenHeight);
	middleOfScreen.x = ScreenWidth/2;
	middleOfScreen.y = ScreenHeight/2;
	
	CreateMiddleRect();

	
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
		window = SDL_CreateWindow(WindowTitle.c_str(),CurrentWindow_XPOS,CurrentWindow_YPOS,ScreenWidth,ScreenHeight,windowFlag);
		PrintWindowProperities();
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
	CurrentWindow_XPOS = xPosition_;
	CurrentWindow_YPOS = yPosition_;
	ScreenWidth = width_;
	ScreenHeight = height_;
	windowFlag = flag_;
}

void Window::setWindowTitle(const char* title_)
{
	WindowTitle = title_;
}

void Window::setFlag(int flag_)
{
	windowFlag = flag_;
}

void Window::PrintWindowProperities()
{
	std::cout << "Window Width: " << ScreenWidth << " " << "Window Height: " << ScreenHeight << std::endl;
	if (CurrentWindow_XPOS == SDL_WINDOWPOS_CENTERED)
	{
		std::cout << "Current Window X Position: " << "CENTERED" << " " << "Current Window Y Position " << "CENTERED" << std::endl;
	}
	else
	{
		std::cout << "Current Window X Position: " << CurrentWindow_XPOS << " " << "Current Window Y Position " << CurrentWindow_YPOS << std::endl;
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

void Window::setWindowContext(SDL_Window* windowContext_)
{
	window = windowContext_;
}


void Window::CreateMiddleRect()
{
	middleRect.x = middleOfScreen.x - 15;
	middleRect.y = middleOfScreen.y - 15;

	middleRect.w = 30;
	middleRect.h = 30;

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
	
				//NEW 
		DogEngine::rendererManager->GetInstance()->GetRenderAPI<SDLRenderer*>()->SetRenderDrawColour(100, 0, 15, 100);
		DogEngine::rendererManager->GetInstance()->GetRenderAPI<SDLRenderer*>()->DrawRect(&middleRect);
		DogEngine::rendererManager->GetInstance()->GetRenderAPI<SDLRenderer*>()->SetRenderDrawColour(0, 0, 0, 225);

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
	SDL_Event sdlEvent;
	SDL_PollEvent(&sdlEvent);
	mouseInput.SetEvent(&sdlEvent);
	keyBoardInput.SetEvent(&sdlEvent);
	switch (sdlEvent.window.event)
	{
	default:
		break;
	
	case SDL_WINDOWEVENT_SIZE_CHANGED:
	{

		break;
	}
	case SDL_WINDOWEVENT_CLOSE:
		{
		isClose = true;
			break;
		}

	}
	mouseInput.HandleEvents();
	keyBoardInput.HandleEvents();
}

bool Window::getIsClose()
{
	return isClose;
}

Vec2 Window::ConvertScreenCoords(int x_, int y_)
{
	Vec2 covertedScreenCoords;
	covertedScreenCoords = Vec2(ScreenWidth/2+(-x_), ScreenHeight/2-(y_));
	return covertedScreenCoords;
}





