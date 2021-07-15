#include "Renderer.h"

Renderer* Renderer::instance = nullptr;
RenderProp* Renderer::properties = nullptr;

void Renderer::setRenderProp(RenderProp RenderProperties_)
{
	properties = &RenderProperties_;
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
