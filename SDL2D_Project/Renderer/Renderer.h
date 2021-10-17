#ifndef RENDERER_H
#define RENDERER_H
#include<SDL.h>
#include <glew.h>
#include <SDL_opengl.h>
#include <iostream>
#include <variant>
/*2021-7-15
Renderer class will support many different renderers hopefully in the future
I will also Write the difference renderer inside my Render class.
2021-10-17
a variant variable has been added to my rendererManager class in order to abstract my rendering process a bit more.
*/

class OpenGLRenderer;
class VulkanRenderer;
class SDLRenderer;
class Window;
class RendererManager
{
public:
	void OnCreate();
	void OnDestroy();
	RendererManager(RendererManager& other) = delete;
	void operator =(const RendererManager&) = delete;
	void setRenderer(int numbercase_);
	void setWindow(Window* window_);
	std::variant<SDL_Renderer*, OpenGLRenderer*, VulkanRenderer*> getRenderer();
	// with the addition of new renderers, this will be changed.
	static RendererManager* GetInstance();
	static int getRenderValue();

	//template function for returning my different renderers
	template <typename T>
	T GetRenderer()
	{
	};
	template<>
	SDL_Renderer* GetRenderer<SDL_Renderer*>()
	{
		SDL_Renderer* temp;
		try
		{
			temp = std::get<SDL_Renderer*>(renderVariant);
			return temp;
		}
		catch (const std::bad_variant_access& e)
		{
			std::cout << e.what() << std::endl;
		}
	};
	template<>
	OpenGLRenderer* GetRenderer<OpenGLRenderer*>()
	{
		OpenGLRenderer* temp;
		try
		{
			temp = std::get<OpenGLRenderer*>(renderVariant);
			return temp;
		}
		catch (const std::bad_variant_access& e)
		{
			std::cout << e.what() << std::endl;
		}
	};
	template<>
	VulkanRenderer* GetRenderer<VulkanRenderer*>()
	{
		VulkanRenderer* temp;
		try
		{
			temp = std::get<VulkanRenderer*>(renderVariant);
			return temp;
		}
		catch (const std::bad_variant_access& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	private:
	~RendererManager();
	RendererManager();
	//Renderer() over load this function when you want to add other renderer, lets start with openGL, then vulkan....
	static RendererManager* instance;
	SDL_Renderer* SDLRenderer;
	OpenGLRenderer* openGLRenderer;
	VulkanRenderer* vulkanRenderer;
	SDL_Window* window;
	std::variant<SDL_Renderer*, OpenGLRenderer*, VulkanRenderer*> renderVariant;
	// a simple value that I use to tell my engine what renderer its using.
	static int RenderValue;
};

class SDLRenderer
{
public:

private:

};


class OpenGLRenderer
{
public:
	OpenGLRenderer();
	~OpenGLRenderer();
	void OnCreate();
	void OnDestroy();
	void PrintOpenGL(int* major_, int* minor_);
	void SetAttributes(int major_, int minor_);
	void SetViewPort(int width_, int height_);
	void Update(float dt_);
	void Render();
private:
	SDL_GLContext* context;
	GLenum error;
	int ScreenHeight;
	int ScreenWidth;
};
// Vulkan implementation really is the last thing you want to implement
class VulkanRenderer
{
public:
	VulkanRenderer();
	~VulkanRenderer();

	void OnCreate();
	void OnDestroy();


	int ScreenHeight;
	int ScreenWidith;
};

#endif //RENDERER_H