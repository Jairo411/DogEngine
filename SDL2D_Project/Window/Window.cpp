#include "Window.h"
#include "../Game/Game.h"
#include <SDL_syswm.h>


/*
Current task 
- Add proper functionally when you click a square you add a tile 
- Add proper Window modes functionailty 
- Needs to be interconnected with MapTiles class 
*/


Window::Window()
{

}
/*The Window gets build First naturally so you might want to switch tileSizes for height and width 
  to be connected to window instead of vice versa. Also you need to connect the row/column length*/

/* Already know how this is going to function, this will only display and change its slicing depending on the map texture length 
 You only really need this window to build properly sectioned maps made of 2D objects */

/*And the Squares will only show up around the mouse instead of covering the whole screen so you'll be able to see the rest of the screen and not be blinded by white shit all over*/

Window::Window(SDL_Window *tempWindow)
{
	SCREENHEIGHT = 0;
	SCREENWIDTH = 0;
	totalAmountOfSquares = 0;
	SDL_GetWindowSize(tempWindow, &SCREENWIDTH, &SCREENHEIGHT);
	SCREENWIDTH = SCREENWIDTH / 20;
	SCREENHEIGHT = SCREENHEIGHT / 20;
	int keyValue=0;
	for (int r = 0; r < SCREENWIDTH;r++)
	{
		for (int  c = 0; c <  SCREENHEIGHT;  c++)
		{
			SDL_Rect* tempSquare = new SDL_Rect();
			tempSquare->x = r * 20;		// it's clear what you need to do use this values <----
			tempSquare->y = c * 20;		//	over there attach them to the rect sizes of of the Map tile sizes 
			tempSquare->w = 20;			//  to make them the same size and interlocking. you also probably want to connect some functionality to the map/tiles update  
			tempSquare->h = 20;			//  with the windows update. 
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

bool Window::mouseInput(int key_)
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

bool Window::controllerInput(int key)
{
	return false;
}

bool Window::keyBoardInput(int key)
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
		std::map<SDL_Rect*, int>::iterator it = GraphicSquareHolder.begin();
		int cycleValue = 0;
		for (it = GraphicSquareHolder.begin(); it != GraphicSquareHolder.end(); it++)
		{
			SDL_Rect* thisKey = it->first;
			it->second = cycleValue;
			SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
			SDL_RenderDrawRect(Game::renderer, it->first);
			//SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 255);
			cycleValue += 1;
		}
	}
		break;
	case Window::STANDARD:
	{

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

}

map<SDL_Rect*, int> Window::getSquareHolder()
{
	return GraphicSquareHolder;
}


