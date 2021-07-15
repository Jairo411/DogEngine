#ifndef WINDOW_H
#define WINDOW_H
#include <SDL.h>
#include <SDL_image.h>
#include <map>
#include <iterator>
#include "../Input/Input.h"
#include "GUI.h"
/*2021-07-09
This whole entire class need to be re-implemented and improved appond. */
/*There should always be a main window, and maybe supplementary windows*/
/* So functions will be called throughout the engine using Window::Functionhere() and most of the getInstance 
functionality will be used to set up properties and maybe access none static variables*/
/* Cool notes:
	I am going to create structs to represent the properites of my objects before hand so 
	that I can create my objects and assign there member values according to how I want.
	Like how Graphics APIs set up there logic.*/
class Game;
/*Might put some flags into this*/
struct Renderer
{
 SDL_Renderer* renderer;
};
struct WindowProp
{
	SDL_Window* win;
	int ScreenHeight;
	int ScreenWidth;
	int xPos;
	int yPos;
};
class Window: public Input
{	
public:
	Window(Window& other) = delete;
	void operator=(const Window&) = delete;
	//Takes a WindowProp structure, and intializes Window classe's member variables.
	void setWindowProperties(WindowProp  windowProperties_); 
	static Window* GetInstance(); 
	static int getScreenHeight();
	static int getScreenWidth();
	bool MouseInput(int case_);
	bool KeyBoardInput(int key);
	bool ControllerInput(int key);
	void CreateMiddleRect();
	void SetRenderer(SDL_Renderer* renderer_);
	void SetGUIEvent(SDL_Event* GUIEvent_);
	SDL_Renderer* GetRenderer();
	void OnRender();
	void OnUpdate();
	static Vec2 ConvertScreenCoords(int x, int y);
	Vec2 midVec;
	enum WindowStatus : unsigned int
	{
		DEBUG = 0,
		STANDARD,
		RELEASE
	};
	SDL_Window* GetWindow();
	static Renderer* RenderContext; 
	static WindowProp* properities;
private:
	//Basic Window Member Variables
	int CurrentWindow_XPOS, CurrentWindow_YPOS;
	int width,height;
	Window(); // With the singleton I will only have default constructors, then change them later with the WindowProp Struct
	Window(SDL_Window* window_);
	~Window();
	int mouseX, mouseY; //Mouse positions
	static int SCREENWIDTH; //Actually since you have functions for this 
	static int SCREENHEIGHT; // move over the covertedScreenCoords 
	int SquareSize;
	int totalAmountOfSquares;
	int windowStatus;
	static Window* instance;
	std::map<SDL_Rect*, int> GraphicSquareHolder;
	SDL_Rect middleRect;
	static SDL_Point middleOfScreen;
	SDL_Surface* graphicLayer;
	SDL_Window* window;
	SDL_Event* GUIEvent;
	Vec2 covertedScreenCoords;
	GUI GUIContext;
};

#endif // !WINDOW_H