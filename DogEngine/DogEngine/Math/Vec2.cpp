#include "Vec2.h"

vec2::vec2()
{
	x = 0;
	y = 0;
	mag = 0;
	dot = 0;
	cross = 0;
}

vec2::vec2(int x_, int y_)
{
	x = x_;
	y = y_;
	mag = SetMag();
}

vec2::vec2(float x_, float y_)
{
	x = x_;
	y = y_;
	mag = SetMag();
}

vec2::~vec2()
{
}

float vec2::GetDot()
{
	return dot;
}

float vec2::GetMag()
{
	return mag;
}

vec2 vec2::Normalize()
{
	vec2 vector = vec2(x / this->mag, y / this->mag);

	return vector; // mag is equal to nothing so it returns some thing wacky 
}

void vec2::SetDot(vec2 b_)
{
	float tempDot;

	tempDot = (x * b_.x) + (y * b_.y);

	tempDot = dot;
}

float vec2::GetAngleBetween(vec2 b_)
{
	vec2 vec2;
	float tempDot0 = dot;
	float tempDot1;

	//vec2 = vec2(b_.x, b_.y);

	vec2.SetDot(b_);
	tempDot1 = vec2.dot;

	float totalDot = tempDot0 + tempDot1;

	float totalMag = this->mag * vec2.mag;
	
	float angle = cosf(totalDot / totalMag);

	return angle;
}

float vec2::SetMag()
{
	float tempMag;

	tempMag = powf(this->x, 2)+powf(this->y,2);

	tempMag = sqrtf(tempMag);

	return tempMag;

}

vec2 vec2::operator+(const vec2& b_)
{
	vec2 vec2;

//	vec2 = vec2(this->x + b_.x, this->y + b_.y);	
	return vec2;
}

vec2 vec2::operator-(const vec2& b_)
{
	vec2 vec2;

//	vec2 = vec2(this->x - b_.x, this->y - b_.y);
	return vec2;

}

vec2 vec2::operator+(const vec2* b_)
{
	vec2 vec2;

//	vec2 = vec2(this->x + b_->x, this->y + b_->y);
	return vec2;
}

vec2 vec2::operator-(const vec2* b_)
{
	vec2 vec2;

//	vec2 = vec2(this->x + b_->x, this->y + b_->y);
	return vec2;
}

vec2 vec2::operator*(const float& b_)
{
	vec2 vec2;

//	vec2 = vec2(this->x * b_, this->y * b_);
	return vec2;
}

vec2 vec2::operator*(const int& b_)
{
	vec2 vec2; 

//	vec2 = vec2(this->x * b_,this->y*b_);
	return vec2;
}

bool vec2::operator==(const vec2& b_)
{
	if (x==b_.x && y==b_.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool vec2::operator!=(const vec2& b_)
{
	if (x!=b_.x && y!=b_.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}


vec2 vec2::rotate()
{


	return vec2();
}

std::ostream& operator<<(std::ostream& os, const vec2& b_)
{
	os << " Position X: " << b_.x << "Position Y:" << b_.y;

	return os;
}

