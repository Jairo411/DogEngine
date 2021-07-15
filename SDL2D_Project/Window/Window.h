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
 int width;
 int height;
};
struct WindowProp
{
	SDL_Window* win;
	int ScreenHeight;
	int ScreenWidth;
	int squareSize;
};
class Window: public Input
{	
public:
	Window(Window& other) = delete;
	void operator=(const Window&) = delete;
	void setWindowProperties(WindowProp  windowProperties_); //Sets the properties for the MainWindow singleton class everyother window will be under heiarchy of this main window.
	static Window* GetInstance(); 
	static int getScreenHeight();
	static int getScreenWidth();
	bool MouseInput(int case_);
	bool KeyBoardInput(int key);
	bool ControllerInput(int key);
	void CreateMiddleRect();
	void SetRenderer(SDL_Renderer* renderer_);
	void SetGUIEvent(SDL_Event* GUIEvent_);
	void getRenderContext(); // We are going to reimplement this later, cause Im going to have to fix everything...
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
	static Renderer* RenderContext; // TIm gonna get rid of this
	SDL_Window* GetWindow();
private:
	Window(); // With the singleton I will only have default constructors, then change them later with the WindowProp Struct
	Window(SDL_Window* window_);
	~Window();
	int mouseX, mouseY;
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
	WindowProp properities;
	Vec2 covertedScreenCoords;
	GUI GUIContext;
};

#endif // !WINDOW_H