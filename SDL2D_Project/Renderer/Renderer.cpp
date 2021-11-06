#include "Renderer.h"
#include "../Window/Window.h"

RendererManager* RendererManager::instance = nullptr;
int RendererManager::RenderValue = NULL;

RendererManager::RendererManager()
{
	renderVariant = std::variant<SDLRenderer*, OpenGLRenderer*, VulkanRenderer*>();
	SDL__Renderer = nullptr;
	openGLRenderer = nullptr;
	vulkanRenderer = nullptr;
	window = nullptr;
	frames = 0;
}

RendererManager::~RendererManager()
{

}

void RendererManager::OnCreate()
{

}

void RendererManager::OnDestroy()
{
}

void RendererManager::setRenderer(int numbercase_)
{
	switch (numbercase_)
	{
	default:
		break;
	case 0:
	{
		RenderValue = 0;
		SDL__Renderer = new SDLRenderer(window);
		SDL__Renderer->OnCreate();
		renderVariant = SDL__Renderer;
		break;
	}
	case 1:
	{
		RenderValue = 1;
		openGLRenderer = new OpenGLRenderer();
		renderVariant = openGLRenderer;
		openGLRenderer->OnCreate();
		break;
	}
	case 2:
	{
		RenderValue = 2;
		vulkanRenderer = new VulkanRenderer();
		renderVariant = vulkanRenderer;
		vulkanRenderer->OnCreate();
		break;
	}
	}
}

void RendererManager::setWindow(Window* window_)
{
	window = window_->getWindowContext();
}

RendererManager* RendererManager::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new RendererManager();
		instance->OnCreate();
	}
	return instance;
}

int RendererManager::getRenderValue()
{
	return RenderValue;
}

OpenGLRenderer::OpenGLRenderer()
{

}

OpenGLRenderer::~OpenGLRenderer()
{
	OnDestroy();
}

void OpenGLRenderer::OnCreate()
{
	context = new SDL_GLContext();
	int major, minor;
	PrintOpenGL(&major, &minor);
	SetAttributes(major, minor);

	GLenum err = glewInit();
	if (err != GLEW_OK)
	{
		std::cout << "GLEW FAILED" << std::endl;
	}
	glViewport(0, 0, ScreenWidth, ScreenHeight);
	std::cout << "Just Intialized GLEW/OPENGL" << std::endl;
}

void OpenGLRenderer::OnDestroy()
{
	SDL_GL_DeleteContext(context);
	context = nullptr;
	delete context;
}

void OpenGLRenderer::PrintOpenGL(int* major_, int* minor_)
{
	//manufacture info... 

	const GLubyte* version = glGetString(GL_VERSION);
	const GLubyte* vendor = glGetString(GL_VENDOR);
	const GLubyte* renderer = glGetString(GL_RENDERER);
	const GLubyte* glslVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);

	glGetIntegerv(GL_MAJOR_VERSION, major_);
	glGetIntegerv(GL_MINOR_VERSION, minor_);

	std::cout << "OpenGL Version: " + std::string((char*)version) << std::endl;
	std::cout << "Graphics Card Vendor: " + std::string((char*)vendor) << std::endl;
	std::cout << "Graphics card name: " + std::string((char*)renderer) << std::endl;
	std::cout << "GLSL Verison: " + std::string((char*)glslVersion) << std::endl;


}

void OpenGLRenderer::SetAttributes(int major_, int minor_)
{

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, major_);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_DEBUG_FLAG);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, true);

	SDL_GL_SetSwapInterval(1);
	glewExperimental = GL_TRUE;
}

void OpenGLRenderer::SetViewPort(int width_, int height_)
{
	ScreenWidth = width_;
	ScreenHeight = height_;
}

void OpenGLRenderer::Update(float dt_)
{
}

void OpenGLRenderer::Render()
{
}

VulkanRenderer::VulkanRenderer()
{
}

VulkanRenderer::~VulkanRenderer()
{
}

void VulkanRenderer::OnCreate()
{
}

void VulkanRenderer::OnDestroy()
{
	

}

SDLRenderer::SDLRenderer(SDL_Window* window_)
{
	rend = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED && SDL_RENDERER_TARGETTEXTURE);
	window = window_;

	if (rend==nullptr)
	{
		std::cout << "SDL renderer could not be created" << std::endl;
	}
	else
	{
		std::cout << "SDL Renderer has been Intialized" << std::endl;
	}
	
	SDL_SetRenderDrawColor(rend, 225, 225, 225, 225);

}
SDLRenderer::~SDLRenderer()
{
	OnDestroy();
}

void SDLRenderer::OnCreate()
{

}

void SDLRenderer::OnDestroy()
{
	rend = nullptr;
	window = nullptr;
	delete rend;
	delete window;
}

SDL_Texture* SDLRenderer::CreateTextureFromSurface(SDL_Surface* surface_)
{
	SDL_Texture* tex = SDL_CreateTextureFromSurface(rend,surface_);
	return tex;
}

void SDLRenderer::DrawGameObject(GameObject* gameOBJ_)
{
	DrawTexture(gameOBJ_->getTexture(), gameOBJ_->getTextureDisplayInfo().first, gameOBJ_->getTextureDisplayInfo().second);
}

void SDLRenderer::DrawTexture(SDL_Texture* tex_, SDL_Rect* srcRect_, SDL_Rect* dstRect_)
{
	SDL_RenderCopy(rend, tex_, srcRect_, dstRect_);
}

void SDLRenderer::DrawLine(float startX_, float startY_, float endX_, float endY_)
{
	SDL_RenderDrawLine(rend, startX_, startY_, endX_, endY_);
}

void SDLRenderer::DrawPoint(int x_, int y_)
{
	SDL_RenderDrawPoint(rend, x_, y_);
}

void SDLRenderer::DrawRect(SDL_Rect* rect_)
{
	SDL_RenderDrawRect(rend, rect_);
}

void SDLRenderer::DrawRect(int x_, int y_, int width_, int height_)
{
	SDL_Rect* tempRect;

	tempRect = new SDL_Rect();

	tempRect->x = x_;
	tempRect->y = y_;

	tempRect->w = width_;
	tempRect->h = height_;

	SDL_RenderDrawRect(rend, tempRect);
}

void SDLRenderer::SetRenderDrawColour(Uint8 r_, Uint8 g_, Uint8 b_, Uint8 a_)
{
	SDL_SetRenderDrawColor(rend, r_, g_, b_, a_);
}

SDL_Renderer* SDLRenderer::GetRenderer()
{
	return rend;
}

void SDLRenderer::RenderClear()
{
	SDL_RenderClear(rend);
}

void SDLRenderer::RenderPresent()
{
	SDL_RenderPresent(rend);
}


int SDLRenderer::getTotalFrames()
{
	return totalFrames;
}

