#ifndef COMPONENT_H
#define COMPONENT_H
/*2021-07-17 
 Basic Component system class*/
class BaseObj; // forward declaration 

class Component
{
public:
	inline Component() { Parent = nullptr; }
	virtual ~Component() { Parent = nullptr; }
	virtual void OnCreate(BaseObj* owner) = 0;
	virtual void OnDestroy() = 0;
	virtual void Update(float deltatime) =0; // I want this to always be defined in there child classes.
	virtual void FixedUpdate(float DeltaTime_) =0;
	virtual void Render() =0;
protected:
		BaseObj* Parent; 
};
#endif // COMPONENT_H