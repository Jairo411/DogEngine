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
- THE WINDOW CLASS WILL NOW HANDLE INPUT LOGIC THROUGH COMPOSITIONS OBJECTS.
- THE WINDOW CLASS INPUT LOGIC CAN AND WILL BE HARDCODEDISH.
	.*/
class Game;
class Window
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
	void CreateMiddleRect();
	void setWindowProperties(int xPosition_, int yPosition, int width, int height, int flag);
	void setWindowTitle(const char* title_);
	void setFlag(int flag_);
	void setWindowContext(SDL_Window* windowContext_);
	void SetGUIEvent(SDL_Event* GUIEvent_);
	void SetGUI(GUI* GUIContext_);
	void Render();
	void Update(float deltaTime_);
	void HandleEvents();
	bool getIsClose();
	static Vec2 ConvertScreenCoords(int x, int y);
	Vec2 midVec;
	enum WindowStatus : unsigned int
	{
		DEBUG = 0,
		STANDARD,
		RELEASE
	};
private:
	//Constructors
	Window(); // With the singleton I will only have default constructors, then change them later with the WindowProp Struct
	Window(SDL_Window* window_);
	~Window();
	//INPUT HANDLER
	KeyBoardInput keyBoardInput;
	MouseInput mouseInput;
	//Basic Window Member Variables
	static int ScreenWidth, ScreenHeight; //Window Size
	int CurrentWindow_XPOS, CurrentWindow_YPOS; // Position of the window 
	int* mouseX, *mouseY, *mousePtr; //Position of the mouse Remove this 
	int windowFlag; 
	int SquareSize;
	int windowStatus;
	std::string WindowTitle;
	static Window* instance;
	SDL_Rect middleRect;
	static SDL_Point middleOfScreen;
	Vec2 covertedScreenCoords;
	//FLAGS
	bool isClose;
	/* Graphics Stuff*/
	GUI* GUIContext;
	SDL_Surface* graphicLayer;
	SDL_Window* window;
	SDL_Event* GUIEvent;
};

#endif // !WINDOW_H