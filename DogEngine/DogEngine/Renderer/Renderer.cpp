#include "Renderer.h"
#include "../DogEngine.h"
#include "../Window/Window.h"
#include "../../DogEnginePlayground/GameObjects/GameObject.h"




RendererManager* RendererManager::instance = nullptr;
int RendererManager::R_Value = NULL;


RendererManager::RendererManager() : R_Variant(std::variant<SDLRenderer*, OpenGLRenderer*, VulkanRenderer*>()), SDL_R(nullptr), OPGL_R(nullptr),V_R(nullptr), frames(0)
{
}

RendererManager::~RendererManager()
{

}

void RendererManager::SetRenderer(int numbercase_)
{
	switch (numbercase_)
	{
	default:
		break;
	case 0:
	{
		R_Value = 0;
		SDL_R = new SDLRenderer();
		SDL_R->OnCreate(window);
		R_Variant = SDL_R;
		break;
	}
	case 1:
	{
		R_Value = 1;
		int w =0;
		int h =0;
		OPGL_R = new OpenGLRenderer();
		OPGL_R->SetWindow(window);
		SDL_GetWindowSize(window, &w, &h);
		OPGL_R->SetWindowSize(w, h);
		R_Variant = OPGL_R;
		OPGL_R->OnCreate();
		break;
	}
	case 2:
	{
		R_Value = 2;
		V_R = new VulkanRenderer();
		R_Variant = V_R;
		V_R->OnCreate();
		break;
	}
	}
}

///The NewImplementation 
//void RendererManager::SetRenderer(RenderAPI api_)
//{
//	switch (api_)
//	{
//	case RenderAPI::SDLAPI:
//		R_Value = static_cast<std::underlying_type<RenderAPI>::type>(api_);
//		SDL_R = new SDLRenderer();
//		SDL_R->OnCreate(window);
//		R_Variant = SDL_R;
//		break;
//	case RenderAPI::OPENGLAPI:
//		R_Value = static_cast<std::underlying_type<RenderAPI>::type>(api_);
//		int w = 0;
//		int h = 0;
//		OPGL_R = new OpenGLRenderer();
//		OPGL_R->SetWindow(window);
//		SDL_GetWindowSize(window, &w, &h);
//		OPGL_R->SetWindowSize(w, h);
//		R_Variant = OPGL_R;
//		OPGL_R->OnCreate();
//		break;
//	case RenderAPI::VULKANAPI:
//		R_Value = static_cast<std::underlying_type<RenderAPI>::type>(api_);
//		R_Value = 2;
//		V_R = new VulkanRenderer();
//		R_Variant = V_R;
//		V_R->OnCreate();
//		break;
//	default:
//		break;
//	}
//}

void RendererManager::SetWindow(Window* window_)
{
	window = window_->getWindowContext();
}

RendererManager* RendererManager::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new RendererManager();
	}
	return instance;
}

int RendererManager::getRenderValue()
{
	return R_Value;
}











