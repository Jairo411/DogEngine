#ifndef Game_H
#define Game_H

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include "../GameObjects/Map/Map.h"
#include "../GameObjects/Map/TileSet/Tiles.h"
#include "../TextureManager/TextureManager.h"
#include "../GameObjects/GameObject.h"
#include "../GameObjects/Player.h"
#include "../GameObjects/Enemy.h"
#include "../GameObjects/Player.h"
#include "../GameObjects/Map/Map.h"
#include "../Input/Input.h"
#include "../Window/Window.h"

//#include "../Saver.h"



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
	~Game();
private:
	int cnt=0;
	bool isRunning;
	SDL_Window *window;
	Window *actualWindow;
	
	

	//Window window;


};

#endif // !Game_H
