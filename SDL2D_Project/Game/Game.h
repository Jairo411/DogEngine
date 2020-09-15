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
	void handleEvents();
	void update();
<<<<<<< HEAD
	void handleCollisions();

||||||| 50f9777
	void handleCollisions();
=======
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
	Window *actualWindow;
	OBJArray<GameObject*> ObjHolder;
	GameObject* holder;
	GameObject* holder1;
	
>>>>>>> 48d7615b797d99609e19fadd6cf40cd1ccacf523
	//Window window;


};

#endif // !Game_H
