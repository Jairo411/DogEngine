#ifndef Game_H
#define Game_H

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include "../GameObjects/Enemy.h"
#include "../GameObjects/Player.h"
#include "../GameObjects/Map/Map.h"
#include "../Input/Input.h"
#include "../Window/Window.h"
#include "../Game/Scenes/Scene.h"
#include "Scenes/SceneManager.h"
#include "Scenes/GameScenes/Scene0.h"

class Game{
public:
	Game();
	void init(const char* title, int posx, int posy, int widith, int height,bool fullscreen);
<<<<<<< HEAD
	void HandleEvents();
	void OnUpdate();
	void handleCollisions();
	void OnRender(); 
=======
	void handleEvents();
	void update();
	void render(); 
>>>>>>> parent of 50f9777... 2020-09-01 1:52
	void clean();
	bool running() { return isRunning; }
	static SDL_Renderer *renderer;
	static Window* actualWindow;
	~Game(); 
private:	
	int cnt=0;
	bool isRunning;
	SDL_Window *window; 
<<<<<<< HEAD
	SceneManager sceneManager;
=======
	Window *actualWindow;

	
>>>>>>> parent of 50f9777... 2020-09-01 1:52
	//Window window;
	

};

#endif // !Game_H