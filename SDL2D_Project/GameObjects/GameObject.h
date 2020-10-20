#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
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
	virtual void Update(float deltaTime_) = 0;
	virtual void Render() = 0;
	virtual void Disable() = 0;
	virtual bool setDisable(bool temp) final;
	virtual bool getDisable() final;
	virtual void setPosition(int x_, int y_);
	virtual void setPosition(Vec2 vPosition);
	Vec2 getPosition();
	static vector<GameObject*> ObjHolder;
	void DrawLine(Vec2 start_, Vec2 end_);
private:
	bool disableObject;
	int posX; // Individual postions X and Y. I don't want these variables to be touched 
	int posY;
	int getX();
	int getY();
	float deltaTime;
	Vec2 moveMiddle(Vec2 pos_); // moves the postion of the game object from the top right corner of the screen to the middle
protected:
	float orientation;
	float rotation;
	float maxAcceleration;
	bool textureIsOn;
	bool intiAnimation(const char* AnimSetName, const char* relativeDir, const char firstChar); // This needs to be moved to the animator class
	virtual void UpdatePostion() final;
	int ReadAmountOfAnimations();
	void setDelta(float deltaTime_);
	float getDelta();
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
