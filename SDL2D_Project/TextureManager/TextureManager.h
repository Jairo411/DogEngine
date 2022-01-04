#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include <string>
#include <vector>
#include <variant>
#include <assert.h>
#include "../Game/Game.h"
#include "../Renderer/Renderer.h"
/*2021-07-09 
	Soild*/
//2021-10-17 not soild enough 


/*TextureManager class has reference of all renderers now. 
 Not all of the same calls will work so I will have to be careful and abstract my TextureManager code a bit more.*/
class TextureManager
{
public:

	void OnCreate();
	void OnDestroy();

	static TextureManager* GetInstance();

	TextureManager(TextureManager& other) = delete;
	void operator =(const TextureManager&) = delete;

	
	///Will Create a Surface
	SDL_Surface* LoadSurface(const char* filename_);

	///SDL IMAGE CALLS
	///Will Create a texture
	static SDL_Texture* LoadTexture(const char* filename);
	///Will Take a SDL_Texture and cut and portion of it and return a texture
    static SDL_Texture* LoadTexture(SDL_Rect sRect,SDL_Texture* source);
	///Create a sprite map 
	static std::vector<SDL_Texture*> CreateMapSprite(SDL_Texture* tex_,int width_, int height_,int SizeOfCut_,int sourceX_, int sourceY_);
	
private:
	TextureManager();
	~TextureManager();
	static TextureManager* instance;
};


#endif // !TEXTUREMANAGER_H

