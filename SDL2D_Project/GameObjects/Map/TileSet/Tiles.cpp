#include "Tiles.h"
#include "C:\Users\jalbm\source\repos\SDL2D_Project\SDL2D_Project\TextureManager\TextureManager.h"

map<int, SDL_Texture*> TileSet::imageSetHolder;
TileSet* TileSet::instance;
int Tile::width = 0; 
int Tile::height = 0;
Tile::Tile()
{
	baseTex = __nullptr;
	srcRect.x = 0;
	srcRect.y = 0;
	width = 0;
	height = 0;
	ID = NULL;
	x = 0;
	y = 0;
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

Tile::Tile(SDL_Texture* texture_, int srcX, int srcY, bool solid)
{
	baseTex = texture_;

	x = 0;
	y = 0;

	ID = NULL;

	srcRect.x = 0;
	srcRect.y = 0;

	srcRect.w = width;
	srcRect.h = height;

	dstRect.x = srcX;
	dstRect.y = srcY;

	dstRect.w = srcRect.w;
	dstRect.h = srcRect.h;
	col = Collider(srcX, srcY, 20);
	isSoild = solid;

}

void Tile::OnRender()
{
	
	SDL_RenderCopy(Game::renderer, baseTex, &srcRect,&dstRect);
	col.CollisonRender();
}

void Tile::setTileSize(int width_, int height_)
{
	width = width_;
	height = height_;
}

int Tile::getWidth()
{
	return width;
}

int Tile::getHeight()
{
	return height;
}

int Tile::getX()
{
	return x;
}

int Tile::getY()
{
	return y;
}

bool Tile::keyBoardInput(int key_)
{
	return false;
}

bool Tile::mouseInput(int key_)
{
	if (key_!=NULL)
	{
		if (key_==SDL_BUTTON_LEFT)
		{
			SDL_Rect result;
			TileSet* set = TileSet::GetInstance();
			if (SDL_IntersectRect(col.getCollider(),Input::mouseClick->getCollider(),&result))
			{
				baseTex = set->getTile(5);
			}
		}
		return true;
	}
	return false;
}

bool Tile::controllerInput(int key_)
{
	return false;
}

void Tile::setX(int x_)
{
	x = x_;
}

void Tile::setY(int y_)
{
	y = y_;
}

void Tile::OnUpdate()
{
	
}

SDL_Texture * Tile::getTex()
{
	return baseTex;
}

SDL_Rect Tile::getSrcRect()
{
	return srcRect;
}

<<<<<<< HEAD
int Tile::getID()
{
	return ID;
}

void Tile::SetID(int ID_)
{
	ID = ID_;
}
=======

>>>>>>> parent of e7eaafc... 2020-08-26 9:35 PM

Tile::~Tile()
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

TileSet* TileSet::RemoveInstance()
{
	if (instance!=nullptr)
	{
		instance = nullptr;
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
	int width=0, height=0;
	desRect.h = srcRect.h;
	desRect.w = srcRect.w;
	
	SDL_QueryTexture(actualIMG,NULL,NULL,&width, &height);
	width = width / 20;
	height = height / 20;
	 for (int c = 0; c < width; c++)
		 for (int r = 0; r <height; r++)
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

