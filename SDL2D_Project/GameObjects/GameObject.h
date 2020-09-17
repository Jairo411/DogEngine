#ifndef GAMEOBJECT_HEADER
#define GAMEOBJECT_HEADER
#include <string>
#include "SDL.h"
#include <map>
#include <list>
#include<vector>
#include<iostream>
#include<fstream>
using namespace std;

/*Standard GameObject class should be abstract and should be the base class.
of any game object in the game i.e
-Enemies
-Enviromental stuff
-Player and Player weapons
Basically anything with a texture.
*/
class TextureManager;
class GameObject
{
public:
   virtual void Update()=0;
   virtual void Render()=0;
   virtual void Disable() = 0;
   virtual bool setDisable(bool temp) final;
   virtual bool getDisable() final;
   static vector<GameObject*> ObjHolder;
   GameObject();
   
private:
	bool disableObject;
	//static vector<GameObject*> gameObjectContainer;
protected:
	int posX;
	int posY;
	string nameID;
	bool intiAnimation(const char* AnimSetName, const char* relativeDir,const char firstChar);
	int ReadAmountOfAnimations();
	bool textureIsOn;
	vector <vector<SDL_Texture*>> animationSet;
	SDL_Texture* nullObjTexture;
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	GameObject* ptr;
};



template <typename T>
class OBJArray
{
private:
	int cap;
	int numberElements;
	T* arr;
public:
	OBJArray();
	~OBJArray();
	int size()const;
	void add(const T &obj);
	T& get(int index);
};

template<typename T>
inline OBJArray<T>::OBJArray()
{
	this->cap = GameObject::getMaxOBJs();
	this->numberElements = 0;
	this->arr = new T[this->cap];
}

template<typename T>
inline OBJArray<T>::~OBJArray()
{
	delete[] this->arr;
}

template<typename T>
inline int OBJArray<T>::size() const
{
	return numberElements;
}

template<typename T>
inline void OBJArray<T>::add(const T &obj)
{
	if (this->numberElements<this->cap)
	{
		this->arr[this->numberElements++] = obj;
	}
	else
	{
		cout << "reached amount maximum amount of objects in scene";
	}
}

template<typename T>
inline T& OBJArray<T>::get(int index)
{
	if (index<0|| index>=this->numberElements)
	{
		throw"Bad index";

		return this->arr[index];
	}
}
#endif // !GAMEOBJECT_HEADER
