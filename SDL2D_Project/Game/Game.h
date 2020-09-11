#ifndef Game_H
#define Game_H
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

#include "../Game/Scenes/Scene.h"
#include "Scenes/SceneManager.h"
#include "Scenes/GameScenes/Scene0.h"
#include "../Window/Window.h"

class Game{
public:
	Game();
	void init(const char* title, int posx, int posy, int widith, int height,bool fullscreen);
	void HandleEvents();
	void OnUpdate();
	void handleCollisions();
	void OnRender(); 
	void clean();
	bool running() { return isRunning; }
	static SDL_Renderer *renderer;
	static Window* actualWindow;
	~Game(); 
private:	
	int cnt=0;
	bool isRunning;
	SDL_Window *window; 
	SceneManager sceneManager;
	//Window window;
	

};

#endif // !Game_H