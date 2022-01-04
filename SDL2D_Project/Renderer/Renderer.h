#ifndef RENDERER_H
#define RENDERER_H
#include<SDL.h>
#include <glew.h>
#include <SDL_opengl.h>
#include <iostream>
#include <variant>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Shader.h"
#include "../GameObjects/GameObject.h";
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
class Game;
class RendererManager 
{
public:
	void OnCreate();
	void OnDestroy();
	RendererManager(RendererManager& other) = delete;
	void operator =(const RendererManager&) = delete;
	///note make sure that you can switch renderers but the machine has to reboot the program
	void setRenderer(int numbercase_);
	void setWindow(Window* window_);
	// with the addition of new renderers, this will be changed.
	static RendererManager* GetInstance();
	static int getRenderValue();
	//template function for returning the different renderers when you know what render
	template <typename T>
	T GetRenderAPI();
	template<>
	SDLRenderer* GetRenderAPI<SDLRenderer*>()
	{
		SDLRenderer* temp = nullptr;
		try
		{
			temp = std::get<SDLRenderer*>(renderVariant);
		}
		catch (const std::bad_variant_access& e)
		{
			std::cout << e.what() << std::endl;
		}
		return temp;
	};
	template<>
	OpenGLRenderer* GetRenderAPI<OpenGLRenderer*>()
	{
		OpenGLRenderer* temp = nullptr;
		try
		{
			temp = std::get<OpenGLRenderer*>(renderVariant);
		}
		catch (const std::bad_variant_access& e)
		{
			std::cout << e.what() << std::endl;
		}
		return temp;
	};
	template<>
	VulkanRenderer* GetRenderAPI<VulkanRenderer*>()
	{
		VulkanRenderer* temp = nullptr;
		try
		{
			temp = std::get<VulkanRenderer*>(renderVariant);
		}
		catch (const std::bad_variant_access& e)
		{
			std::cout << e.what() << std::endl;
		}
		return temp;
	}
	private:
	~RendererManager();
	RendererManager();
	//Renderer() over load this function when you want to add other renderer, lets start with openGL, then vulkan....
	static RendererManager* instance;
	SDL_Window* window;
	SDLRenderer* SDL__Renderer;
	OpenGLRenderer* openGLRenderer;
	VulkanRenderer* vulkanRenderer;
	std::variant<SDLRenderer*, OpenGLRenderer*, VulkanRenderer*> renderVariant;
	// a simple value that I use to tell my engine what renderer its using.
	static int RenderValue;
	int frames;
};

/* My SDL Renderer class 
 Does all my rendering stuff here, some of these functions exist simply for abstracting 
 my render process and it also seems like that, I will create own purpose rendering functions*/
class SDLRenderer 
{
public:
	SDLRenderer();
	~SDLRenderer();
	void OnCreate(SDL_Window* window_);
	void OnDestroy();
	SDL_Texture* CreateTextureFromSurface(SDL_Surface* surface_);
	void DrawTexture(SDL_Texture* tex_,SDL_Rect* srcRect_,SDL_Rect* dstRect);
	void DrawTexture(SDL_Texture* tex_, SDL_Rect* srcRect_, SDL_Rect* dstRect_, double angle_, SDL_Point* center_, SDL_RendererFlip flipFlag_);
	/// Please learn how the middle Point algorithm actually works in this case. Hard Coded
	void DrawCircle(int centreX_, int centreY_, int radius_); // I need a better draw Circle function
	void DrawLine(float startX_,float startY_, float endX_, float endY_);
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

struct Square2D 
{
	Square2D();
	void OnCreate();
	void SetImage(const char* imageSrc_);
	void SetProjection(glm::mat4 projection_);
	glm::mat4 transform;
	glm::mat4 projection;
	unsigned VBO;
	unsigned VAO;
	unsigned int projectionLoc;
	unsigned int transformLoc;
	unsigned texturePtr;
	SDL_Surface* texture;
	ShaderScript* shader;
};

struct Particle
{
	Particle();
	void OnCreate();
	void SetImage(const char* imageSrc_);
	void SetProjection(glm::mat4 projection_);

	unsigned int VBO;
	unsigned int VAO;
	unsigned int texturePtr;
	unsigned int projectionLoc;
	unsigned int transformLoc;
	unsigned int nr_particles;
	unsigned int lastUsedParticle;
	SDL_Surface* texture;
	ShaderScript* shader;
	glm::mat4 projection;
	glm::mat4 transform;
	glm::vec3 Position;
	glm::vec2 Velocity;
	glm::vec4 colour;
	float life;

};


class OpenGLRenderer 
{
public:
	OpenGLRenderer();
	~OpenGLRenderer();
	void OnCreate();
	void OnDestroy();
	void setWindow(SDL_Window* window_);
	void SetWindowSize(int width_, int height_);
	void SetViewPort(int width_, int height_);
	void RefreshWindow();
	void Update();
	glm::mat4 getProjection();
	Square2D CreateSquare(Square2D square2D_); // create a plain square don't know why I would need this. But im gonna leave this hear
	Particle CreateParticle(Particle particles_);
	

private:
	void PrintOpenGL(int* major_, int* minor_);
	void SetAttributes(int major_, int minor_);
	void SetContext();
	glm::mat4 projection;
	SDL_Window* window;
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
	int ScreenWidth;
};

#endif //RENDERER_H