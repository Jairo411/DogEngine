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
#include <utility>
#include"../Math/Vec2.h"
#include"Component/Component.h"
#include "Component/C_CircleCollider.h"
#include "Component/C_RectangleCollider.h"
#include "Component/C_Sprite.h"
#include "Component/C_Animation.h"
#include "Component/AnimationSet.h"
#include"../DesignPattern/Observer.h"
#include "../Input/PlayerController.h"


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
	I agree with past me, and looking forward to moving to a component base structure.
	2021-10-04 
	Okay so GameObject class isn't terrible like I thought it would be. Just need remove SDL Centering logic that I created myself. 
*/
/*
NOTES:
CHECK ON SHARED_PTR 
CHECK dynamic_PTR CAST
ALSO Remove IObserverable
*/
class TextureManager;
class IObserver;
class GameObject : public BaseObj , public IObserverable
{
public:
	GameObject();
	virtual ~GameObject();
	virtual void OnCreate()=0;
	virtual void OnDestroy() = 0;
	virtual void Update(float deltaTime_)=0;
	virtual void fixedUpdate(float deltaTime) = 0;
	virtual void Render()=0; 
	virtual void Disable() = 0;
	/*Setters*/
	virtual void setPosition(int x_, int y_);
	virtual void setPosition(Vec2 vPosition);
	/*Getters*/
	virtual bool getDisable();
	bool setDisable(bool temp);
	SDL_Texture* getTexture();
	std::pair<SDL_Rect*, SDL_Rect*> getTextureDisplayInfo();
	/*Observer Pattern Implemented*/
	virtual void Attach(IObserver* observer_);
	virtual void Detach(IObserver* observer_);
	virtual void Notify();
	///Returns the Pivot Position (the middle) of the object position
	virtual Vec2 getPivotPosition() final; 
	///Returns the actual Sreen Coordinate position
	virtual Vec2 getPosition() final;
	static std::list<GameObject*> OBJHolder;
	void DrawLine(Vec2 start_, Vec2 end_);

	//Template Component Stuff
	template <typename T, typename ... Args > void AddComponent(Args&& ... args_ ) // Move Constructor 
	{
		T* comp = new T(std::forward<Args>(args_)...);
		
		static_assert(std::is_base_of<Component, T>::value,
			"T must derive from Component");// static arrest compiles this argument during compile time. To make sure the Type I add is a component

			//check to see if we have this component already
		// The object does not have this component so we create it and 
		// and it to our list.	
		Component* newComponent;
		newComponent = dynamic_cast<Component*>(comp);
		components.push_back(newComponent);
		newComponent->OnCreate(this);
	};
	template <typename T> T* GetComponent()
	{
		static_assert(std::is_base_of<Component, T>::value,
			"T must derived from Component");
		T* CurrentType = new T();
		T* ComponentType;
		for (Component* component : components)
		{
			ComponentType = dynamic_cast<T*>(component);
			if (ComponentType != nullptr)
			{
				std::string typePtrID = typeid(CurrentType).name();
				std::string ComponentPtrID = typeid(ComponentType).name();

				if (strcmp(typePtrID.c_str(), ComponentPtrID.c_str()) == 0) // if the types are the same types then return the current type
				{
					return ComponentType;
				}
			} 
		}
	}
	template <typename T> void RemoveComponent()
	{
		static_assert(std::is_base_of<Component, T>::value,
			"T must derived from Component");
		T* ptr = new T();
		std::vector<Component*>::iterator it = components.begin();
		for (it; it != components.end(); it++)
		{
			if (dynamic_cast<T*>(*it) != nullptr)
			{
				components.erase(it);
			}
		}
	}
protected:
	/*Functions*/
	virtual void UpdatePostion() final;
	int ReadAmountOfAnimations();
	/*Members variables*/
	std::pair<SDL_Rect*, SDL_Rect*> TextureDisplayRectInfo;
	float orientation;
	float rotation;
	float maxAcceleration;
	bool textureIsOn;
	/*Object Members*/
	Vec2 Position; // real position 
	Vec2 PivotPosition; // stands for Piviot Position -> moved the origin of the gameObject to the middle of its rect
	Vec2 velocity;
	SDL_Texture* nullObjTexture;
	SDL_Texture* objTexture;
	SDL_Rect srcRect, dstRect;
private:
	bool disableObject;
	int posX; // Individual postions X and Y. I don't want these variables to be touched 
	int posY;
	Vec2 moveMiddle(Vec2 pos_); // moves the postion of the game object from the top right corner of the screen to the middle 
	std::vector<Component*> components;
};


#endif // !GAMEOBJECT_HEADER
