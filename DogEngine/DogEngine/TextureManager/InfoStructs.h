#ifndef INFOSTRUCTURES_H
#define INFOSTRUCTURES_H
#include <vector>
#include <string>
#include <SDL.h>
#include "../DogEngineDefinitions.h"


/// <summary>
/// Width and height contain the information of image dimensions
/// Path is just the string path to the image.
/// SpriteRect is a typedef that just contains the information of the sourcerect and display rect 
/// Center is just the center of the sprite.
/// flip is a enum value
/// </summary>

struct Spritedata
{
	int width;
	int height;
	const char* path;
	float angle;
	SpriteRect rect; 
	SDL_Point center;
	SDL_RendererFlip flip;
	void operator = (const Spritedata spriteInfoB)
	{
		this->width = spriteInfoB.width;
		this->height = spriteInfoB.height;
		this->angle = spriteInfoB.angle;
		this->rect = spriteInfoB.rect;
		this->center = spriteInfoB.center;
		this->flip = spriteInfoB.flip;
	}
};

/// <summary>
/// Width and height contain the information of image dimensions.
/// Path is just the string path to the image.
/// Texture is just a pointer to the image.
/// </summary>
struct TextureInfo
{
	int width;
	int height;
	const char* path;
	SDL_Texture* texture;
	void operator = (const TextureInfo textureInfoB)
	{
		this->width = textureInfoB.width;
		this->height = textureInfoB.height;
		this->texture = textureInfoB.texture;
	};
};
/// <summary>
/// width and height is the size of the SpriteMap
/// Path is just the string path to the image.
/// SizeOfCut is the area of the cut to be made out of each specific cut. 
/// sprites is a collection of pointers to the images in the heap. 
/// </summary>
struct SpriteMapData
{
	int width;
	int height;
	int sizeOfCut;
	const char* path;
	std::vector<SDL_Texture*> sprites;

	void operator = (const SpriteMapData MapSpriteInfo)
	{
		this->width = MapSpriteInfo.width;
		this->height = MapSpriteInfo.height;
		this->sizeOfCut = MapSpriteInfo.sizeOfCut;

		this->sprites = MapSpriteInfo.sprites;
	};
};

#endif // ! INFOSTRUCTURES_H
