#ifndef MESSAGE_H
#define MESSAGE_H
#include <string>
template <class TypeMessage>
struct Message
{
	Message(TypeMessage type_, std::string timeStamp_)
	{
		if (std::is_fundamental<TypeMessage>::value)
		{
			typeM = type_;
			timeStamp = timeStamp_;
		}
		std::cerr << "Message type isn't a primitive" << std::endl;
	}
	TypeMessage getMessage()
	{
		return typeM;
	}
	TypeMessage typeM;
	std::string timeStamp;
};

#endif // !MESSAGE_H