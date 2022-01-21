#ifndef INFOSTRUCTURES_H
#define INFOSTRUCTURES_H
#include <vector>
#include <string>
#include <SDL.h>
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
