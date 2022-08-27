#ifndef WINDOW_H
#define WINDOW_H
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
enum class WINDOWFLAGS
{
	NONE_=0,
};
enum class WINDOWSTATUS
{
	NONE_=0,
};
class DogEngine;
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
	void setWindowProperties(int xPosition_, int yPosition, int width, int height, WINDOWFLAGS flag_);
	///Set the Title of the window.
	void SetWindowTitle(const char* title_);
	///Set a Window flag.
	void SetFlag(WINDOWFLAGS flag_);
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
	template <typename enumType>
	constexpr typename std::underlying_type<enumType>::type to_underlying(enumType e) noexcept
	{
		return static_cast<typename std::underlying_type<enumType>::type>(e);
	};
	static int ScreenWidth, ScreenHeight;	
	int posX, posY; 
	bool isClose;
	WINDOWFLAGS windowFlag; 
	WINDOWSTATUS windowStatus;
	GUI* GUIContext;
	SDL_Surface* graphicLayer;
	SDL_Window* window;
	SDL_Event* GUIEvent;
	std::string WindowTitle;
	static Window* instance;
};

#endif // !WINDOW_H