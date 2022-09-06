#include "Tiles.h"
#include "../../../DogEngine/DogEngine.h"
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
	isSoild = solid;

}

void Tile::Render()
{
	switch (DogEngine::rendererManager->GetInstance()->getRenderValue())
	{
	default:
		break;
	case 0:// SDL
		DogEngine::rendererManager->GetInstance()->GetRenderAPI<SDLRenderer*>()->DrawTexture(baseTex, &srcRect, &dstRect);
	case 1: //OPENGL
		break;
		//Game::rendererManager->GetInstance()->GetRenderAPI<OpenGLRenderer*>()->CreateSquare();
	case 2://VULKAN

		break;
	}
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


void Tile::SetPosition(vec2 pos_)
{
	x = pos_.x;
	y = pos_.y;
}

void Tile::setGridPosition(vec2 pos_)
{
	GridPosition.x = pos_.x;
	GridPosition.y = pos_.y;
}

void Tile::Update(float deltaTime_)
{

}

vec2 Tile::getPosition()
{
	vec2 Aposition= vec2(); 
	Aposition.x = x + srcRect.w / 2;
	Aposition.y = y + srcRect.h / 2;
	return Aposition;
}

vec2 Tile::getGridPosition()
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
	return nullptr;
}

Tile::~Tile()
{
}
TileSetManager::TileSetManager()
{
	tileSetImage = nullptr;
	name = "NULL";
	ID = NULL;
	srcRect = SDL_Rect();
	desRect = SDL_Rect();
	width = NULL;
	height = NULL;
}

TileSetManager* TileSetManager::GetInstance()
{
	if (instance != nullptr)
	{
		return instance;
	}
	else
	{
		instance = new TileSetManager();
		return instance;
	}
}

TileSetManager::TileSetManager(const char* dir_, std::string name_, int ID_)
{
//	tileSetImage = TextureManager::LoadTexture(dir_);
	name = name_;
	ID = ID_;
	srcRect = SDL_Rect();
	desRect = SDL_Rect();
	SDL_QueryTexture(tileSetImage, NULL, NULL, &width, &height);
}

void TileSetManager::CreateSet(int sizeOfCut_, int srcX_, int srcY_)
{
//	imageSetHolder = TextureManager::CreateMapSprite(tileSetImage, width, height, sizeOfCut_, srcX_, srcY_);
}


void TileSetManager::SetDisplayRects(SDL_Rect tempSrcR_, SDL_Rect tempDesR_)
{
	srcRect = tempSrcR_;
	desRect = tempDesR_;
}

void TileSetManager::SetBaseImage(SDL_Texture* tempIMG_)
{
	baseImage = tempIMG_;
}

SDL_Texture* TileSetManager::getBaseImage()
{
	return baseImage;
}


TileSetManager::~TileSetManager()
{
}

TILE::TILE()
{
}

TILE::~TILE()
{
}

void TILE::OnCreate()
{
}

void TILE::OnDestroy()
{
}

void TILE::Update(float deltaTime_)
{
}

void TILE::Render()
{
}

GridPosition::GridPosition()
{
}

GridPosition::~GridPosition()
{
}

void GridPosition::OnCreate()
{
}

void GridPosition::OnDestroy()
{
}

void GridPosition::Update(float deltaTime_)
{
}

void GridPosition::Render()
{
}
