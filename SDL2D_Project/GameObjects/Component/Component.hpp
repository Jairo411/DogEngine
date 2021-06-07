#ifndef COMPONENT_HPP
#define COMPONENT_HPP

class BaseObj; // forward declaration 

class Component
{
public:
	Component(BaseObj* owner) : owner(owner) {};
	virtual void Start() {};
	virtual void Update(float deltatime) {};
	virtual void Render() {};
protected:
		BaseObj* owner; 
};
#endif // COMPONENT_HPP