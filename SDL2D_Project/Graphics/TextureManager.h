#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include "../Game/Game.h"
#include <string>
#include <vector> 
/*2021-07-09 
	Soild*/
class TextureManager
{
public:
	TextureManager();
	~TextureManager();
	static SDL_Texture* LoadTexture(const char* filename);
    static SDL_Texture* LoadTexture(SDL_Rect sRect,SDL_Texture* source);
	static std::vector<SDL_Texture*> LoadMapSprite(SDL_Texture* tex_,int width_, int height_,int SizeOfCut_,int sourceX_, int sourceY_);
	//static const char* getTexture();
	static void Draw(SDL_Texture* tex,SDL_Rect src, SDL_Rect dest);
};


#endif // !TEXTUREMANAGER_H

