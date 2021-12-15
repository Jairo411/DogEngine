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
	void Update();
	void Render();
private:
	Particle CurrentParticle;
	int index=0;
	int flag = 0;
	std::vector<Particle> particles;
};

#endif