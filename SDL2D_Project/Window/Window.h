#ifndef WINDOW_H
#define WINDOW_H
#include <SDL.h>
#include <SDL_image.h>
#include <map>
#include <iterator>
#include "../Input/Input.h"
#include "GUI.h"
class Game;
struct Renderer
{
 SDL_Renderer* renderer;
 int width;
 int height;
};

class Window: public Input
{	
public:
	Window();
	Window(SDL_Window* tempWindow_);
	~Window();
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
	static Renderer* RenderContext;
	SDL_Window* GetWindow();
private:
	int mouseX, mouseY;
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
	GUI GUIContext;
	SDL_Event* GUIEvent;
};

#endif // !WINDOW_H