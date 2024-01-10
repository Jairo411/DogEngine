#ifndef COMPONENT_H
#define COMPONENT_H
#include <vector>
#include <utility>
#include <tuple>
/*2021-07-17 
 Basic Component system class*/
class BaseObj; 
class Component
{
public:
	inline Component() { Parent = nullptr; }	
	inline virtual ~Component() { Parent = nullptr; }
	virtual void OnCreate(BaseObj* owner_) = 0;
	virtual void OnDestroy() = 0;
	virtual void Update(float deltatime_) =0; // I want this to always be defined in there child classes.
	virtual void Render() =0;
protected:
		BaseObj* Parent; 
};
#endif // COMPONENT_H