#ifndef RENDERER_H
#define RENDERER_H
#include<SDL.h>
#include <SDL_opengl.h>
#include <iostream>
/*2021-7-15 
Renderer class will support many different renderers hopefully in the future
I will also Write the difference renderer inside my Render class
*/
// Ill get rid of this 
struct OpenGLRenderer;
struct VulkanRenderer;
class RendererManager
{
public:
	RendererManager(RendererManager& other)=delete;
	void operator =(const RendererManager&) = delete;
	// new setRenderProp
	void setRenderer(SDL_Renderer* renderer_);
	void setRenderer(VulkanRenderer renderer_);
	void setRenderer(OpenGLRenderer renderer_);
	// with the addition of new renderers, this will be changed.
	SDL_Renderer* getRenderer(); 
	static RendererManager* getInstance();
private:
	~RendererManager();
	RendererManager();
	//Renderer() over load this function when you want to add other renderer, lets start with openGL, then vulkan....
	static RendererManager* instance;
	SDL_Renderer* currentRenderer;
	SDL_Window* window;
};

struct OpenGLRenderer
{
public:
	OpenGLRenderer();
	~OpenGLRenderer();
	void OnCreate();
	void OnDestroy();
	void PrintOpenGL(int* major_, int* minor_);
	void SetAttributes(int major_, int minor_);

	SDL_GLContext context;
	GLenum error;
	int ScreenHeight;
	int ScreenWidith;
};
// Vulkan implementation really is the last thing you want to implement
struct VulkanRenderer
{
public:
	VulkanRenderer();
	~VulkanRenderer();

	void OnCreate();
	void OnDestroy();


	int ScreenHeight;
	int ScreenWidith;
};

#endif