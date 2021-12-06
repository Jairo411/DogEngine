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
	void Update(float deltaTime_);

	std::string imgSrc; 
	Square2D square;
};

class OpenGLTestGameObj1
{
public:
	OpenGLTestGameObj1();
	~OpenGLTestGameObj1();
	void Render();
	void Update();
private:
	Particle CurrentParticle;
	unsigned int nr_particles = 1000;
	int lastUsedparticle = 0;
	int index=0;
	int flag = 0;
};

#endif