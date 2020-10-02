#ifndef MATH_H
#define MATH_H
#include <math.h>
/*Simple Vector 2 class with basic vector math
 All children Classes of GameObject will carry the Vec2 class*/

class Vec2
{
public:
	Vec2();
	Vec2(int x_, int y_);
	~Vec2();
	
	float getX();
	float getY();
	float GetDot();

	void SetDot(Vec2 b_);
	float GetAngleBetween(Vec2 b_);
	/*Overloading operators So I can simpily Add Vectors and subtract themd*/
	Vec2 operator+(const Vec2& b_);
	Vec2 operator-(const Vec2 & b_);
	Vec2 rotate();
private: 
	 float SetMag();
	 float x, y;
	 float mag;
	 float dot, cross;
};

#endif // !MATH_H