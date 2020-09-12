#ifndef WINDOW_H
#define WINDOW_H
#include <SDL.h>
#include <map>
#include <iterator>
#include "../Input/Input.h"

class Game;
/* Honestly don't know the purpose of this class
	It's suppose to hold UI Elements I guess. It could hold a health bar maybe a stamaina bar*/
class Window: public Input
{	
private:
	int SCREENWIDTH;
	int SCREENHEIGHT;
	int SquareSize;
	int totalAmountOfSquares;
	int windowStatus;
	Uint32 rmask, gmask, bmask, amask;
	std::map<SDL_Rect*, int> GraphicSquareHolder;
	SDL_Surface *graphicLayer;
	SDL_Window *window;
public:
	Window();
	Window(SDL_Window* tempWindow_);
	//I made this constructor for future scablilty 
	//forgot what is was for :) 
	Window(SDL_Window* tempWindow_,int xSquare,int ySquare);
	int getScreenHeight();
	int getScreenWidth();
	bool mouseInput(int case_);
	bool  keyBoardInput(int key);
	bool  controllerInput(int key);
	void OnRender();
	void OnUpdate();
<<<<<<< HEAD
	map<SDL_Rect*, int>getSquareHolder();
	~Window();
	enum WindowStatus : unsigned int
	{
		DEBUG = 0 ,
		STANDARD,
		RELEASE
	};
};

#endif // !WINDOW_H