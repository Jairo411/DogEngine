#ifndef RENDERER_H
#define RENDERER_H
#include<SDL.h>
/*2021-7-15 
Renderer class will support many different renderers hopefully in the future
*/
struct RenderProp
{
	SDL_Renderer* renderer;
};
class Renderer
{
public:
	Renderer(Renderer& other)=delete;
	void operator =(const Renderer&) = delete;
	//Takes in a RenderProperty Structure and intializes Renderer's class member variables.
	void setRenderProp(RenderProp RenderProperties_);
	// with the addition of new renderers, this will be changed.
	SDL_Renderer* getRenderer(); 
	static Renderer* getInstance();
	static RenderProp* properties; 
private:
	~Renderer();
	Renderer();
	//Renderer() over load this function when you want to add other renderer, lets start with openGL, then vulkan....
	static Renderer* instance;
	SDL_Renderer* currentRenderer;
};
#endif