#include "TextureManager.h"

TextureManager* TextureManager::instance = nullptr;

TextureManager::TextureManager()
{
	OnCreate();
}


TextureManager::~TextureManager()
{
	OnDestroy();
}

void TextureManager::OnCreate()
{
}

void TextureManager::OnDestroy()
{
}

TextureManager* TextureManager::GetInstance()
{
	if (instance==nullptr)
	{
		instance = new TextureManager();
	}
	return instance;
}

SDL_Surface* TextureManager::LoadSurface(const char* filename_)
{
	SDL_Surface* tempSurface = IMG_Load(filename_);

	assert(tempSurface != NULL); // if the sdlSurface returns null its and the file directory is correct, its most likely because IMG_LOAD doesn't support the picture file format that you gave it. 

	SDL_LockSurface(tempSurface);

	int pitch = tempSurface->pitch; // row size
	char* temp = new char[pitch];
	char* pixels = (char*)tempSurface->pixels;

	for (int i = 0; i < tempSurface->h/2; i++)
	{
		//get pointers to the two rows to swap 

		char* row1 = pixels + i * pitch;
		char* row2 = pixels + (tempSurface->h - 1) * pitch;

		//swap rows 
		memcpy(temp, row1, pitch);
		memcpy(temp, row2, pitch);
		memcpy(row2, temp, pitch);
	}

	delete[] temp;
	SDL_UnlockSurface(tempSurface);
	return tempSurface;
}

SDL_Texture * TextureManager::LoadTexture(const char * filename)
{	
	SDL_Surface* tempSurface;

	tempSurface = IMG_Load(filename);
	
	if (tempSurface==nullptr)
	{
		std::cout << "texture not found" << std::endl;
	}


	SDL_Texture* tex = Game::rendererManager->GetInstance()->GetRenderAPI<SDLRenderer*>()->CreateTextureFromSurface(tempSurface);
	SDL_FreeSurface(tempSurface);
	
	return tex;
}
SDL_Texture * TextureManager::LoadTexture(SDL_Rect sRect,SDL_Texture* source)
{
	/*Loads part of the texture*/
	SDL_Texture* tex = SDL_CreateTexture(Game::rendererManager->GetInstance()->GetRenderAPI<SDLRenderer*>()->GetRenderer(), SDL_PIXELFORMAT_ABGR8888,SDL_TEXTUREACCESS_TARGET,sRect.w,sRect.h);
	SDL_SetRenderTarget(Game::rendererManager->GetInstance()->GetRenderAPI<SDLRenderer*>()->GetRenderer(), tex);
	SDL_SetTextureBlendMode(tex, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(Game::rendererManager->GetInstance()->GetRenderAPI<SDLRenderer*>()->GetRenderer(), 0, 0, 0, 0);
	SDL_RenderClear(Game::rendererManager->GetInstance()->GetRenderAPI<SDLRenderer*>()->GetRenderer());
	SDL_RenderCopy(Game::rendererManager->GetInstance()->GetRenderAPI<SDLRenderer*>()->GetRenderer(), source, &sRect,NULL);
	// the following line should reset the target to default(the screen)
	SDL_SetRenderTarget(Game::rendererManager->GetInstance()->GetRenderAPI<SDLRenderer*>()->GetRenderer(), NULL);
	return tex;
}

std::vector<SDL_Texture*> TextureManager::CreateMapSprite(SDL_Texture* tex_, int width_, int height_,int SizeOfCut_,int sourceX_,int sourceY_)
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
			sourceX = sourceX_;
			sourceY = sourceY_;

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


