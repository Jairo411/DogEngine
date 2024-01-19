#include "OpenGLRenderer.h"

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
	projection = glm::ortho((float)-ScreenWidth, (float)ScreenWidth, (float)-ScreenHeight, (float)ScreenHeight, 0.0f, 1000.0f);
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

//Square2D OpenGLRenderer::CreateSquare(Square2D square_)
//{
//	//Create the square then set the projection of the square to the engine camera
//
//	square_.SetProjection(projection);
//
//	square_.OnCreate();
//
//	return square_;
//
//}

//Particle OpenGLRenderer::CreateParticle(Particle particle_)
//{
//	particle_.SetProjection(projection);
//	particle_.OnCreate();
//
//	return particle_;
//}


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

//void Square2D::SetImage(const char* imageSrc_)
//{
//	texture = DogEngine::textureManager->GetInstance()->LoadSurface(imageSrc_);
//}

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

//void Particle::SetImage(const char* imageSrc_)
//{
//	texture = DogEngine::textureManager->GetInstance()->LoadSurface(imageSrc_);
//}

void Particle::SetProjection(glm::mat4 projection_)
{
	projection = projection_;
}
