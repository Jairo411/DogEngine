#ifndef AI_H
#define AI_H
#include "../../Physics/Math/Vec2.h"
class AI
{
public:
	void kinematicSteeringOutput();
	void steeringOutput();
private:
	Vec2 position;
	float orientation; //<-- this should only flip the sprites 
};
#endif //AI_H
