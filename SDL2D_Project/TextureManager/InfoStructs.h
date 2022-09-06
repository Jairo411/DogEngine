#ifndef INFOSTRUCTURES_H
#define INFOSTRUCTURES_H
#include <vector>
#include <string>
#include <SDL.h>
#include "../DogEngine/DogEngineDefinitions.h"
struct SpriteInfo
{
	int width;
	int height;
	float angle;
	SpriteRect rect; 
	SDL_Point center;
	SDL_RendererFlip flip;
	void operator = (const SpriteInfo spriteInfoB)
	{
		this->width = spriteInfoB.width;
		this->height = spriteInfoB.height;
		this->angle = spriteInfoB.angle;
		this->rect = spriteInfoB.rect;
		this->center = spriteInfoB.center;
		this->flip = spriteInfoB.flip;
	}
};

struct TextureInfo
{
	int width;
	int height;
	SDL_Texture* texture;
	void operator = (const TextureInfo textureInfoB)
	{
		this->width = textureInfoB.width;
		this->height = textureInfoB.height;
		this->texture = textureInfoB.texture;
	};
};

struct MapSpriteInfo
{
	int width;
	int height;
	int sizeOfCut;
	std::vector<SDL_Texture*> sprites;

	void operator = (const MapSpriteInfo MapSpriteInfo)
	{
		this->width = MapSpriteInfo.width;
		this->height = MapSpriteInfo.height;
		this->sizeOfCut = MapSpriteInfo.sizeOfCut;

		this->sprites = MapSpriteInfo.sprites;
	};
};

#endif // ! INFOSTRUCTURES_H
