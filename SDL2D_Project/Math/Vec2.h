#ifndef MATH_H
#define MATH_H
#include <math.h>
#include <iostream>
#include <glm/glm.hpp>
/*
2022/16/8 vector math interface. 
*/
class vec2
{
public:
	vec2();
	vec2(int x_, int y_);
	vec2(float x_, float y_);
	~vec2();
	//VECTOR MATH  
	float GetDot();
	float GetMag();
	vec2 Normalize();
	vec2 rotate();
	void SetDot(vec2 b_);
	float GetAngleBetween(vec2 b_);
	/*Overloading operators VECTOR TO VECTOR*/
	vec2 operator+(const vec2& b_);
	vec2 operator-(const vec2& b_);
	vec2 operator+(const vec2* b_);
	vec2 operator-(const vec2* b_);



	/*Overloading operators VECTOR TO SCALAR*/
	vec2 operator*(const float& b_);
	vec2 operator*(const int& b_);

	/*Overloading logical operators*/
	bool operator==(const vec2& b_);
	bool operator!=(const vec2& b_);
	friend std::ostream& operator <<(std::ostream& os,const vec2& b_);
	float x, y;
private: 
	 float SetMag();
	 float mag;
	 float dot, cross;
};



#endif // !MATH_H