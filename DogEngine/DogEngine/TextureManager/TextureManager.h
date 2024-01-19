#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include <string>
#include <vector>
#include <variant>
#include <assert.h>
#include "DataStructs.h"
/*
* 8/16/2022
* Singleton texture manager system, that loads/creates SDL textures. 
* 
* SDL textures are driver specific optimized data of pixels. That is it.
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
		/// <summary>
		/// Will return a SDL_Surface which is a structure that contains 
		/// the informations of pixels for software blitting.
		/// </summary>
		SDL_Surface* LoadSurface(const char* p_);
		/// <summary>
		/// Will load pixel data into a SDL_Texture, which 
		/// is a driver-specific representation of pixel data. Meaning that if 
		/// depending on the rendering driver you're currently using, direct3d, opengl, vulkan etc. 
		/// SDL will create a specific type of texture that arranges the pixels for you in a such a manner, 
		/// that is efficient for that specific rendering driver.
		/// </summary>
		/// <returns></returns>
		static SDL_Texture* LoadTexture(const char* p_);
		///Will Create a texture
		///Will Copy a portion of an SDL_Texture loaded into memory and then create a new instance of that texture.
		static SDL_Texture* CreateTextureFromTexture(SDL_Rect sRect, SDL_Texture* source);
		///Create a sprite map 
		static SpriteMapData CreateMapSprite(SDL_Texture* tex_, int width_, int height_, int SizeOfCut_, int sourceX_, int sourceY_);
		///Create a collection of sprites from a sprite map 
		static SpriteMapData CreateMapSprite(SDL_Texture* spirteMaptexture_);
	private:
		TextureManager();
		~TextureManager();
		static TextureManager* instance;
	};



#endif // !TEXTUREMANAGER_H

