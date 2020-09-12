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
<<<<<<< HEAD
   virtual bool setDisable(bool temp) final;
   virtual bool getDisable() final;
   static int getMaxOBJs();
   static vector<GameObject*> ObjHolder;
=======
   virtual bool setDisable(bool temp);
   virtual bool getDisable();
   static void AddObject(GameObject* temp_);
>>>>>>> parent of 50f9777... 2020-09-01 1:52
   GameObject();
private:	
	bool disableObject;
	static vector<GameObject*> gameObjectContainer; 
protected:
	int posX;
	int posY;
	int ReadAmountOfAnimations();
	bool intiAnimation(const char* AnimSetName, const char* relativeDir,const char firstChar);
	bool textureIsOn;
	string nameID;
	vector <vector<SDL_Texture*>> animationSet;
	SDL_Texture* nullObjTexture;
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
<<<<<<< HEAD
	GameObject* ptr;
=======
	
	
>>>>>>> parent of 50f9777... 2020-09-01 1:52
};
#endif // !GAMEOBJECT_HEADER

