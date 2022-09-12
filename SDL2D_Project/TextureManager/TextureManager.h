#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include <string>
#include <vector>
#include <variant>
#include <assert.h>
#include "InfoStructs.h"
/*
* 8/16/2022
* Singleton texture manager interface, that loads/creates textures. 
*/
class DogEngine;
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
	///Will Create a texture
	static TextureInfo LoadTexture(TextureInfo info_);
	///Will Take an SDL_Texture that is loaded and cut a portion of it and return a new texture
    static SDL_Texture* CreateTextureFromTexture(SDL_Rect sRect,SDL_Texture* source);
	///Create a sprite map 
	static SpriteMapInfo CreateMapSprite(SDL_Texture* tex_,int width_, int height_,int SizeOfCut_,int sourceX_, int sourceY_);
	///Create a sprite map 
	static SpriteMapInfo CreateMapSprite(SpriteMapInfo info_, SDL_Texture* spriteMaptexture_);
private:
	TextureManager();
	~TextureManager();
	static TextureManager* instance;
};


#endif // !TEXTUREMANAGER_H

