#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "Object.h"
#include <string>
#include "SDL.h"
#include <map>
#include <list>
#include<vector>
#include<iostream>
#include<fstream>
#include<type_traits>
#include"../Math/Vec2.h"
#include"../DataStructures/Observer.h"
#include"Component/Component.hpp"
using namespace std;

/*Standard GameObject class should be abstract and should be the base class.
of any game object in the game i.e
-Enemies
-Enviromental stuff
-Player and Player weapons
Basically anything with a texture.
*/
/*You are currently implementing this as a player object and enemy object class.
might want to strip this class of alot of it's functionality leave basic functionality.
and expand the functionailty to child classes.
potentailly going to have gameObjects with no movement or extra functionality being used and having a bunch of null variables */
/*2021-07-09
	I agree with past me, and looking forward to moving to a component base structure.*/
class TextureManager;
class IObserver;
class GameObject : public BaseObj , public IObserverable
{
public:
	GameObject();
	virtual ~GameObject();
	virtual void Start();
	virtual void Update(float deltaTime_);
	virtual void Render();
	virtual void Disable() = 0;
	virtual SDL_Texture* getTexture() final;
	virtual bool setDisable(bool temp) final;
	virtual bool getDisable() final;
	virtual void setPosition(int x_, int y_);
	virtual void setPosition(Vec2 vPosition);
	/*Observer Pattern Implemented*/
	virtual void Attach(IObserver* observer_);
	virtual void Detach(IObserver* observer_);
	/*Observer Pattern Implemented*/
	virtual void Notify();
//	virtual void HandleCollison(); Update this in the future
	Vec2 getPosition();
	static vector<GameObject*> ObjHolder; //Switch this to a list <----------------------------------------
	void DrawLine(Vec2 start_, Vec2 end_);
	string nameID;
	template <typename T> std::shared_ptr<T> AddComponent()
	{
		//this ensures that we only try to add a class the derives 
		//from component. This is tested at compile time.
		static_assert(std::is_base_of<Component, T>::value,
			"T must derive from Component");//<-- need to look at std::is_base_of()

			//check to see if we have this component already
		for (auto& exisitingComponent : components)
		{
			// Currently we prevent adding the same component twice
			// This may be something we will change in the future. 
			if (std::dynamic_pointer_cast<T>(exisitingComponent))
			{
				return std::dynamic_pointer_cast<T>(exisitingComponent);
			}
		}
		// The object does not have this component so we create it and 
		// and it to our list.
		std::shared_ptr<T> newComponent = std::make_shared<T>(this);
		components.push_back(newComponent);

		return newComponent;
	};

	template <typename T> std::shared_ptr<T> GetComponent()
	{
		static_assert(std::is_base_of<Component, T>::value,
			"T must derived from Component");
		
		//Check that we don't already have a component of this type.
		for (auto& exisitingComponents : components)
		{
			if (std::dynamic_pointer_cast<T>(exisitingComponents))
			{
				return std::dynamic_pointer_cast<T>(exisitingComponents);
			}
		}
	}

private:
	bool disableObject;
	int posX; // Individual postions X and Y. I don't want these variables to be touched 
	int posY;
	float deltaTime;
	Vec2 moveMiddle(Vec2 pos_); // moves the postion of the game object from the top right corner of the screen to the middle 
	std::vector<std::shared_ptr<Component>> components;
protected:
	/*Functions*/
	virtual void UpdatePostion() final;
	int ReadAmountOfAnimations();
	void setDelta(float deltaTime_);
	float getDelta();
	/*Members variables*/
	float orientation;
	float rotation;
	float maxAcceleration;
	bool textureIsOn;
	std::string ID;
	/*Object Members*/
	Vec2 realPosition; // real position
	Vec2 APosition; // stands for Anchor Position -> middle of image or square
	Vec2 velocity;
	SDL_Texture* nullObjTexture;
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	GameObject* ptr;
	
};


#endif // !GAMEOBJECT_HEADER
