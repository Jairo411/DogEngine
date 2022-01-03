#ifndef C_ANIMATIONHEADER
#define C_ANIMATIONHEADER
#include <vector>
#include <SDL.h>
#include "Component.h"
/*REMEMBER TO KNOW WHAT UNITS YOU ARE WORKING IN
YOU'RE UNITS OF ANIMATION ARE 30 FRAMES EQUALS A SECOND 30FPS 
*/
class C_Animation : public Component
{
public:
	C_Animation();
	virtual ~C_Animation();
	virtual void OnCreate(BaseObj* owner_);
	virtual void OnDestroy();
	virtual void Update(float deltaTime_);
	virtual void FixedUpdate(float deltaTime_){}
	virtual void Render() {}
	void AddImage(SDL_Texture* texture_);
	void RemoveImage(SDL_Texture* texture_);
	void SetAnimationLength(float animationLength_);
private:
	float secondsOfAnimations;
	std::vector<SDL_Texture*> imageHolder;
};

#endif // !C_ANIMATIONHEADER