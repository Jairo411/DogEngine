#ifndef Game_H
#define Game_H

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
<<<<<<< HEAD
#include "../GameObjects/Enemy.h"
#include "../GameObjects/Player.h"
#include "../GameObjects/Map/Map.h"
#include "../Input/Input.h"
#include "../Window/Window.h"
#include "../Game/Scenes/Scene.h"
#include "Scenes/SceneManager.h"
#include "Scenes/GameScenes/Scene0.h"
=======
#include "../GameObjects/Map/Map.h"
#include "../GameObjects/Map/TileSet/Tiles.h"
#include "../TextureManager/TextureManager.h"
#include "../GameObjects/GameObject.h"
#include "../GameObjects/Player.h"
#include "../GameObjects/Enemy.h"
#include "../Window/Window.h"
>>>>>>> parent of ff90b31... 2020-09-11

//#include "../Saver.h"



class Game{
public:
	Game();
	~Game();
	
	void init(const char* title, int posx, int posy, int widith, int height,bool fullscreen);
	void handleEvents();
	void update();
	void handleCollisions();
<<<<<<< HEAD
	void OnRender(); 

=======
	void render(); 
>>>>>>> parent of ff90b31... 2020-09-11
	void clean();
	bool running() { return isRunning; }
	static SDL_Renderer *renderer;

private:	
	int cnt=0;
	bool isRunning;
	SDL_Window *window; 
<<<<<<< HEAD
	//SceneManager sceneManager;
	Window *actualWindow;
=======
	Window *actualWindow;
	
>>>>>>> parent of ff90b31... 2020-09-11
	//Window window;
	

};

#endif // !Game_H