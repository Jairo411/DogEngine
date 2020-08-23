#ifndef ENEMY_H
#define ENEMY_H
#include "GameObject.h"
using namespace std;

class Enemy: public GameObject
{
public:
	Enemy();
	void Update();
	void Render();
	bool setDisable();
	bool getDisable();
protected:

private:

};

#endif