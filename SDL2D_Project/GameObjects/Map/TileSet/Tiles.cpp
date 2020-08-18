#include "Tiles.h"
#include "C:\Users\jalbm\source\repos\SDL2D_Project\SDL2D_Project\TextureManager\TextureManager.h"

map<int, SDL_Texture*> TileSet::imageSetHolder;
TileSet* TileSet::instance;
Tiles::Tiles()
{
	baseTex = __nullptr;
	srcRect.x = 0;
	srcRect.y = 0;
	/*old verison of the regular width and height 
		w=16 
		h=30
	*/
	srcRect.w = 40;
	srcRect.h = 40;

	dstRect.w = srcRect.w;
	dstRect.h = srcRect.h;
	isSoild = NULL;

}

Tiles::Tiles(SDL_Texture* texture_, int srcX, int srcY, bool solid)
{
	baseTex = texture_;

	srcRect.x = 0;
	srcRect.y = 0;
	/*old verison of the regular width and height
		w=16
		h=30
	*/
	srcRect.w = 40;
	srcRect.h = 40;

	dstRect.x = srcX;
	dstRect.y = srcY;

	dstRect.w = 40;
	dstRect.h = 40;



	isSoild = solid;
	
}

void Tiles::OnRender()
{
	
	SDL_RenderCopy(Game::renderer, baseTex, &srcRect,&dstRect);
	
}

void Tiles::OnUpdate()
{
	
}

SDL_Texture * Tiles::getTex()
{
	return baseTex;
}

SDL_Rect Tiles::getSrcRect()
{
	return srcRect;
}



Tiles::~Tiles()
{
}
//Might change this name thingy
TileSet::TileSet(std::string tempName, int tempID)
{
	//tileSet = "Assets/Level Sprites/Foreground/Tileset.png"; 
	name = tempName;
	ID = tempID;
	srcRect.w = 16;
	srcRect.h = 30;
	srcRect.x = 0;
	srcRect.y = 0;
	Init();
}

TileSet* TileSet::GetInstance()
{

	if (instance==nullptr)
	{
		instance = new TileSet("BaseLayer",0);
	}
	return instance;
}

TileSet::~TileSet()
{
}

void TileSet::Init()
{
	SDL_Texture* tempIMG;
	SDL_Texture* actualIMG;
	actualIMG = TextureManager::LoadTexture("Assets/Level Sprites/Foreground/Tileset.png");
	int sourceX =0;
	int sourceY=0;	
	desRect.h = srcRect.h;
	desRect.w = srcRect.w;
	

	 for (int c = 0; c < 3; c++)
		 for (int r = 0; r <10; r++)
		 {
			 sourceX = 16 * r;
			 sourceY = 32 * c;
			 srcRect.x = sourceX;
			 srcRect.y = sourceY;
			
			 tempIMG = TextureManager::LoadTexture(srcRect,actualIMG);
			 // it's working now 
			 imageSetHolder.insert(make_pair(c+r,tempIMG));
		 }
	 }

std::map<int, SDL_Texture*> TileSet::GetTileSet()
{
	return imageSetHolder;
}

SDL_Texture * TileSet::getTile(int key_)
{
	return imageSetHolder[key_];
}

/*void TileSet::TestRender()
{
		// I know This works  now 
	//	SDL_RenderCopy(Game::renderer, TextureManager::LoadTexture("Assets/Level Sprites/Foreground/Tileset.png"), NULL, NULL);
		SDL_RenderCopy(Game::renderer, imageSetHolder[5],NULL,NULL);
		
}*/
