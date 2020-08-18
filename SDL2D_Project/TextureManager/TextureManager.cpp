#include "TextureManager.h"



TextureManager::TextureManager()
{
}


TextureManager::~TextureManager()
{
}

SDL_Texture * TextureManager::LoadTexture(const char * filename)
{
	SDL_Surface *tempSurface =  IMG_Load(filename);
	
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);	
	SDL_FreeSurface(tempSurface);
	
	return tex;
}
SDL_Texture * TextureManager::LoadTexture(SDL_Rect sRect,SDL_Texture* source)
{
	/*Loads part of the texture*/
	SDL_Texture* tex = SDL_CreateTexture(Game::renderer, SDL_PIXELFORMAT_ABGR8888,SDL_TEXTUREACCESS_TARGET,sRect.w,sRect.h);
	SDL_SetRenderTarget(Game::renderer, tex);
	SDL_RenderClear(Game::renderer);
	SDL_RenderCopy(Game::renderer, source, &sRect,NULL);
	// the following line should reset the target to default(the screen)
	SDL_SetRenderTarget(Game::renderer, NULL);
	return tex;
}



void TextureManager::Draw(SDL_Texture * tex, SDL_Rect src, SDL_Rect dest)
{
	SDL_RenderCopy(Game::renderer,tex,&src,&dest);
}

