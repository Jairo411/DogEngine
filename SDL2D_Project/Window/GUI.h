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
class GUI
{
public:
	GUI();
	~GUI();
	void OnCreate();
	void OnDestroy();
	void HandleEvents(SDL_Event* e_);
	void Update(float deltaTime_);
	void Render();
private:
	bool DisplayWindowMenuBar();
	ImGuiIO* io;
	int mouseX, mouseY;
	int wheel;
	int buttons;
};

#endif // ! GUI_H