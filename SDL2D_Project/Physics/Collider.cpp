#include "Collider.h"

Collider::Collider(int x_, int y_)
{
	x = x_;
	y = y_;
	area = x * y;
	collisonObjectType = NONE;
	collisonType = NONE;
}

void Collider::CollisonUpdate()
{
	switch (collisonObjectType)
	{
	case Collider::NONE:
		break;
	case Collider::GameObject:
		/*switch (collisonType)
		{
		case Collider::NONE:
			break;
		case Collider::Projectile:
			break;
			/*if the Mouse Has clicked on a gameObject  Let the Engine at least 
			know what type of object it is and if it has a collider */
		/*case Collider::Mouse:
			 
			break;
		case Collider::GameObject:
			break;
		default:
			break;
		}*/
		break;
	default:
		break;
	}
}

void Collider::CollisonRender()
{
}

void Collider::SetCollisonObjectType(int col_)
{
	collisonObjectType = col_;
}

void Collider::SetCollisonType(int col_)
{
	collisonType = col_;
}

Collider::~Collider()
{
}

