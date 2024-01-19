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
#include "../../DogEngine/DogEngineDefinitions.h"
#include "Shader.h"
#include "SDLRenderer.h"
#include "OpenGLRenderer.h"
#include "VulkanRenderer.h"

/*
* 8/16/2022
* Singleton renderermanger system. 
* Allows me to switch in between different renderers, SDL's 2D basic renderer, opengl and vulkan.
*/

class Window;
class DogEngine;
typedef std::variant<SDLRenderer*, OpenGLRenderer*, VulkanRenderer*> renderers;

	class RendererManager
	{
	public:
		RendererManager(const RendererManager&) = delete;
		RendererManager(RendererManager& other) = delete;
		RendererManager operator =(const RendererManager&) = delete;
		RendererManager operator =(RendererManager&&) = delete;
		static RendererManager* GetInstance();
		///Set RenderAPI.
		void SetRenderer(int numbercase_);
		//New SetRenderer subroutine 
		///Pass current window context.
		void SetWindow(Window* window_);
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
		SDL_Window* window =nullptr;
		SDLRenderer* SDL_R = nullptr;
		OpenGLRenderer* OPGL_R = nullptr;
		VulkanRenderer* V_R = nullptr;
		renderers R_Variant;
		RenderAPI API;
		static int R_Value;
		int frames;
	};






#endif //RENDERER_H