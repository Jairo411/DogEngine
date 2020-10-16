#ifndef AI_H
#define AI_H
#include "../../Physics/Math/Vec2.h"
#include "../../GameObjects/GameObject.h"
class AI
{
public:
	AI() {};
	virtual ~AI() {};
	virtual void UpdateAI()=0;
	virtual void SetTarget(GameObject* obj_) final;
	virtual void Purse();
	virtual void CollisonAvoidance();
	virtual void Cohensions();
protected:
		Vec2 targetPos;
		GameObject* targetObj;
};
#endif //AI_H
