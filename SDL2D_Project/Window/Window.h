#ifndef WINDOW_H
#define WINDOW_H
#include <SDL.h>
#include <SDL_image.h>
#include <map>
#include <iterator>
#include "../Input/Input.h"
class Game;
/* Honestly don't know the purpose of this class
	It's suppose to hold UI Elements I guess. It could hold a health bar maybe a stamina bar*/
/* I should make this static Reasoning:
 -I can access very basic window stuff which should be important because this carries the SDL_Context 
 -I will be able to do easy Vector math with my screenCoords covered methods 
 -Everything is technically  in this Window Screen.*/
class Window: public Input
{	
private:
	static int SCREENWIDTH; //Actually since you have functions for this 
	static int SCREENHEIGHT; // move over the covertedScreenCoords 
	int SquareSize;
	int totalAmountOfSquares;
	int windowStatus;
	std::map<SDL_Rect*, int> GraphicSquareHolder;
	SDL_Rect middleRect;
	static SDL_Point middleOfScreen;
	SDL_Surface *graphicLayer;
	SDL_Window *window;
	Vec2 covertedScreenCoords;
public:
	Window();
	Window(SDL_Window* tempWindow_);
	static int getScreenHeight();
	static int getScreenWidth();
	bool MouseInput(int case_);
	bool KeyBoardInput(int key);
	bool controllerInput(int key);
	void CreateMiddleRect();
	//void OnCreateUI(UI tempUI_) adding UI functionality 
	void OnRender();
	void OnUpdate();
	static Vec2 convertScreenCoords(int x, int y);
	~Window();
	Vec2 midVec;
	enum WindowStatus : unsigned int
	{
		DEBUG = 0 ,
		STANDARD,
		RELEASE
	};
};

#endif // !WINDOW_H