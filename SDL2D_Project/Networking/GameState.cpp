#include "GameState.h"


const char* GameState::ServerAddress = nullptr;
std::vector<GameObject*>* GameState::Objholder = nullptr;
std::vector<Tile*>* GameState::Tiles = nullptr;
std::map<int, bool>* GameState::KeyBoardInputV = nullptr;
std::map<int, bool>* GameState::MouseInputV = nullptr;

GameState::GameState()
{
	/*Didn't create the object yet*/
	gameStateXML = new XML("C:/Users/jalbm/source/repos/SDL2D_Project/SDL2D_Project/Networking/GameStateInfo/","newXml.xml");
	gameStateXML->addClassNode("objHolder", "GameObject");
	gameStateXML->addClassNode("otherObjectHOlder", "other");
	gameStateXML->printXML();
	system("pause");
}

GameState::~GameState()
{
	Objholder->empty();
	Tiles->empty();
	KeyBoardInputV->empty();
	MouseInputV->empty();
	Objholder = nullptr;
	Tiles = nullptr;
	KeyBoardInputV = nullptr;
	MouseInputV = nullptr;
	delete Objholder;
	delete Tiles;
	delete KeyBoardInputV;
	delete MouseInputV;
}

void GameState::setGameObjects(std::vector<GameObject*>* Objholder_)
{
	Objholder = Objholder_;
}

void GameState::setCurrentKeyBoardInput(std::map<int, bool>* keyboardInputV_)
{
	KeyBoardInputV = keyboardInputV_;
}

void GameState::setCurrentMouseInput(std::map<int, bool>* MouseInput_)
{
	MouseInputV = MouseInput_;
}

void GameState::setServerIP(const char* IPADDRESS_)
{
	ServerAddress = IPADDRESS_;
}

std::vector<GameObject*>* GameState::getGameObjHolder()
{
	return Objholder;
}

std::vector<Tile*>* GameState::getMapInfo()
{
	return Tiles;
}

std::map<int, bool>* GameState::getKeyboardInfo()
{
	return KeyBoardInputV;
}

std::map<int, bool>* GameState::getMouseInfo()
{
	return MouseInputV;
}


