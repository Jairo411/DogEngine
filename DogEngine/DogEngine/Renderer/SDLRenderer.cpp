#include "SDLRenderer.h"

SDLRenderer::SDLRenderer()
{
	rend = nullptr;
	window = nullptr;
}
SDLRenderer::~SDLRenderer()
{
	OnDestroy();
}

void SDLRenderer::OnCreate(SDL_Window* window_)
{
	rend = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED && SDL_RENDERER_TARGETTEXTURE && SDL_RENDERER_PRESENTVSYNC);
	window = window_;

	if (rend == nullptr)
	{
		std::cout << "SDL renderer could not be created" << std::endl;
	}
	else
	{
		std::cout << "SDL Renderer has been Intialized" << std::endl;
	}

	SDL_SetRenderDrawColor(rend, 225, 225, 225, 225);
}

void SDLRenderer::OnDestroy()
{

	rend = nullptr;
	window = nullptr;
	delete rend;
	delete window;
}

SDL_Texture* SDLRenderer::CreateTextureFromSurface(SDL_Surface* surface_)
{
	SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surface_);
	return tex;
}

void SDLRenderer::DrawTexture(SDL_Texture* tex_, SDL_Rect* srcRect_, SDL_Rect* dstRect_)
{
	SDL_RenderCopy(rend, tex_, srcRect_, dstRect_);
}

void SDLRenderer::DrawTexture(SDL_Texture* tex_, SDL_Rect* srcRect_, SDL_Rect* dstRect_, double angle_, SDL_Point* center_, SDL_RendererFlip flipFlag_)
{
	SDL_RenderCopyEx(rend, tex_, srcRect_, dstRect_, angle_, center_, flipFlag_);
}

void SDLRenderer::DrawCircle(float centreX_, float centreY_, float radius_)
{

	SDL_SetRenderDrawColor(rend, 89, 225, 0, 1);

	float fcentreX = centreX_;
	float fcentreY = centreY_;
	float fradius = radius_;
	SDL_FPoint points[24000];
	float xPoint = 0;
	float yPoint = 0;
	int index = 0;
	for (float i = 0.000f; i < 360.000f;)
	{
		//get a point on the circle using cartesan coordinates with the origin of this circle being (0,0)
		xPoint = fradius * cosf(i);
		yPoint = fradius * sinf(i);

		points[index].x = xPoint;
		points[index].y = yPoint;

		//Move the origin of the circle to where my object actually is 
		//SDL_RenderDrawPoint(rend, xPoint, yPoint);
		i += 0.015f;
		index++;
	}

	for (int i = 0; i < 24000; i++)
	{
		points[i].x += fcentreX;
		points[i].y += fcentreY;
	}

	SDL_RenderDrawPointsF(rend, &points[0], 24000);

	SDL_SetRenderDrawColor(rend, 225, 225, 225, 225);
}

void SDLRenderer::DrawLine(float startX_, float startY_, float endX_, float endY_)
{
	SDL_RenderDrawLine(rend, startX_, startY_, endX_, endY_);
}

void SDLRenderer::DrawPoint(int x_, int y_)
{
	SDL_RenderDrawPoint(rend, x_, y_);
}

void SDLRenderer::DrawRect(SDL_Rect* rect_)
{
	SDL_SetRenderDrawColor(rend, 89, 225, 0, 1);
	SDL_RenderDrawRect(rend, rect_);
	SDL_SetRenderDrawColor(rend, 225, 225, 225, 225);
	//SDL_RenderClear(rend);
}

void SDLRenderer::DrawRect(int x_, int y_, int width_, int height_)
{
	SDL_Rect* tempRect;

	tempRect = new SDL_Rect();

	tempRect->x = x_;
	tempRect->y = y_;

	tempRect->w = width_;
	tempRect->h = height_;

	SDL_RenderDrawRect(rend, tempRect);
}

void SDLRenderer::SetRenderDrawColour(Uint8 r_, Uint8 g_, Uint8 b_, Uint8 a_)
{
	SDL_SetRenderDrawColor(rend, r_, g_, b_, a_);
}

SDL_Renderer* SDLRenderer::GetRenderer()
{
	return rend;
}

void SDLRenderer::RenderClear()
{
	SDL_RenderClear(rend);
}

void SDLRenderer::RenderPresent()
{
	SDL_RenderPresent(rend);
}


int SDLRenderer::getTotalFrames()
{
	return totalFrames;
}