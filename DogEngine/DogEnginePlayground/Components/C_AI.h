#ifndef AI_H
#define AI_H
#include "Component.h"
#include "../GameObjects/Object.h"
/*Current Idea 8-01-2023
* Something that I am currently noticing is that 
* I think the only real type of programmign is low level programming and that simply isn't true. 
* in this current AI example what I am going to do is create, some sort of medium to high level type of programming 
* where I am not going to incorperate a scripting language because, well I have to learn that information first and I already feel
* like that is going to take a decent portion of my time already. 
* 
* So if I implement this in my game engine I am only really going to incorperate AI logic, not the gaming industry standard of 
* game AI. 
* 
* I'll be using this resource to implement AI into my game engine: programming game AI by Example. 
*/
class AI : public Component
{
	AI();
	virtual ~AI();
	virtual void OnCreate(BaseObj* owner_);
	virtual void OnDestroy();
	virtual void Update(float deltatime_);
	virtual void Render()=0;
	/*To-Do 08-01-2023
	* Add functions to add and remove AI logic.
	* Add functions to run AI logic.
	*/
private:
	/* To-Do 08-01-2023
	* Implement variable to contain some sort semi-hardcoded logic for this AI_Component.
	* Could be a container or could simply be a pointer.
	*/
};
#endif // !AI_H
