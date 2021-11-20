#ifndef THREADABLE_H
#define THREADABLE_H
#include "ScopedThread.h"
#include <functional>
#include <variant>

class SDLRenderer;
class OpenGLRenderer;
class VulkanRenderer;

class ThreadAble
{
protected:
	ThreadAble();
	virtual ~ThreadAble()=0;
	//Define This in my classes that are threadable
	virtual void operator ()() = 0;
	
	///Returns a function pointer of any type 
	template <typename T, typename ... Args>
	T getReturnType()
	{
		return std::function<T(Args ...)> temporaryReturn;
	};
	///A simple flag to redirect the functions calls to a multithreaded Format 
	template<typename T>
	bool isThreadAble()
	{
		if (static_cast<this>(T)==true)
		{
			return true;
		}
		else
		{
			return false;
		}
	};
private:
	ThreadAble& operator=(const ThreadAble&)=delete;
	Scoped_Thread* threadPtr;
	
};
#endif // !ThreadAble

