#include "Window.h"
#include <SDL_syswm.h>

int Window::SCREENHEIGHT = 0;
int Window::SCREENWIDTH = 0;
SDL_Point Window::middleOfScreen = SDL_Point();
SDL_Renderer* Window::renderer = nullptr;

Window::Window()
{

}

Window::Window(const char* title, int posx, int posy, int width, int height, bool fullscreen)
{
	/*Intial defaulting*/
	SCREENHEIGHT = 0;
	SCREENWIDTH = 0;
	totalAmountOfSquares = 0;
	SquareSize = 0;
	middleOfScreen.x = 0;
	middleOfScreen.y = 0;
	window = nullptr;
	windowStatus = 0;
	middleRect = SDL_Rect();
	graphicLayer = SDL_Surface();
	/*Intial defaulting*/

	int flag = 0;
	if (fullscreen)
	{
		flag = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystem Initialised!..." << std::endl;
		window = SDL_CreateWindow(title, posx, posy, width, height, flag);

		if (window)
		{
			std::cout << "Window created!" << std::endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 225, 225, 225, 225);
			std::cout << "Renderer Created!" << std::endl;
		}
		std::cout << "Width: " << width << " Height: " << height << std::endl;
	}
	else {
		std::cout << "SDL_Init failed" << std::endl;
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
	if (key_ != NULL)
	{
	
		return true;
	}
	return false;
}

bool Window::controllerInput(int key)
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

SDL_Window* Window::getWindow()
{
	return window;
}


void Window::OnRender()
{
	
}

void Window::OnUpdate()
{
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 233, 128, 128,1);
	SDL_SetRenderDrawColor(renderer, 222, 180, 180, 1);
	SDL_RenderPresent(renderer);
}


