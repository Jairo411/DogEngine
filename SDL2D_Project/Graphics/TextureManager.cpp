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

TextureManager* TextureManager::getInstance()
{
	if (instance==nullptr)
	{
		instance = new TextureManager();
	}
	return instance;
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


