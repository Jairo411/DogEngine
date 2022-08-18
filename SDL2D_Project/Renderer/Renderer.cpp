#include "Renderer.h"
#include "../Window/Window.h"
#include "../DogEngine/DogEngine.h"

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

void RendererManager::setWindow(Window* window_)
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

OpenGLRenderer::OpenGLRenderer()
{

}

OpenGLRenderer::~OpenGLRenderer()
{
	OnDestroy();
}




void OpenGLRenderer::OnCreate()
{
	SetContext();
	int major, minor;

	PrintOpenGL(&major, &minor);
	SetAttributes(major, minor);

	GLenum err = glewInit();
	if (err != GLEW_OK)
	{
		std::cout << "GLEW FAILED" << std::endl;
	}

	glEnable(GL_DEPTH_TEST); // this way not work the way you think it does

	glViewport(0, 0, ScreenWidth, ScreenHeight);
	projection = glm::ortho((float)-ScreenWidth,(float)ScreenWidth,(float)-ScreenHeight,(float)ScreenHeight,0.0f,1000.0f);
	std::cout << "Just Intialized GLEW/OPENGL" << std::endl;

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

}

void OpenGLRenderer::OnDestroy()
{
	SDL_GL_DeleteContext(context);
	context = nullptr;
	delete context;
}

void OpenGLRenderer::SetWindow(SDL_Window* window_)
{
	window = window_;
}

void OpenGLRenderer::SetContext()
{
	context = new SDL_GLContext();
	*context = SDL_GL_CreateContext(window);
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

void OpenGLRenderer::RefreshWindow()
{
	SDL_GL_SwapWindow(window);
}

void OpenGLRenderer::Update()
{
}

glm::mat4 OpenGLRenderer::getProjection()
{
	return projection;
}

Square2D OpenGLRenderer::CreateSquare(Square2D square_)
{
	//Create the square then set the projection of the square to the engine camera
	
	square_.SetProjection(projection);
	
	square_.OnCreate();
	
	return square_;
	
}

Particle OpenGLRenderer::CreateParticle( Particle particle_)
{
		particle_.SetProjection(projection);
		particle_.OnCreate();

		return particle_;
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

SDLRenderer::SDLRenderer()
{
	rend = nullptr;
	window = nullptr;
}
SDLRenderer::~SDLRenderer()
{
	OnDestroy();
}

void SDLRenderer::OnCreate(SDL_Window* window_)
{
	rend = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED && SDL_RENDERER_TARGETTEXTURE && SDL_RENDERER_PRESENTVSYNC);
	window = window_;

	if (rend == nullptr)
	{
		std::cout << "SDL renderer could not be created" << std::endl;
	}
	else
	{
		std::cout << "SDL Renderer has been Intialized" << std::endl;
	}

	SDL_SetRenderDrawColor(rend, 225, 225, 225, 225);
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

void SDLRenderer::DrawTexture(SDL_Texture* tex_, SDL_Rect* srcRect_, SDL_Rect* dstRect_)
{
	SDL_RenderCopy(rend, tex_, srcRect_, dstRect_);
}

void SDLRenderer::DrawTexture(SDL_Texture* tex_, SDL_Rect* srcRect_, SDL_Rect* dstRect_, double angle_, SDL_Point* center_, SDL_RendererFlip flipFlag_)
{
	SDL_RenderCopyEx(rend, tex_, srcRect_, dstRect_, angle_, center_, flipFlag_);
}

void SDLRenderer::DrawCircle(int centreX_, int centreY_, int radius_)
{

	SDL_SetRenderDrawColor(rend, 89, 225, 0, 1);
	
	float fcentreX = (float)centreX_;
	float fcentreY = (float)centreY_;
	float fradius = (float)radius_;
	SDL_FPoint points[24000];
	float xPoint = 0;
	float yPoint = 0;
	int index = 0;
	for (float i = 0.000f; i < 360.000f;)
	{
		//get a point on the circle using cartesan coordinates with the origin of this circle being (0,0)
		xPoint = fradius * cosf(i);
		yPoint = fradius * sinf(i);
		
		points[index].x = xPoint;
		points[index].y = yPoint;

		//Move the origin of the circle to where my object actually is 
		//SDL_RenderDrawPoint(rend, xPoint, yPoint);
		i += 0.015;
		index++;
	}

	for (int i = 0; i < 24000; i++)
	{
		points[i].x +=  fcentreX;
		points[i].y += fcentreY;
	}
	
	SDL_RenderDrawPointsF(rend, &points[0], 24000);

	SDL_SetRenderDrawColor(rend, 225, 225, 225, 225);
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
	SDL_SetRenderDrawColor(rend,89,225,0,1);
	SDL_RenderDrawRect(rend, rect_);
	SDL_SetRenderDrawColor(rend, 225, 225, 225, 225);
	//SDL_RenderClear(rend);
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

Square2D::Square2D()
{
}

void Square2D::OnCreate()
{
//	projection = glm::mat4(1.0f);
	shader = new ShaderScript("C:/Users/jalbm/source/repos/SDL2D_Project/SDL2D_Project/Renderer/ShadersScripts/SquareV.glsl", "C:/Users/jalbm/source/repos/SDL2D_Project/SDL2D_Project/Renderer/ShadersScripts/SquareF.glsl");
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
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);

	glGenTextures(1, &texturePtr);
	glBindTexture(GL_TEXTURE_2D, texturePtr);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture->w, texture->h, 0, GL_RGB, GL_UNSIGNED_BYTE, texture->pixels);
	glGenerateMipmap(GL_TEXTURE_2D);

	SDL_FreeSurface(texture);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Square2D::SetImage(const char* imageSrc_)
{
	texture = DogEngine::textureManager->GetInstance()->LoadSurface(imageSrc_);
}

void Square2D::SetProjection(glm::mat4 projection_)
{
	projection = projection_;
}

Particle::Particle() : Position(0.0f), Velocity(0.0f), colour(1.0f), life(0.0f)
{	
}

void Particle::OnCreate()
{
	shader = new ShaderScript("Renderer/ShadersScripts/ParticleV.glsl", "Renderer/ShadersScripts/ParticleF.glsl");
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
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);

	glGenTextures(1, &texturePtr);
	glBindTexture(GL_TEXTURE_2D, texturePtr);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture->w, texture->h, 0, GL_RGB, GL_UNSIGNED_BYTE, texture->pixels);
	glGenerateMipmap(GL_TEXTURE_2D);

	SDL_FreeSurface(texture);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

}

void Particle::SetImage(const char* imageSrc_)
{
	texture = DogEngine::textureManager->GetInstance()->LoadSurface(imageSrc_);
}

void Particle::SetProjection(glm::mat4 projection_)
{
	projection = projection_;
}
