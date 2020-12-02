#ifndef CLIENTINTERFACENETWORK
#define CLIENTINTERFACENETWORK
/*This networking class will 
 set up all  base game information*/

/* This is going to be an interface 
attached to The Client Project I have*/

class GameState;
class ClientInterface 
{
public:
	ClientInterface();
	~ClientInterface();

protected:
	bool isRunning;
};


#endif

