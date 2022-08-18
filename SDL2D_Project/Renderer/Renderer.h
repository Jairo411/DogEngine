#ifndef RENDERER_H
#define RENDERER_H
#include <cstddef>
#include <cstdint>
#include <numeric>
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
/*
* 8/16/2022
* Singleton renderermanger interface. 
* -Handles all rendererAPI calls.
*/
class OpenGLRenderer;
class VulkanRenderer;
class SDLRenderer;
class Window;
class DogEngine;

enum class RenderAPI
{
	SDLAPI = 0,
	OPENGLAPI = 1,
	VULKANAPI = 2,
	
};
class RendererManager 
{
public:
	RendererManager(RendererManager& other) = delete;
	void operator =(const RendererManager&) = delete;
	///Set RenderAPI.
	void SetRenderer(int numbercase_);
	//New SetRenderer subroutine 
	void SetRenderer(RenderAPI api_);
	///Pass current window context.
	void setWindow(Window* window_);
	static RendererManager* GetInstance();
	static int getRenderValue();
	/// Return current rendererAPI.
	template <typename T>
	T GetRenderAPI();
	template<>
	SDLRenderer* GetRenderAPI<SDLRenderer*>()
	{
		SDLRenderer* temp = nullptr;
		try
		{
			temp = std::get<SDLRenderer*>(R_Variant);
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
			temp = std::get<OpenGLRenderer*>(R_Variant);
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
			temp = std::get<VulkanRenderer*>(R_Variant);
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
	static RendererManager* instance;
	SDL_Window* window;
	SDLRenderer* SDL_R;
	OpenGLRenderer* OPGL_R;
	VulkanRenderer* V_R;
	std::variant<SDLRenderer*, OpenGLRenderer*, VulkanRenderer*> R_Variant;
	RenderAPI API;
	static int R_Value;
	int frames;
};

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

//8/16/2022	This interface needs to be reworked.
class OpenGLRenderer 
{
public:
	OpenGLRenderer();
	~OpenGLRenderer();
	void OnCreate();
	void OnDestroy();
	void SetWindow(SDL_Window* window_);
	void SetWindowSize(int width_, int height_);
	void SetViewPort(int width_, int height_);
	void RefreshWindow();
	void Update();
	glm::mat4 getProjection();
	Square2D CreateSquare(Square2D square2D_);
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
// Vulkan interface implementation
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