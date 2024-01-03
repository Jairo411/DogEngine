#include "OpenGLTestGameObj.h"

OpenGLTestGameObj::OpenGLTestGameObj()
{
	square = Square2D();
	square.SetImage("C:/Users/jalbm/Pictures/Saved Pictures/homenumerodos.png");	
	square =DGEngine::core::DogEngine::rendererManager->GetInstance()->GetRenderAPI<OpenGLRenderer*>()->CreateSquare(square);
}

OpenGLTestGameObj::~OpenGLTestGameObj()
{
}

void OpenGLTestGameObj::Render()
{

//	glDisable(GL_DEPTH_TEST); // right now this is the only thing allowing you to see what is actually going on 
//	glDepthMask(0);
	glBindVertexArray(square.VAO);
	square.shader->Use();
	glBindTexture(GL_TEXTURE_2D, square.texturePtr);

	square.shader->SetMatrix("projection", square.projection);

	square.transform = glm::mat4(1.0f);


	square.transform = glm::translate(square.transform, glm::vec3(-400.0f, 0.0f, 0.0f));
	square.transform = glm::scale(square.transform, glm::vec3(100.0f, 100.0f, 0.0f));
	//	transform = glm::rotate(transform, 30.0f, glm::vec3(1.0f, 0.0f, 0.0f));

	square.shader->SetMatrix("transform", square.transform);

	glDrawArrays(GL_TRIANGLES, 0, 6);

//	glEnable(GL_DEPTH_TEST);
	glBindVertexArray(0);
	glUseProgram(0);

}

void OpenGLTestGameObj::Update()
{
}

OpenGLTestGameObj1::OpenGLTestGameObj1()
{

}

OpenGLTestGameObj1::~OpenGLTestGameObj1()
{
}

void OpenGLTestGameObj1::Update()
{
}

void OpenGLTestGameObj1::Render()
{
}



