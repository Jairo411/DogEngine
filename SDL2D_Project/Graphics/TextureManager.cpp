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
	assert(std::get<SDL_Renderer*>(renderInfo) != nullptr);
	SDL_Surface* tempSurface;

	tempSurface = IMG_Load(filename);
	
	if (tempSurface==nullptr)
	{
		std::cout << "texture not found" << std::endl;
	}


	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::rendererManager->GetInstance()->GetRenderer<SDL_Renderer*>(), tempSurface);
	SDL_FreeSurface(tempSurface);
	
	return tex;
}
SDL_Texture * TextureManager::LoadTexture(SDL_Rect sRect,SDL_Texture* source)
{
	assert(std::get<SDL_Renderer*>(renderInfo) != nullptr);
	/*Loads part of the texture*/
	SDL_Texture* tex = SDL_CreateTexture(Game::rendererManager->GetInstance()->GetRenderer<SDL_Renderer*>(), SDL_PIXELFORMAT_ABGR8888,SDL_TEXTUREACCESS_TARGET,sRect.w,sRect.h);
	SDL_SetRenderTarget(Game::rendererManager->GetInstance()->GetRenderer<SDL_Renderer*>(), tex);
	SDL_SetTextureBlendMode(tex, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(Game::rendererManager->GetInstance()->GetRenderer<SDL_Renderer*>(), 0, 0, 0, 0);
	SDL_RenderClear(Game::rendererManager->GetInstance()->GetRenderer<SDL_Renderer*>());
	SDL_RenderCopy(Game::rendererManager->GetInstance()->GetRenderer<SDL_Renderer*>(), source, &sRect,NULL);
	// the following line should reset the target to default(the screen)
	SDL_SetRenderTarget(Game::rendererManager->GetInstance()->GetRenderer<SDL_Renderer*>(), NULL);
	return tex;
}

std::vector<SDL_Texture*> TextureManager::CreateMapSprite(SDL_Texture* tex_, int width_, int height_,int SizeOfCut_,int sourceX_,int sourceY_)
{
	assert(std::get<SDL_Renderer*>(renderInfo) != nullptr);
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



void TextureManager::Draw(SDL_Texture * tex, SDL_Rect src, SDL_Rect dest)
{
	SDL_RenderCopy(Game::rendererManager->GetInstance()->GetRenderer<SDL_Renderer*>(),tex,&src,&dest);
}

void TextureManager::setRenderer(SDL_Renderer* renderer_)
{
	renderInfo = renderer_;
}

void TextureManager::setRenderer(OpenGLRenderer* renderer_)
{
	renderInfo = renderer_;
}

void TextureManager::setRenderer(VulkanRenderer* renderer_)
{
	renderInfo = renderer_;
}

