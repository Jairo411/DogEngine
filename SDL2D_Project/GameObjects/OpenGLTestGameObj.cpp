#include "OpenGLTestGameObj.h"

OpenGLTestGameObj::OpenGLTestGameObj()
{
	square = Square2D();
	square.SetImage("C:/Users/jalbm/Pictures/Saved Pictures/homenumerodos.png");	
	square =Game::rendererManager->GetInstance()->GetRenderAPI<OpenGLRenderer*>()->CreateSquare(square);
	square.transform = glm::mat4(1.0f);
	square.transform = glm::translate(square.transform, glm::vec3(-400.0f, 0.0f, 0.0f));
	square.transform = glm::scale(square.transform, glm::vec3(100.0f, 100.0f, 0.0f));
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

	


	square.shader->SetMatrix("transform", square.transform);

	glDrawArrays(GL_TRIANGLES, 0, 6);

//	glEnable(GL_DEPTH_TEST);
	glBindVertexArray(0);
	glUseProgram(0);

}

void OpenGLTestGameObj::Update(float deltaTime_)
{
	glm::mat4 rotate = glm::mat4(1.0f);
	rotate = glm::rotate(rotate, glm::radians(0.5f), glm::vec3(0.0, 0.0f, 1.0f));
	square.transform *= rotate;
}

OpenGLTestGameObj1::OpenGLTestGameObj1()
{
		CurrentParticle = Particle();
		CurrentParticle.SetImage("C:/Users/jalbm/Pictures/Explosions/Red/explosion_red_53.png");
		CurrentParticle = Game::rendererManager->GetInstance()->GetRenderAPI<OpenGLRenderer*>()->CreateParticle(CurrentParticle);

		CurrentParticle.transform = glm::mat4(1.0f);
		CurrentParticle.transform = glm::translate(CurrentParticle.transform, glm::vec3(300.0f, 0.0f, 0.0f));
		CurrentParticle.transform = glm::scale(CurrentParticle.transform, glm::vec3(50.0f, 50.0f, 0.0f));

		CurrentParticle.Velocity = glm::vec2(0.4f, 0.4f);

	

	

}

OpenGLTestGameObj1::~OpenGLTestGameObj1()
{
}



void OpenGLTestGameObj1::Render()
{
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);


	glBindVertexArray(CurrentParticle.VAO);


	

	CurrentParticle.shader->Use();
	glBindTexture(GL_TEXTURE_2D, CurrentParticle.texturePtr);



	CurrentParticle.shader->SetMatrix("projection", CurrentParticle.projection);
	CurrentParticle.shader->SetVector4f("colour", CurrentParticle.colour);
	CurrentParticle.shader->SetMatrix("transform", CurrentParticle.transform);

	glDrawArraysInstanced(GL_TRIANGLE_STRIP, 0, 4, nr_particles);


		
	

	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	glBindVertexArray(0);



	glUseProgram(0);
}

void OpenGLTestGameObj1::Update()
{
	
	


}
