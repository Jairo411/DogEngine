#ifndef SDLRENDERER_H
#define SDLRENDERER_H
#include <SDL.h>
#include <iostream>
/*11-01-2024
* Abstraction of SDL render function calls
*/
class SDLRenderer
{
public:
	SDLRenderer();
	~SDLRenderer();
	void OnCreate(SDL_Window* window_);
	void OnDestroy();
	SDL_Texture* CreateTextureFromSurface(SDL_Surface* surface_);
	void DrawTexture(SDL_Texture* tex_, SDL_Rect* srcRect_, SDL_Rect* dstRect);
	void DrawTexture(SDL_Texture* tex_, SDL_Rect* srcRect_, SDL_Rect* dstRect_, double angle_, SDL_Point* center_, SDL_RendererFlip flipFlag_);
	/// Please learn how the middle Point algorithm actually works in this case. Hard Coded
	void DrawCircle(float centreX_, float centreY_, float radius_); // I need a better draw Circle function
	void DrawLine(float startX_, float startY_, float endX_, float endY_);
	void DrawPoint(int x_, int y_);
	void DrawRect(SDL_Rect* rect_);
	void DrawRect(int x_, int y_, int width_, int height_);
	void SetRenderDrawColour(Uint8 r_, Uint8 g_, Uint8 b_, Uint8 a_);
	SDL_Renderer* GetRenderer();
	void RenderClear();
	void RenderPresent();
	int getTotalFrames();
private:
	SDL_Renderer* rend;
	SDL_Window* window;
	int totalFrames;
};
#endif // !SDLRENDERER_H