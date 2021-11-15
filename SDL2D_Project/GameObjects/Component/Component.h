#ifndef COMPONENT_HPP
#define COMPONENT_HPP
/*2021-07-17 
 Basic Component system class*/
class BaseObj; // forward declaration 

class Component
{
public:
	Component() { Parent = nullptr; }
	Component(BaseObj* owner) : Parent(owner) {};
	virtual ~Component() = 0;
	virtual void OnCreate(BaseObj* parent_) = 0;
	virtual bool OnDestroy() = 0;
	virtual void Update(float deltatime) =0; // I want this to always be defined in there child classes.
	virtual void FixedUpdate(float DeltaTime_)=0; 
	virtual void Render() const = 0;
protected:
		BaseObj* Parent; 
};
#endif // COMPONENT_HPP