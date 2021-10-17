#ifndef  GUI_H
#define  GUI_H
#include "DearGUI/imgui.h"
#include "DearGUI/imgui_sdl.h"
#include <SDL_events.h>

/// <summary>
/// Very important note here since your are abstracting your renderers between three systems 
/// make sure that properly handle the render function call process to handle their apporiate library class 
/// here for example, you need to create a seperate OpenGL Render process because how you intialize ImGui is different with OpenGL
/// 2021-10-17
/// </summary>
class Game;
class renderer;
class GUI
{
public:
	GUI();
	~GUI();
	void Inti(renderer* renderer);
	void HandleEvents(SDL_Event* e_);
	void Update();
	void Render();
private:
	renderer* renderContext;
	ImGuiIO io;
	int mouseX, mouseY;
};

#endif // ! GUI_H