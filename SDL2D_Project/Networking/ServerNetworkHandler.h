#ifndef SERVERNETWORKHANDLER_H
#define SERVERNETWORKHANDLER_H
#include "../GameObjects/GameObject.h"
#include "../GameObjects/Map/Map.h"
/* This GameState class will hold all 
 relevant gobal,local and static game information from the Game
Stuff like:
Game Logic i.e AI functionality 
Sprites rendering 
positions of game Objects 
Input 
output (vaildate if resulted input is output). I guess 
*/

/* Best way to think about this is, the "GAMESTATE" IS THE CLIENT FOR THE SERVER 

	so in depth description: 
		the Server reads and write to the GameState, so this way 
	the server vaildates whether or not the move or changeState is vaild.*/
/*Should make this a singleton, but the extra functionality isn't really needed to be honest */

/*Data that needs to be seralized
 Gameobject classes and there child classes 
 Tile class
 Player
*/

class GameState
{
public:
	GameState();
	~GameState();
	/*Setters*/
	static void setGameObjects(std::vector<GameObject*> *Objholder_);
	static void setCurrentKeyBoardInput(std::map<int, bool> *keyboardInputV_);
	static void setCurrentMouseInput(std::map<int, bool> *MouseInput_);
	static void setServerIP(const char* IPADDRESS_);
	///*Getters*/
	static std::vector<GameObject*> *getGameObjHolder();
	static std::vector<Tile*>* getMapInfo();
	static std::map<int, bool>* getKeyboardInfo();
	static std::map<int, bool>* getMouseInfo();
	/*Single Update Function 
	We do not need to render anything IN the gamestate 
	might not need this*/
private:
	/*Pointer gallor */
	static const char* ServerAddress;
	static std::vector<GameObject*> *Objholder;
	static std::vector<Tile*> *Tiles;
	static std::map<int, bool> *KeyBoardInputV;
	static std::map<int, bool> *MouseInputV;
};



#endif 
