#include "Renderer.h"
#include "../Window/Window.h"

RendererManager* RendererManager::instance = nullptr;
int RendererManager::RenderValue = NULL;

RendererManager::RendererManager()
{
	renderVariant = std::variant<SDL_Renderer*, OpenGLRenderer*, VulkanRenderer*>();
	SDLRenderer = nullptr;
	openGLRenderer = nullptr;
	vulkanRenderer = nullptr;
	window = nullptr;
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
		SDLRenderer = SDL_CreateRenderer(window, -1, 0);
		renderVariant = SDLRenderer;
		if (SDLRenderer != nullptr)
		{
			SDL_SetRenderDrawColor(SDLRenderer, 225, 225, 225, 225);
		}
		else
		{
			std::cout << "Renderer Failed" << std::endl;
		}
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

std::variant<SDL_Renderer*, OpenGLRenderer*, VulkanRenderer*> RendererManager::getRenderer()
{
	try
	{
		switch (RenderValue)
		{
		default:
			break;
		case 0:
			return std::get<SDL_Renderer*>(renderVariant);
			break;
		case 1:
			return std::get<OpenGLRenderer*>(renderVariant);
			break;
		case 2:
			return std::get<VulkanRenderer*>(renderVariant);
			break;
		}
	}
	catch (const std::bad_variant_access& e)
	{
		std::cout << e.what() << std::endl;
	}
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
