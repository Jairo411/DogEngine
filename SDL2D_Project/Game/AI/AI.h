#ifndef AI_H
#define AI_H
#include "../../Physics/Math/Vec2.h"
#include "../../GameObjects/GameObject.h"
class AI
{
public:
	AI() {};
	virtual ~AI() {};
	virtual void SetTarget(GameObject* obj_) final;
	virtual void Chase() = 0;
	virtual void Purse() = 0;
	//	virtual void CollisonAvoidance();
	//	virtual void Cohensions();
protected:
	bool chaseFlag;
	Vec2 targetPos;
	GameObject* targetObj;

	enum Enabled
	{
		FALSE = 0,
		TRUE
	};

	enum STATES
	{
		IDLE = 0,
		CHASE,
		ATTACK,

	};
};
#endif //AI_H
