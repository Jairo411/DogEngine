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
#include"../DesignPattern/Observer.h"
#include"Component/Component.h"
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
	Okay so GameObject class isn't terrible like I thought it would be. Just need remove shitting SDL Centering logic that I created myself. 
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
	virtual Vec2 getPosition() final;
	static std::list<GameObject*> OBJHolder;
	void DrawLine(Vec2 start_, Vec2 end_);
	template <typename T, typename ... Args > std::shared_ptr<T> AddComponent(Args&& ... args_ ) // Move Constructor 
	{
		T* comp = new T(std::forward<Args>(args_)...); // Need to reLook at this, this has to do something with treating a Lvalue and turns it into a Lvalue or Rvalue?
		//this ensures that we only try to add a class the derives 
		//from component. This is tested at compile time.
		static_assert(std::is_base_of<Component, T>::value,
			"T must derive from Component");//<-- need to look at std::is_base_of() static assert seems to be an sort of execption checking

			//check to see if we have this component already
		for (auto& exisitingComponent : components)
		{
			// Currently we prevent adding the same component twice
			// This may be something we will change in the future. 
			if (std::dynamic_pointer_cast<T>(exisitingComponent))
			{
				return std::dynamic_pointer_cast<T>(exisitingComponent);
				std::cout << " Component Already Exists" << std::endl;
			}
		}
		// The object does not have this component so we create it and 
		// and it to our list.
		std::shared_ptr<T> pointer;
		std::shared_ptr<T> newComponent = std::make_shared<T>( new Component());
		pointer = std::dynamic_pointer_cast<Component*>(newComponent);
		components.push_back(newComponent);
		pointer->OnCreate();
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
	template <typename T> std::shared_ptr<T> RemoveComponent()
	{
		for (int i = 0; i < components.size(); i++)
		{
			if (std::dynamic_pointer_cast<T>(components[i]))
			{
				delete components[i];
				components.erase(components.begin() + i); //position 0 + index 
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
	Vec2 realPosition; // real position 
	Vec2 APosition; // stands for Anchor Position -> middle of image or square
	Vec2 velocity;
	SDL_Texture* nullObjTexture;
	SDL_Texture* objTexture;
	SDL_Rect srcRect, dstRect;
private:
	bool disableObject;
	int posX; // Individual postions X and Y. I don't want these variables to be touched 
	int posY;
	Vec2 moveMiddle(Vec2 pos_); // moves the postion of the game object from the top right corner of the screen to the middle 
	std::vector<std::shared_ptr<Component>> components;

};


#endif // !GAMEOBJECT_HEADER
