#ifndef C_TRANSFORM_H
#define C_TRANSFORM_H
#include <glm/glm.hpp>
#include "Component.h"
#include "../DogEngine/DogEngineDefinitions.h"
class DogEngine;
class Transform2D : public Component
{
public:
	Transform2D();
	~Transform2D();
	virtual void OnCreate(BaseObj* owner_) final;
	virtual void OnDestroy() final;
	virtual void Update(float deltaTime_) final;
	virtual void Render();
	void SetMatrix(Mat3 matrix_);
	Mat3 GetMatrix();
	//Future matrix functions 
	//Translate()
	//Scale()
	//Rotate about origin(). 
	//Relfect().
private:
	Mat3 matrix2D;
};
#endif // !C_TRANSFORM_H