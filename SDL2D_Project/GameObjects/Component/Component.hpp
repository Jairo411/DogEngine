#ifndef COMPONENT_HPP
#define COMPONENT_HPP

class Object; // forward declaration 

class Component
{
public:
	Component(Object* owner) : owner(owner) {};
	virtual void Start() {};
	virtual void Update(float deltatime) {};
	virtual void Render() {};
protected:
		Object* owner; 
};
#endif // COMPONENT_HPP