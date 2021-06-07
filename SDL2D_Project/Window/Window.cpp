#include "Window.h"
#include "../Game/Game.h"
#include <SDL_syswm.h>

int Window::SCREENHEIGHT = 0; 
int Window::SCREENWIDTH = 0;
SDL_Point Window::middleOfScreen = SDL_Point();
Renderer* Window::RenderContext = nullptr;

Window::Window()
{
	SCREENHEIGHT = 0;
	SCREENWIDTH = 0;
	totalAmountOfSquares = 0;
	SquareSize = 0;
	middleOfScreen.x = 0;
	middleOfScreen.y = 0;
	window = nullptr;

}

void Window::SetRenderer(SDL_Renderer* renderer_)
{
	RenderContext = new Renderer();
	RenderContext->renderer = renderer_;
//	GUIContext = GUI();
//	GUIContext.Inti(RenderContext);
}

void Window::SetGUIEvent(SDL_Event* GUIEvent_)
{

}

SDL_Renderer* Window::GetRenderer()
{
	return RenderContext->renderer;
}

Window::Window(SDL_Window *tempWindow)
{
	SCREENHEIGHT = 0;
	SCREENWIDTH = 0;
	SquareSize = 40;
	totalAmountOfSquares = 0;
	window = tempWindow;
	

	SDL_GetWindowSize(window, &SCREENWIDTH, &SCREENHEIGHT);
	middleOfScreen.x = SCREENWIDTH/2;
	middleOfScreen.y = SCREENHEIGHT/2;
	
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

int Window::getScreenHeight()
{
	return SCREENHEIGHT;
}

int Window::getScreenWidth()
{
	return SCREENWIDTH;
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
	switch (windowStatus)
	{
	case Window::DEBUG:
	{
		SDL_SetRenderDrawColor(RenderContext->renderer, 100, 0, 15, 100);
		SDL_RenderDrawRect(RenderContext->renderer, &middleRect);
		SDL_SetRenderDrawColor(RenderContext->renderer, 0, 0, 0, 255);
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
			SDL_SetRenderDrawColor(Window::RenderContext->renderer, 255, 255, 255, 255);
			SDL_RenderDrawRect(Window::RenderContext->renderer, it->first);
			SDL_SetRenderDrawColor(Window::RenderContext->renderer, 0, 0, 0, 255);
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
	
}

void Window::OnUpdate()
{
	GUIContext.HandleEvents(GUIEvent);
	GUIContext.Update();
}

Vec2 Window::ConvertScreenCoords(int x_, int y_)
{
	Vec2 covertedScreenCoords;
	covertedScreenCoords = Vec2(SCREENWIDTH/2+(-x_), SCREENHEIGHT/2-(y_));
	return covertedScreenCoords;
}

SDL_Window* Window::GetWindow()
{
	return window;
}





