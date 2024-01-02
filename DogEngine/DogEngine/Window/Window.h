#ifndef WINDOW_H
#define WINDOW_H
#define MAXWINDOWFLAGS 21 
#include "../DogEngineDefinitions.h"
#include <SDL.h>
#include <SDL_image.h>
#include <map>
#include <iterator>
#include "../EventSystem/Event.h"
#include "../Renderer/Renderer.h"
#include "GUI.h"
/*
* Window singleton class.
*/
class DogEngine;
enum class WINDOWSTATUS
{
	NONE_=0,
};
	class Window
	{
	public:
		Window(Window& other) = delete;
		Window(const Window&) = delete;
		Window& operator =(Window& other) = delete;
		Window& operator=(const Window&) = delete;
		void OnCreate();
		void OnDestroy();
		///Prints window's current properities.
		void PrintWindowProperties();
		static Window* GetInstance();
		SDL_Window* getWindowContext();
		static int getScreenHeight();
		static int getScreenWidth();
		///Set properties.
		void setWindowProperties(int xPosition_, int yPosition, int width, int height, int flag_);
		///Set the Title of the window.
		void SetWindowTitle(const char* title_);
		///Set a Window flag.
		void SetFlag(int flag_);
		///Set a rendering context for graphic APIs like vulkan and opengl.
		void SetWindowContext(SDL_Window* windowContext_);
		void SetGUIEvent(SDL_Event* GUIEvent_); //Remove this. 
		void SetGUI(GUI* GUIContext_); // Remove this. 
		void Render();
		void Update(float deltaTime_);
		void HandleEvents();
		bool getIsClose();
	private:
		Window();
		Window(SDL_Window* window_);
		~Window();
		static int ScreenWidth, ScreenHeight;
		int posX, posY;
		int windowFlag;
		bool isClose;
		WINDOWSTATUS windowStatus;
		GUI* GUIContext;
		SDL_Surface* graphicLayer;
		SDL_Window* window;
		SDL_Event* GUIEvent;
		std::string WindowTitle;
		static Window* instance;
	};

#endif // !WINDOW_H