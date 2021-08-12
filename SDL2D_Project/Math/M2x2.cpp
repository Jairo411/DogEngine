#include "M2x2.h"

M2x2::M2x2()
{
	positions[0] = 0.0f;
	positions[1] = 0.0f;
	positions[2] = 0.0f;
	positions[3] = 0.0f;
}

M2x2::~M2x2()
{
	positions.empty();
}

void M2x2::identity()
{
	positions[0] = 1.0f;
	positions[1] = 0.0f;
	positions[2] = 0.0f;
	positions[3] = 1.0f;
}

bool M2x2::operator==(M2x2 rhs)
{
	int sameIndex = 0;
	for (int i = 0; i < 4; i++)
	{
		if (this->positions[i]==rhs.positions[i])
		{
			sameIndex++;
			if (sameIndex==4)
			{
				return true;
			}
		}
		else
		{
			return false;
		}
	}
}

M2x2 M2x2::operator+(M2x2 rhs)
{
	M2x2 tempM = *this;

	tempM.positions[0] += rhs.positions[0];
	tempM.positions[1] += rhs.positions[1];
	tempM.positions[2] += rhs.positions[2];
	tempM.positions[3] += rhs.positions[3];

	return tempM;
}

M2x2 M2x2::operator*(M2x2 rhs)
{
	M2x2 newM = M2x2();
	M2x2 tempM = *this;
	
	newM.positions[0] = (tempM.positions[0] * rhs.positions[0]) + (tempM.positions[1] * rhs.positions[2]);
	newM.positions[1] = (tempM.positions[0] * rhs.positions[1]) + (tempM.positions[1] * rhs.positions[3]);
	newM.positions[2] = (tempM.positions[2] * rhs.positions[0]) + (tempM.positions[3] * rhs.positions[2]);
	newM.positions[3] = (tempM.positions[3] * rhs.positions[1]) + (tempM.positions[3] * rhs.positions[3]);


	return newM;
}
