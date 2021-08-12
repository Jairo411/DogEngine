#ifndef M2x2_H
#define M2x2_H 
#include <array>
/*Purpose of this class will be that, it only is really use to seperately hold rotation data.
,because I cannot change the dimensons or rather the number of position elements I have mathematically.
 Ill just keep this here probably for rotations and such. */
class M2x2
{
public:
	M2x2();
	~M2x2();
	void identity();
	// logical check
	bool operator ==(M2x2 rhs);
	// matrix addition 
	M2x2 operator +(M2x2 rhs);
	// matrix subtraction 
	M2x2 operator *(M2x2 rhs);
private:
	std::array<float, 4> positions;
};
#endif 
