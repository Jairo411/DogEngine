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
	SDL_SetTextureBlendMode(tex, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 0);
	SDL_RenderClear(Game::renderer);
	SDL_RenderCopy(Game::renderer, source, &sRect,NULL);
	// the following line should reset the target to default(the screen)
	SDL_SetRenderTarget(Game::renderer, NULL);
	return tex;
}

std::vector<SDL_Texture*> TextureManager::LoadMapSprite(SDL_Texture* tex_, int width_, int height_,int SizeOfCut_,int sourceX_,int sourceY_)
{
	std::vector<SDL_Texture*> MapSpriteContainer;
	SDL_Rect srcRect;
	SDL_Texture* tempIMG;
	SDL_Texture* mapSprite = tex_;
	int width = width_;
	int height = height_;
	int sourceX, sourceY;
	
	width = width / SizeOfCut_;
	height = height / SizeOfCut_;

	srcRect.w = sourceX_;
	srcRect.h = sourceY_;

	for (int r = 0; r < width; r++)
	{
		for (int c = 0; c < height; c++)
		{
			sourceX = sourceX_ *r;
			sourceY = sourceY_ *c;
			srcRect.x = sourceX;
			srcRect.y = sourceY;

			tempIMG = TextureManager::LoadTexture(srcRect, mapSprite);
			MapSpriteContainer.push_back(tempIMG);
		}
	}
	return MapSpriteContainer;
}



void TextureManager::Draw(SDL_Texture * tex, SDL_Rect src, SDL_Rect dest)
{
	SDL_RenderCopy(Game::renderer,tex,&src,&dest);
}

