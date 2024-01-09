#ifndef ANIMATOR2D_H
#define ANIMATOR2D_H
#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <SDL.h>
#include <map>
#include <string>
#include "Component.h"

class Animator2D : Component
{
public:
	Animator2D();
	virtual ~Animator2D();

	virtual void OnCreate(BaseObj* owner_);
	virtual void OnDestroy();
	virtual void Update(float deltatime_);
	virtual void Render();
};





/*
	THIS SHIT IS OUTDATED SUN
*/

///*Animator class Suppose to be an interface inhereted by GameObjects with animations.
//	right now functionality is basically non-existance. Because you're to lazy to fix these issues now they are.
//	 - You're hard coding the frame speed of the animations
//	 the Fix:
//	 just carry the amount of frames per , each "set" of animations
//	 Have a play function that doesn't nesserally handle the playing of the animations right away, but handle the animationSet vector
//	 */
//struct Sprite
//{
//	std::vector <std::vector<SDL_Texture*>> animationSet;
//	std::map<int, Uint32> spriteContainer;
//	std::map<int, std::string> stringID; // STATE NAME AND SPRITE NAME 
//	Uint32 ticks;
//	Uint32 spriteFrames;
//	Uint32 frameSpeed;
//};
//class Animator
//{
//public:
//	/* Most of these public functions won't be used right now but allow the Engine to have future Functionality over the animations*/
//	virtual ~Animator();
////	virtual void PlayAnimations(enum class temp temp_) = 0;
//	/*virtual void PlayAnimations()  so basically there is probably a better way of doing this I shouldn't have to put in the 
//	frameSpeed in the animationsSet vector, to run. That should already be set.*/
//	virtual void ChangeStateName(std::string temp_, int ID_)final;//  able to change state Name; 
//	virtual void ChangeFrameSpeed(Uint32 frameTicks_)final; // change the sprite frameSpeed variable
//	virtual bool IntiAnimations(const char* AnimSetName_, const char* relativeDir_, const char firstChar_) final;
//protected:
//	Sprite sprite; //Sprite struct that holds all the information of the sprite. 
//	template <typename E>
//	constexpr auto toUnderlyingType(E e)
//	{
//		return static_cast<typename std::underlying_type<E>::type>(e); 
//	} // takes the enum classes I have and converts the state to an integer
//private:
//	void IntiSprite(); //Default way of setting the sprite animation length 
//	void CreateStates(); //creates a temp variable for my animations states
//
//};
#endif //Animator_H
