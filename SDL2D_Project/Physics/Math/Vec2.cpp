#include "Vec2.h"

Vec2::Vec2()
{
	x = 0;
	y = 0;
	mag = 0;
	dot = 0;
	cross = 0;
}

Vec2::Vec2(int x_, int y_)
{
	x = x_;
	y = y_;
	mag = SetMag();
}

Vec2::~Vec2()
{
}

float Vec2::getX()
{
	return x;
}

float Vec2::getY()
{
	return y;
}

float Vec2::GetDot()
{
	return dot;
}

void Vec2::SetDot(Vec2 b_)
{
	float tempDot;

	tempDot = (this->x * b_.x) + (this->y * b_.y);

	tempDot = dot;
}

float Vec2::GetAngleBetween(Vec2 b_)
{
	Vec2 vec2;
	float tempDot0 = dot;
	float tempDot1;

	vec2 = Vec2(b_.x, b_.y);

	vec2.SetDot(b_);
	tempDot1 = vec2.dot;

	float totalDot = tempDot0 + tempDot1;

	float totalMag = this->mag * vec2.mag;
	
	float angle = cosf(totalDot / totalMag);

	return angle;
}

float Vec2::SetMag()
{
	float tempMag;

	tempMag = powf(x, 2.0f)+powf(y,2.0f);

	tempMag = sqrtf(tempMag);

	return tempMag;

}

Vec2 Vec2::operator+(const Vec2& b_)
{
	Vec2 vec2;

	vec2.x = this->x + b_.x;
	vec2.y = this->y + b_.y;

	mag = vec2.SetMag();

	return vec2;
}

Vec2 Vec2::operator-(const Vec2& b_)
{
	Vec2 vec2;

	vec2.x = this->x - b_.x;
	vec2.y = this->y - b_.y;

	mag = vec2.SetMag();

	return vec2;
}

Vec2 Vec2::rotate()
{


	return Vec2();
}

