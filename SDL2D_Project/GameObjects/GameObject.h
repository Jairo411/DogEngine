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
/*You are currently implementing this as a player object and enemy object class.
might want to strip this class of alot of it's functionality leave basic functionality. 
and expand the functionailty to child classes. 
potentailly going to have gameObjects with no movement or extra functionality being used and having a bunch of null variables */
class TextureManager;
class GameObject
{
public:
	GameObject();
   virtual void Update(float deltaTime_)=0;
   virtual void Render()=0;
   virtual void Disable() = 0;
   virtual bool setDisable(bool temp) final;
   virtual bool getDisable() final;
   virtual int  getX();
   virtual int  getY();
   Vec2 getPostion();
   static vector<GameObject*> ObjHolder;
    
private:
	bool disableObject;
protected:
	int posX;
	int posY;
	float orientation;
	float rotation;
	float maxAcceleration; 
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
