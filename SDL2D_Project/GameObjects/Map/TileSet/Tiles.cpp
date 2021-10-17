#include "Tiles.h"
#include "../../../Graphics/TextureManager.h"

vector<SDL_Texture*> TileSet::imageSetHolder = vector<SDL_Texture*>();
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

	srcRect.w = 40;
	srcRect.h = 40;

	dstRect.w = srcRect.w;
	dstRect.h = srcRect.h;
	isSoild = NULL;
}

Tile::Tile(int srcX_, int srcY_)
{
	//baseTex =  ;
	x = srcX_;
	y = srcY_;
	srcRect.x = x;
	srcRect.y = y;

	ID = NULL;

}

Tile::Tile(SDL_Texture* texture_, int srcX, int srcY, bool solid)
{
	baseTex = texture_;

	x = srcX;
	y = srcY;

	ID = NULL;

	srcRect.x = 0;
	srcRect.y = 0;

	srcRect.w = width;
	srcRect.h = height;

	dstRect.x = srcX;
	dstRect.y = srcY;

	dstRect.w = srcRect.w;
	dstRect.h = srcRect.h;
	col = RectCollider(x, y, dstRect.w);
	isSoild = solid;

}

void Tile::OnRender()
{

	SDL_RenderCopy(Game::rendererManager->GetInstance()->getRenderer(), baseTex, &srcRect, &dstRect);
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



bool Tile::KeyBoardInput(int key_)
{
	return false;
}

bool Tile::MouseInput(int key_)
{
	return false;
}

bool Tile::ControllerInput(int key_)
{
	return false;
}

void Tile::SetPosition(Vec2 pos_)
{
	x = pos_.x;
	y = pos_.y;
}

void Tile::setGridPosition(Vec2 pos_)
{
	GridPosition.x = pos_.x;
	GridPosition.y = pos_.y;
}

void Tile::OnUpdate()
{

}

Vec2 Tile::getPosition()
{
	Vec2 Aposition= Vec2(); 
	Aposition.x = x + srcRect.w / 2;
	Aposition.y = y + srcRect.h / 2;
	return Aposition;
}

Vec2 Tile::getGridPosition()
{
	return GridPosition;
}

SDL_Texture* Tile::getTex()
{
	return baseTex;
}

SDL_Rect Tile::getSrcRect()
{
	return srcRect;
}


void Tile::SetID(int ID_)
{
	ID = ID_;
	n = new Node(ID);
}

Node* Tile::getID(int ID_)
{
	if (ID_==n->label)
	{
		return n;
	}
}

Tile::~Tile()
{
}
TileSet::TileSet()
{
	tileSetImage = nullptr;
	name = "NULL";
	ID = NULL;
	srcRect = SDL_Rect();
	desRect = SDL_Rect();
	width = NULL;
	height = NULL;
}
//Might change this name thingy
TileSet::TileSet(const char* dir_, string name_, int ID_)
{
	tileSetImage = TextureManager::LoadTexture(dir_);
	name = name_;
	ID = ID_;
	srcRect = SDL_Rect();
	desRect = SDL_Rect();
	SDL_QueryTexture(tileSetImage, NULL, NULL, &width, &height);
}

void TileSet::CreateSet(int sizeOfCut_, int srcX_, int srcY_)
{
	imageSetHolder = TextureManager::CreateMapSprite(tileSetImage, width, height, sizeOfCut_, srcX_, srcY_);
}


void TileSet::SetDisplayRects(SDL_Rect tempSrcR_, SDL_Rect tempDesR_)
{
	srcRect = tempSrcR_;
	desRect = tempDesR_;
}

void TileSet::SetBaseImage(SDL_Texture* tempIMG_)
{
	baseImage = tempIMG_;
}

SDL_Texture* TileSet::getBaseImage()
{
	return baseImage;
}

vector<SDL_Texture*> TileSet::GetTileSet()
{
	return imageSetHolder;
}


SDL_Texture* TileSet::getTile(int index_)
{
	return imageSetHolder[index_];
}

TileSet::~TileSet()
{
}