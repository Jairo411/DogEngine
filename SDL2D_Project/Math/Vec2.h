#ifndef MATH_H
#define MATH_H
#include <math.h>
/*Simple Vector 2 class with basic vector math
 All children Classes of GameObject will carry the Vec2 class*/
/*2021-07-09
	probably can be improved on, but works soild.*/
class Vec2
{
public:
	Vec2();
	Vec2(int x_, int y_);
	Vec2(float x_, float y_);
	~Vec2();

	//VECTOR MATH  
	float GetDot();
	float GetMag();
	Vec2 Normalize();
	Vec2 rotate();
	void SetDot(Vec2 b_);
	float GetAngleBetween(Vec2 b_);

	/*Overloading operators VECTOR TO VECTOR*/
	Vec2 operator+(const Vec2& b_);
	Vec2 operator-(const Vec2& b_);
	Vec2 operator+(const Vec2* b_);
	Vec2 operator-(const Vec2* b_);



	/*Overloading operators VECTOR TO SCALAR*/
	Vec2 operator*(const float& b_);
	Vec2 operator*(const int& b_);

	/*Overloading logical operators*/
	bool operator==(const Vec2& b_);
	bool operator!=(const Vec2& b_);


	float x, y;
private: 
	 float SetMag();
	 float mag;
	 float dot, cross;
};

#endif // !MATH_H