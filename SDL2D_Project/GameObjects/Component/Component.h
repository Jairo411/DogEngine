#ifndef COMPONENT_HPP
#define COMPONENT_HPP
/*2021-07-17 
 Basic Component system class*/
class BaseObj; // forward declaration 

class Component
{
public:
	Component(BaseObj* owner) : owner(owner) {};
	virtual void Start() {};
	virtual void Update(float deltatime) =0; // I want this to always be defined in there child classes.
	virtual void Render() {};
protected:
		BaseObj* owner; 
};
#endif // COMPONENT_HPP