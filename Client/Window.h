#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H
#include <SDL.h>
#include <SDL_image.h>
#include <map>
#include <iterator>
#include <iostream>
/* Honestly don't know the purpose of this class
	It's suppose to hold UI Elements I guess. It could hold a health bar maybe a stamina bar*/
	/* I should make this static Reasoning:
	 -I can access very basic window stuff which should be important because this carries the SDL_Context
	 -I will be able to do easy Vector math with my screenCoords covered methods
	 -Everything is technically  in this Window Screen.*/
class Window 
{
private:
	static int SCREENWIDTH; //Actually since you have functions for this 
	static int SCREENHEIGHT; // move over the covertedScreenCoords 
	int SquareSize;
	int totalAmountOfSquares;
	int windowStatus;
	static SDL_Point middleOfScreen;
	std::map<SDL_Rect*, int> GraphicSquareHolder;
	static SDL_Renderer *renderer;
	SDL_Rect middleRect;
	SDL_Surface graphicLayer;
	SDL_Window* window;
public:
	Window();
	Window(const char* title, int posx, int posy, int width, int height, bool fullscreen);
	~Window();
	SDL_Window* getWindow();
	static int getScreenHeight();
	static int getScreenWidth();
	bool MouseInput(int case_);
	bool KeyBoardInput(int key);
	bool controllerInput(int key);
	void CreateMiddleRect();
	void OnRender();
	void OnUpdate();
};

#endif // !CLIENTWINDOW_H