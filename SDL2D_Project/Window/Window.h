#ifndef WINDOW_H
#define WINDOW_H
#include <SDL.h>
#include <SDL_image.h>
#include <map>
#include <iterator>
#include "../Input/Input.h"
#include "../Renderer/Renderer.h"
#include "GUI.h"
/*2021-07-09
This whole entire class need to be re-implemented and improved appond. */
/*There should always be a main window, and maybe supplementary windows*/
/* So functions will be called throughout the engine using Window::Functionhere() and most of the getInstance 
functionality will be used to set up properties and maybe access none static variables*/
/* Cool notes:
	I am going to create structs to represent the properites of my objects before hand so 
	that I can create my objects and assign there member values according to how I want.
	Like how Graphics APIs set up there logic
- THE WINDOW CLASS SHOULD NOT HANDLE INPUT LOGIC 
	
	.*/
class Game;
class Window: public Input
{	
public:
	Window(Window& other) = delete;
	void operator=(const Window&) = delete;
	//Takes a WindowProp structure, and intializes Window classe's member variables.
	void OnCreate();
	void OnDestroy();
	void PrintWindowProperities();
	static Window* GetInstance(); 
	SDL_Window* getWindowContext();
	static int getScreenHeight();
	static int getScreenWidth();
	bool MouseInput(int case_);
	bool KeyBoardInput(int key);
	bool ControllerInput(int key);
	void CreateMiddleRect();
	void setWindowProperties(int xPosition_, int yPosition, int width, int height, int flag);
	void setWindowTitle(const char* title_);
	void setFlag(int flag_);
	void setWindowContext(SDL_Window* windowContext_);
	void SetRenderer(RendererManager* renderer_);
	void SetGUIEvent(SDL_Event* GUIEvent_);
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
private:
	//Basic Window Member Variables
	int CurrentWindow_XPOS, CurrentWindow_YPOS;
	int windowFlag;
	static int ScreenWidth; //Actually since you have functions for this 
	static int ScreenHeight; // move over the covertedScreenCoords 
	std::string WindowTitle;
	Window(); // With the singleton I will only have default constructors, then change them later with the WindowProp Struct
	Window(SDL_Window* window_);
	~Window();
	int mouseX, mouseY; //Mouse positions
	int SquareSize;
	int totalAmountOfSquares;
	int windowStatus;
	static Window* instance;
	std::map<SDL_Rect*, int> GraphicSquareHolder;
	SDL_Rect middleRect;
	static SDL_Point middleOfScreen;
	Vec2 covertedScreenCoords;
	/* Graphics Stuff*/
	GUI GUIContext;
	SDL_Surface* graphicLayer;
	SDL_Window* window;
	SDL_Event* GUIEvent;
	SDL_Renderer* renderContext;
};

#endif // !WINDOW_H