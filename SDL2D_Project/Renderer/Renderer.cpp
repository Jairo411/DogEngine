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
	renderer_ = OpenGLRenderer();
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
