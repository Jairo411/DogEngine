#include "AI.h"

void AI::SetTarget(GameObject* obj_)
{
	/* I should Just get the refence to the object*/
	
		if (targetObj == nullptr)
		{
			targetObj = obj_;
		}
}
