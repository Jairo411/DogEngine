#ifndef AI_H
#define AI_H
#include "../../Physics/Math/Vec2.h"
class GameObject;
class AI
{
public:
	AI() {};
	virtual ~AI() {};
	virtual void UpdateAI()=0;
	virtual void SetTarget(Vec2 target_)=0;
};
#endif //AI_H
