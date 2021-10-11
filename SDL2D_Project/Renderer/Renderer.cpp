#include "Renderer.h"

RendererManager* RendererManager::instance = nullptr;


void RendererManager::setRenderer(SDL_Renderer* renderer_)
{

	renderer_ = SDL_CreateRenderer(window,-1,0);
	if (renderer_!=nullptr)
	{
		SDL_SetRenderDrawColor(renderer_, 225, 225, 225, 225);
		std::cout << "SDLRenderer Created" << std::endl;
	}
	else
	{
		std::cout << "Renderer Failed" << std::endl;
	}
}

void RendererManager::setRenderer(VulkanRenderer renderer_)
{
	renderer_.OnCreate();
}

void RendererManager::setRenderer(OpenGLRenderer renderer_)
{
	renderer_.OnCreate();
}


SDL_Renderer* RendererManager::getRenderer()
{
	return currentRenderer;
}

RendererManager* RendererManager::getInstance()
{
	if (instance==nullptr)
	{
		instance = new RendererManager();
	}
	return instance;
}

RendererManager::~RendererManager()
{

}

RendererManager::RendererManager()
{
}

