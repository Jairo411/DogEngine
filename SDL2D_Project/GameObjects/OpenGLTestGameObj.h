#ifndef OPENGLTEST_HEADER
#define OPENGLTEST_HEADER
#include "../Game/Game.h"
#include "../Renderer/Renderer.h"
#include <vector>
#include <string>
class OpenGLTestGameObj
{
public:
	OpenGLTestGameObj();
	~OpenGLTestGameObj();
	void Render();
	void Update();

	std::string imgSrc; 
	Square2D square;
};

class OpenGLTestGameObj1
{
public:
	OpenGLTestGameObj1();
	~OpenGLTestGameObj1();
	void RespawnParticle(Particle& particle, glm::vec2 offset);
	void Render();
	void Update(float deltaTime, glm::vec2 offset = glm::vec2(0.0f,0.0f));
private:
	Particle CurrentParticle;
	unsigned int nr_particles = 500;
	unsigned int lastUsedparticle = 0;
	int index=0;
	int flag = 0;
	std::vector<Particle> particles;
};

#endif