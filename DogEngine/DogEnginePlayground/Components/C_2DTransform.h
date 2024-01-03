#ifndef C_TRANSFORM_H
#define C_TRANSFORM_H
#include "Component.h"
#include "../../DogEngine/DogEngineDefinitions.h"
class DogEngine;
class C_Transform2D : public Component
{
public:
	C_Transform2D();
	~C_Transform2D();
	virtual void OnCreate(BaseObj* owner_) final;
	virtual void OnDestroy() final;
	virtual void Update(float deltaTime_) final;
	virtual void Render() final;
	void SetMatrix(DGEngine::core::Mat3 matrix_);
	DGEngine::core::Mat3 GetMatrix();
	//Future matrix functions 
	//Translate()
	//Scale()
	//Rotate about origin(). 
	//Relfect().
private:
	DGEngine::core::Mat3 matrix2D;
};
#endif // !C_TRANSFORM_H