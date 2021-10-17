#include "Window.h"
#include "../Game/Game.h"
#include <SDL_syswm.h>

int Window::ScreenHeight = 0; 
int Window::ScreenWidth = 0;
SDL_Point Window::middleOfScreen = SDL_Point();
Window* Window::instance = nullptr;

Window::Window()
{
	ScreenHeight = 0;
	ScreenWidth = 0;
	totalAmountOfSquares = 0;
	SquareSize = 0;
	middleOfScreen.x = 0;
	middleOfScreen.y = 0;
	window = nullptr;

}


void Window::SetGUIEvent(SDL_Event* GUIEvent_)
{

}

Window::Window(SDL_Window *window_)
{
	ScreenHeight = 0; //
	ScreenWidth = 0;
	SquareSize = 40;
	totalAmountOfSquares = 0;
	window= window_;
	

	SDL_GetWindowSize(window, &ScreenWidth, &ScreenHeight);
	middleOfScreen.x = ScreenWidth/2;
	middleOfScreen.y = ScreenHeight/2;
	
	CreateMiddleRect();

	int keyValue=0;
	for (int r = 0; r < 20;r++)
	{
		for (int  c = 0; c <  16;  c++)
		{
			SDL_Rect* tempSquare = new SDL_Rect();
		
			tempSquare->x = r * SquareSize;
			tempSquare->y = c * SquareSize;
			tempSquare->w = SquareSize;
			tempSquare->h = SquareSize;
			GraphicSquareHolder.insert(std::pair<SDL_Rect*,int>(tempSquare,keyValue));	
			keyValue++;
		}	
	}
	
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

bool Window::MouseInput(int key_)
{
	/*
	you probably want to redesign this
	make it so that the mouse doesn't turn it on and off.
	*/
	if (key_!=NULL)
	{
		if (SDL_BUTTON_RIGHT&&windowStatus!=STANDARD)
		{
			windowStatus = STANDARD;
		}
		else if (SDL_BUTTON_RIGHT&& windowStatus!=DEBUG)
		{
			windowStatus = DEBUG;
		}
		return true;
	}
	return false;
}

bool Window::ControllerInput(int key)
{
	return false;
}

void Window::CreateMiddleRect()
{
	middleRect.x = middleOfScreen.x - 15;
	middleRect.y = middleOfScreen.y - 15;

	middleRect.w = 30;
	middleRect.h = 30;

}

bool Window::KeyBoardInput(int key)
{
	return false;
}

Window::~Window()
{

}


void Window::OnRender()
{
	switch (Game::rendererManager->GetInstance()->getRenderValue())
	{
	default:
		break;
	case 0:
		/// <summary>
	/// SDL Render Process
	/// </summary>
		switch (windowStatus)
		{
		case Window::DEBUG:
		{
			SDL_SetRenderDrawColor(Game::rendererManager->GetInstance()->GetRenderer<SDL_Renderer*>(), 100, 0, 15, 100);
			SDL_RenderDrawRect(Game::rendererManager->GetInstance()->GetRenderer<SDL_Renderer*>(), &middleRect);
			SDL_SetRenderDrawColor(Game::rendererManager->GetInstance()->GetRenderer<SDL_Renderer*>(), 0, 0, 0, 255);
			//		GUIContext.Render();
		}
		break;
		case Window::STANDARD:
		{
			std::map<SDL_Rect*, int>::iterator it = GraphicSquareHolder.begin();
			int cycleValue = 0;
			for (it = GraphicSquareHolder.begin(); it != GraphicSquareHolder.end(); it++)
			{
				SDL_Rect* thisKey = it->first;
				it->second = cycleValue;
				SDL_SetRenderDrawColor(Game::rendererManager->GetInstance()->GetRenderer<SDL_Renderer*>(), 255, 255, 255, 255);
				SDL_RenderDrawRect(Game::rendererManager->GetInstance()->GetRenderer<SDL_Renderer*>(), it->first);
				SDL_SetRenderDrawColor(Game::rendererManager->GetInstance()->GetRenderer<SDL_Renderer*>(), 0, 0, 0, 255);
				cycleValue += 1;
			}
		}
		break;
		case Window::RELEASE:
		{

		}
		break;
		default:
			break;
		};
		break;
	/// <summary>
	/// OpenGL Render Process
	/// </summary>
	case 1: 
		switch (windowStatus)
		{
		default:
			break;
		}
		break;
		/// <summary>
	/// Vulkan Render Process
	/// </summary>
	case 2:
		switch (windowStatus)
		{
		default:
			break;
		}
	}
}

void Window::OnUpdate()
{
	GUIContext.HandleEvents(GUIEvent);
	GUIContext.Update();
}

Vec2 Window::ConvertScreenCoords(int x_, int y_)
{
	Vec2 covertedScreenCoords;
	covertedScreenCoords = Vec2(ScreenWidth/2+(-x_), ScreenHeight/2-(y_));
	return covertedScreenCoords;
}





