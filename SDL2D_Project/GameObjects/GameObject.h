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
   virtual bool setDisable(bool temp);
   virtual bool getDisable();
   static void AddObject(GameObject* temp_);
   GameObject();
private:	
	bool disableObject;
	static vector<GameObject*> gameObjectContainer; 
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
	
	
};
#endif // !GAMEOBJECT_HEADER

