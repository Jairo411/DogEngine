#ifndef VEC3_H
#define VEC3_H
class Vec3
{
public:
	Vec3();
	Vec3(float x_, float y_, float z_);    
	Vec3(int x_, int y_, int z_);
	~Vec3();

	//VECTOR MATH  
	float GetDot();
	float GetMag();
	Vec3 Normalize();
	Vec3 rotate();
	void SetDot(Vec3 b_);
	float GetAngleBetween(Vec3 b_);

	/*Overloading operators VECTOR TO VECTOR*/
	Vec3 operator+(const Vec3& b_);
	Vec3 operator-(const Vec3& b_);
	Vec3 operator+(const Vec3* b_);
	Vec3 operator-(const Vec3* b_);



	/*Overloading operators VECTOR TO SCALAR*/
	Vec3 operator*(const float& b_);
	Vec3 operator*(const int& b_);

	/*Overloading logical operators*/
	bool operator==(const Vec3& b_);
	bool operator!=(const Vec3& b_);


private:
	float SetMag();
	float x, y, z;
	float magnitude;
};
#endif // !VEC3_H
