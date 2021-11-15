#ifndef INPUTABLE_H
#define INPUTABLE_H
#include <list>

class Input;
/*Welcome to my INPUT HANDLER CLASS*/
class Inputable
{
public:
	//Constructor & Destructor 
	Inputable() { inputContainer = std::list<Input*>(); }
	Inputable(Input* InputFunctionally) { inputContainer.push_back(InputFunctionally); }
	~Inputable() { inputContainer.empty(); }
	//Functions 
	void AddFunctionallity(Input* InputFunctionally) { inputContainer.push_back(InputFunctionally); }
	void RemoveFuncationality(Input* InputFunctionally) { inputContainer.remove(InputFunctionally); }
private:
	std::list<Input*> inputContainer;
};
#endif // !KEYINPUT_H*/
