#ifndef GAMEOBJECT_HEADER
#define GAMEOBJECT_HEADER
#include <string>
#include "SDL.h"
#include <map>
#include <list>
#include<vector>
#include<iostream>
#include<fstream>
#include"../Physics/Math/Vec2.h"
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
	GameObject();
   virtual void Update()=0;
   virtual void Render()=0;
   virtual void Disable() = 0;
   virtual bool setDisable(bool temp) final;
   virtual bool getDisable() final;
   virtual int  getX();
   virtual int  getY();
   static vector<GameObject*> ObjHolder;
    
private:
	bool disableObject;
	//static vector<GameObject*> gameObjectContainer;
protected:
	int posX;
	int posY;
	float orientation;
	float rotation;
	bool textureIsOn;
	bool intiAnimation(const char* AnimSetName, const char* relativeDir,const char firstChar);
	int ReadAmountOfAnimations();
	string nameID;
	Vec2 position;
	Vec2 velocity; 
	vector <vector<SDL_Texture*>> animationSet;
	SDL_Texture* nullObjTexture;
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	GameObject* ptr;
};


#endif // !GAMEOBJECT_HEADER
