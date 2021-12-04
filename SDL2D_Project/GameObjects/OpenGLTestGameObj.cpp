#include "OpenGLTestGameObj.h"

OpenGLTestGameObj::OpenGLTestGameObj()
{
	square = Square2D();
	square.SetImage("C:/Users/jalbm/Pictures/Saved Pictures/homenumerodos.png");	
	square =Game::rendererManager->GetInstance()->GetRenderAPI<OpenGLRenderer*>()->CreateSquare(square);
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

	for (unsigned int i = 0; i < nr_particles; i++)
	{
		CurrentParticle = Particle();
		CurrentParticle.SetImage("C:/Users/jalbm/Pictures/Explosions/Red/explosion_red_53.png");
		CurrentParticle = Game::rendererManager->GetInstance()->GetRenderAPI<OpenGLRenderer*>()->CreateParticle(CurrentParticle);

		CurrentParticle.transform = glm::mat4(1.0f);
		CurrentParticle.transform = glm::translate(CurrentParticle.transform, glm::vec3(300.0f, 0.0f, 0.0f));
		CurrentParticle.transform = glm::scale(CurrentParticle.transform, glm::vec3(50.0f, 50.0f, 0.0f));

		particles.push_back(CurrentParticle);

	}

}

OpenGLTestGameObj1::~OpenGLTestGameObj1()
{
}


void OpenGLTestGameObj1::RespawnParticle(Particle& particle, glm::vec2 offest)
{
	float random = ((rand() % 100) - 50) / 10.0f;
	float rColour = 0.5f + ((rand() % 100) / 100.0f);
	particle.Position = glm::vec3(0.0f + random + offest.x, 0.0f + random + offest.y,0.0f);
	particle.colour = glm::vec4(rColour, rColour, rColour, 1.0f);
	particle.life = 1.5f;
	particle.Velocity = glm::vec2(0.4f, 0.4f);
}

void OpenGLTestGameObj1::Render()
{
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);

	for (Particle particle : particles)
	{
		CurrentParticle = particle;
		if (CurrentParticle.life > 0.0f)
		{

			glBindVertexArray(CurrentParticle.VAO);

			CurrentParticle.shader->Use();
			glBindTexture(GL_TEXTURE_2D, CurrentParticle.texturePtr);

			CurrentParticle.shader->SetMatrix("projection", CurrentParticle.projection);
			CurrentParticle.shader->SetVector4f("colour", CurrentParticle.colour);


			CurrentParticle.shader->SetMatrix("transform", CurrentParticle.transform);

			glDrawArrays(GL_TRIANGLES, 0, 6);

			glBlendFunc(GL_SRC_ALPHA, GL_ONE);

			glBindVertexArray(0);
		}
	}
	
	
		glUseProgram(0);
}

void OpenGLTestGameObj1::Update(float deltaTime,glm::vec2 offset)
{

	


	/*	if (CurrentParticle.life<=0.0f)
		{
			RespawnParticle(CurrentParticle, offset);
		}
		
		

		glm::vec2 changeinVelo = glm::vec2(CurrentParticle.Velocity.x + 0.016, CurrentParticle.Velocity.y + 0.016);

		CurrentParticle.Position.x -= changeinVelo.x;
		CurrentParticle.Position.y -= changeinVelo.y;

		CurrentParticle.colour.a -= 0.00005f;
		CurrentParticle.life -= 0.00005f;

		CurrentParticle.transform = glm::translate(CurrentParticle.transform, glm::vec3(CurrentParticle.Position.x, CurrentParticle.Position.y, 0.0f));*/

	
	/*for (Particle particle : particles)
	{
		if (particle.life<=0.0f)
		{
			RespawnParticle(particle, offset);
		}
		particle.life -= deltaTime;
	}*/
}
