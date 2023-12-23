#include "C_2DTransform.h"
#include "../DogEngine/DogEngine.h"

C_Transform2D::C_Transform2D()
{
  
}

C_Transform2D::~C_Transform2D()
{

}

void C_Transform2D::OnCreate(BaseObj* owner_)
{
	Parent = owner_;
}

void C_Transform2D::OnDestroy()
{
}

void C_Transform2D::Update(float deltaTime_)
{
}

void C_Transform2D::Render()
{
}

void C_Transform2D::SetMatrix(Mat3 matrix_)
{
	matrix2D = matrix_;
}

Mat3 C_Transform2D::GetMatrix()
{
	return matrix2D;
}
