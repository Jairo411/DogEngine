#include "Renderer.h"

Renderer* Renderer::instance = nullptr;
RenderProp* Renderer::properties = nullptr;

void Renderer::setRenderProp(RenderProp RenderProperties_)
{
	properties = &RenderProperties_;
	currentRenderer = RenderProperties_.renderer;
}


SDL_Renderer* Renderer::getRenderer()
{
	return currentRenderer;
}

Renderer* Renderer::getInstance()
{
	if (instance==nullptr)
	{
		instance = new Renderer();
	}
	return instance;
}

Renderer::~Renderer()
{

}

Renderer::Renderer()
{
}
