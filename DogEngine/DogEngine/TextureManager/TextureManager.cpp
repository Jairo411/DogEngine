#include "TextureManager.h"
#include "../../DogEngine/DogEngine.h"

TextureManager* TextureManager::instance = nullptr;

TextureManager::TextureManager()
{

}


TextureManager::~TextureManager()
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

TextureInfo TextureManager::LoadTexture(const char * filename)
{	
	TextureInfo textInfo;
	SDL_Surface* tempSurface;
	int height, width;
	tempSurface = IMG_Load(filename);
	
	
	if (tempSurface==nullptr)
	{
		std::cout << "texture not found" << std::endl;
	}


	SDL_Texture* tex = DogEngine::rendererManager->GetInstance()->GetRenderAPI<SDLRenderer*>()->CreateTextureFromSurface(tempSurface);
	SDL_QueryTexture(tex,NULL,NULL,&width,&height);
	textInfo.height = height;
	textInfo.width = width;
	textInfo.texture = tex;
	SDL_FreeSurface(tempSurface);
	
	return textInfo;
}
TextureInfo TextureManager::LoadTexture(TextureInfo info_)
{
	return TextureInfo();
}
SDL_Texture * TextureManager::CreateTextureFromTexture(SDL_Rect sRect,SDL_Texture* source)
{
	/*Loads part of the texture*/
	SDL_Texture* tex = SDL_CreateTexture(DogEngine::rendererManager->GetInstance()->GetRenderAPI<SDLRenderer*>()->GetRenderer(), SDL_PIXELFORMAT_ABGR8888,SDL_TEXTUREACCESS_TARGET,sRect.w,sRect.h);
	SDL_SetRenderTarget(DogEngine::rendererManager->GetInstance()->GetRenderAPI<SDLRenderer*>()->GetRenderer(), tex);
	SDL_SetTextureBlendMode(tex, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(DogEngine::rendererManager->GetInstance()->GetRenderAPI<SDLRenderer*>()->GetRenderer(), 0, 0, 0, 0);
	SDL_RenderClear(DogEngine::rendererManager->GetInstance()->GetRenderAPI<SDLRenderer*>()->GetRenderer());
	SDL_RenderCopy(DogEngine::rendererManager->GetInstance()->GetRenderAPI<SDLRenderer*>()->GetRenderer(), source, &sRect,NULL);
	// the following line should reset the target to default(the screen)
	SDL_SetRenderTarget(DogEngine::rendererManager->GetInstance()->GetRenderAPI<SDLRenderer*>()->GetRenderer(), NULL);
	return tex;
}

SpriteMapData TextureManager::CreateMapSprite(SDL_Texture* tex_, int width_, int height_,int SizeOfCut_,int sourceX_,int sourceY_)
{
	SpriteMapData mapInfo;
	SDL_Rect srcRect;
	SDL_Texture* tempIMG;
	SDL_Texture* mapSprite = tex_;

	int width = width_;
	int height = height_;
	int sourceX, sourceY;

	mapInfo.width = width;
	mapInfo.height = height;
	
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

			tempIMG = TextureManager::CreateTextureFromTexture(srcRect, mapSprite);
			mapInfo.sprites.push_back(tempIMG);
		}
	}
	return mapInfo;
}

SpriteMapData TextureManager::CreateMapSprite(SpriteMapData info_, SDL_Texture* spriteMapTexture_)
{


	int width;
	int height;
	int sourceX = 0;
	int sourceY = 0;
	SDL_Rect sourceRect;
	SDL_Texture* tempImage;

	width = info_.width;
	height = info_.height;


	sourceRect.x = sourceX;
	sourceRect.y = sourceY;



	// r stands for row
	for (int r = 0; r < width; r++)
	{
		// c stands for column
		for (int c = 0; c < height; c++)
		{
			sourceX = sourceX;
			sourceY = sourceY;

			sourceX = sourceX * r;
			sourceY = sourceY * c;

			tempImage = TextureManager::CreateTextureFromTexture(sourceRect, spriteMapTexture_);
			info_.sprites.push_back(tempImage);
		}
	}
	return info_;
}


