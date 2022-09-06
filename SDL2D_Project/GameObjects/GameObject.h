#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <string>
#include <SDL.h>
#include <map>
#include <list>
#include<vector>
#include<iostream>
#include<fstream>
#include<type_traits>
#include <utility>
#include "Object.h"
#include "../Components/C_2DTransform.h"
#include "../DogEngine/DogEngineDefinitions.h""
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

	2022-01-11	
	Happy new year :) 
	https://gameprogrammingpatterns.com/update-method.html
	here is a link so you can update the "update" design pattern you have for your gameobjects
	I did it :) 2022-01-22
*/
/*
NOTES:
CHECK ON SHARED_PTR 
CHECK dynamic_PTR CAST
ALSO Remove IObserverable
*/

class GameObject : public BaseObj   
{
public:
	GameObject();
	virtual ~GameObject();
	virtual void OnCreate()=0;
	virtual void OnDestroy()=0;
	virtual void Update(float deltaTime_)=0;
	virtual void Render()=0; 
	///Set position
	virtual void setPosition(int x_, int y_) final;
	///Set position
	virtual void setPosition(vector2 position_) final;
	///Returns the Pivot Position (the middle) of the object position
	virtual vector2 getPivotPosition() final; 
	///Returns the actual Sreen Coordinate position
	virtual vector2 getPosition() final;
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
		T* componentType;
		for (Component* component : components)
		{
			componentType = dynamic_cast<T*>(component);
			if (componentType != nullptr)
			{
				std::string typePtrID = typeid(componentType).name();
				std::string ComponentPtrID = typeid(componentType).name();
				if (strcmp(typePtrID.c_str(), ComponentPtrID.c_str()) == 0) // if the types are the same types then return the current type
				{
					return componentType;
				}
			} 
		}
		std::cout << "Couldn't find component" << std::endl;
		return nullptr;
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
	virtual void UpdatePostion() final;
	Transform2D transform; //transform that holds all object data , orientation , position and size. 
	vector2 position;   // the x and y position.
	vector2 pivotPosition; // stands for Pivot Position -> moved the origin of the gameObject to the middle of its rect.
private: 
	std::vector<Component*> components;
};


#endif // !GAMEOBJECT_HEADER
