#include "C_2DTransform.h"
#include "../DogEngine/DogEngine.h"

Transform2D::Transform2D() : matrix2D(Mat3())
{
}

Transform2D::~Transform2D()
{
}

void Transform2D::OnCreate(BaseObj* owner_)
{
	Parent = owner_;
}

void Transform2D::OnDestroy()
{
}

void Transform2D::Update(float deltaTime_)
{
}

void Transform2D::Render()
{
}

void Transform2D::SetMatrix(Mat3 matrix_)
{
	matrix2D = matrix_;
}

Mat3 Transform2D::GetMatrix()
{
	return matrix2D;
}
