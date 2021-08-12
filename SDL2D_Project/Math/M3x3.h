#ifndef M3x3_H
#define M3x3_H
#include <array>
/* Main thing Im going to use in order to show off my knowledge of matrices and how they can be used as transforms */
class M3x3
{
public:
	M3x3();
	~M3x3();
	void identity();
	M3x3 operator ==(M3x3 rhs);
	M3x3 operator + (M3x3 rhs);
	M3x3 operator * (M3x3 rhs);
private:
	std::array <float, 9> positions;
};
#endif M3x3_H
