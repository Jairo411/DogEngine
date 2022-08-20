#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H
#include <list>
class Input;
class InputManager
{
public:
	InputManager(const InputManager&) = delete;
	InputManager(InputManager& other) = delete;
	InputManager& operator =(const InputManager&) = delete;
	InputManager& operator =(InputManager&) = delete;
	~InputManager() {};

	inline static InputManager* GetInstance()
	{
		if (instance==nullptr)
		{
			InputManager::instance = new InputManager();
		}
		return instance;
	};
	void OnCreate()
	{
		inputContainer = std::list<Input*>();
	};
	void OnDestroy()
	{
		inputContainer.empty();
	};
	void AddFunctionallity(Input* InputFunctionally) { inputContainer.push_back(InputFunctionally); }
	void RemoveFuncationality(Input* InputFunctionally) { inputContainer.remove(InputFunctionally); }
private:
	inline static InputManager* instance;
	std::list<Input*> inputContainer;
	InputManager();
};


#endif // !INPUTMANAGER_H*/
