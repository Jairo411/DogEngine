#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H
#include <vector>
#include <string>
#include <SDL.h>
#include "../DogEngineDefinitions.h"


/// <summary>
/// Struct containing the information of 
/// </summary>
struct Spritedata
{
	int width;
	int height;
	float angle;
	SDL_Texture* spriteTexture;
	SpriteDisplayRect rect; 
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
/// Contains SDL_Texture objects from sprite maps
/// </summary>
struct SpriteMapData
{
	std::vector<SDL_Texture*> sprites;

};

#endif // ! INFOSTRUCTURES_H
