#ifndef OPENGLRENDERER_H
#define OPENGLRENDERER_H

#include <glew.h>
#include <SDL.h>
#include <glm/glm.hpp>
#include "Shader.h"


/* 11-01-2024
* Abstraction of OpenGL render function calls
*/
class OpenGLRenderer
{
public:
	OpenGLRenderer();
	~OpenGLRenderer();
	void OnCreate();
	void OnDestroy();
	void SetWindow(SDL_Window* window_);
	void SetWindowSize(int width_, int height_);
	void SetViewPort(int width_, int height_);
	void RefreshWindow();
	void Update();
	glm::mat4 getProjection();
	//Square2D CreateSquare(Square2D square2D_);
	//Particle CreateParticle(Particle particles_);


private:
	void PrintOpenGL(int* major_, int* minor_);
	void SetAttributes(int major_, int minor_);
	void SetContext();
	glm::mat4 projection;
	SDL_Window* window;
	SDL_GLContext* context;
	GLenum error;
	int ScreenHeight;
	int ScreenWidth;
};



struct Square2D
{
	Square2D();
	void OnCreate();
//	void SetImage(const char* imageSrc_);
	void SetProjection(glm::mat4 projection_);
	glm::mat4 transform;
	glm::mat4 projection;
	unsigned VBO;
	unsigned VAO;
	unsigned int projectionLoc;
	unsigned int transformLoc;
	unsigned texturePtr;
	SDL_Surface* texture;
	ShaderScript* shader;
};

struct Particle
{
	Particle();
	void OnCreate();
//	void SetImage(const char* imageSrc_);
	void SetProjection(glm::mat4 projection_);

	unsigned int VBO;
	unsigned int VAO;
	unsigned int texturePtr;
	unsigned int projectionLoc;
	unsigned int transformLoc;
	unsigned int nr_particles;
	unsigned int lastUsedParticle;
	SDL_Surface* texture;
	ShaderScript* shader;
	glm::mat4 projection;
	glm::mat4 transform;
	glm::vec3 Position;
	glm::vec2 Velocity;
	glm::vec4 colour;
	float life;

};





#endif // !OPENGLRENDERER_H