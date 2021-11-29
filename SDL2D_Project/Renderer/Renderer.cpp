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
		int* w, * h;
		openGLRenderer = new OpenGLRenderer();
		openGLRenderer->SetContext(window);
		SDL_GetWindowSize(window, w, h);
		openGLRenderer->SetWindowSize(*w, *h);
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

void OpenGLRenderer::SetContext(SDL_Window* window_)
{
	context = new SDL_GLContext();
	*context = SDL_GL_CreateContext(window_);
}

void OpenGLRenderer::SetWindowSize(int width_, int height_)
{
	ScreenWidth = width_;
	ScreenHeight = height_;
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

SquareStruct::SquareStruct(const char* imageSrc_)
{
	shader = new ShaderScript("Renderer/ShadersScripts/SquareV.glsl", "Renderer/ShadersScripts/SquareF.glsl");
	texture = Game::textureManager->GetInstance()->LoadSurface(imageSrc_);

	float vertices[] =
	{
		//pos	//tex
		0.0f,1.0f,0.0f,1.0f,
		1.0f,0.0f,1.0f,0.0f,
		0.0f,0.0f,0.0f,0.0f,

		0.0f,1.0f,0.0f,1.0f,
		1.0f,1.0f,1.0f,1.0f,
		1.0f,0.0f,1.0f,0.0f
	};

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindVertexArray(VAO);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float),0);

	glGenTextures(1, &texturePtr);
	glBindTexture(GL_TEXTURE_2D, texturePtr);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture->w, texture->h, 0, GL_RGB, GL_UNSIGNED_BYTE, texture->pixels);
	glGenerateMipmap(GL_TEXTURE_2D);

	SDL_FreeSurface(texture);


}

void SquareStruct::Render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBindVertexArray(VAO);
	glUseProgram(shader->getProgram());
	glBindTexture(GL_TEXTURE_2D,texturePtr);

}
