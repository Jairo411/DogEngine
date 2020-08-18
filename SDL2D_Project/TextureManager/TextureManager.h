#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include "../Game/Game.h"
#include <string>

class TextureManager
{
public:
	TextureManager();
	~TextureManager();
	static SDL_Texture* LoadTexture(const char* filename);
    static SDL_Texture* LoadTexture(SDL_Rect sRect,SDL_Texture* source);
	//static const char* getTexture();
	static void Draw(SDL_Texture* tex,SDL_Rect src, SDL_Rect dest);
};


#endif // !TEXTUREMANAGER_H

