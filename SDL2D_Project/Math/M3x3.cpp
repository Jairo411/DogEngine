#include "M3x3.h"

M3x3::M3x3()
{
	positions[0] = 0.0f;
	positions[1] = 0.0f;
	positions[2] = 0.0f;
	positions[3] = 0.0f;
	positions[4] = 0.0f;
	positions[5] = 0.0f; 
	positions[6] = 0.0f;
	positions[7] = 0.0f;
	positions[8] = 0.0f;
}

M3x3::~M3x3()
{
	positions.empty();
}

void M3x3::identity()
{
	positions[0] = 1.0f;
	positions[1] = 0.0f;
	positions[2] = 0.0f;
	positions[3] = 0.0f;
	positions[4] = 1.0f;
	positions[5] = 0.0f;
	positions[6] = 0.0f;
	positions[7] = 0.0f;
	positions[8] = 1.0f;
}

M3x3 M3x3::operator==(M3x3 rhs)
{
	return M3x3();
}

M3x3 M3x3::operator+(M3x3 rhs)
{
	M3x3 tempM = *this;

	tempM.positions[0] += rhs.positions[0];
	tempM.positions[1] += rhs.positions[1];
	tempM.positions[2] += rhs.positions[2];
	tempM.positions[3] += rhs.positions[3];
	tempM.positions[4] += rhs.positions[4];
	tempM.positions[5] += rhs.positions[5];
	tempM.positions[6] += rhs.positions[6];
	tempM.positions[7] += rhs.positions[7];
	tempM.positions[8] += rhs.positions[8];

	return tempM;
}

M3x3 M3x3::operator*(M3x3 rhs)
{
	return M3x3();
}

