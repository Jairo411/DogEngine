#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include <string>
#include <vector>
#include <variant>
#include <assert.h>
#include "InfoStructs.h"
#include "../DogEngine/DogEngine.h"
#include "../Renderer/Renderer.h"
/*2021-07-09 
	Soild*/
//2021-10-17 not soild enough 


/*TextureManager class has reference of all renderers now. 
 Not all of the same calls will work so I will have to be careful and abstract my TextureManager code a bit more.*/

class TextureManager
{
public:
	TextureManager(const TextureManager&) = delete;
	TextureManager(TextureManager& other) = delete;
	TextureManager& operator =(const TextureManager&) = delete;
	TextureManager& operator = (TextureManager&&) = delete;

	static TextureManager* GetInstance();
	///Will Create a Surface
	SDL_Surface* LoadSurface(const char* filename_);
	///SDL IMAGE CALLS
	///Will Create a texture
	static TextureInfo LoadTexture(const char* filename);
	///Will Take an SDL_Texture that is loaded and cut a portion of it and return a new texture
    static SDL_Texture* CreateTextureFromTexture(SDL_Rect sRect,SDL_Texture* source);
	///Create a sprite map 
	static MapSpriteInfo CreateMapSprite(SDL_Texture* tex_,int width_, int height_,int SizeOfCut_,int sourceX_, int sourceY_);
	
private:
	TextureManager();
	~TextureManager();
	static TextureManager* instance;
};


#endif // !TEXTUREMANAGER_H

