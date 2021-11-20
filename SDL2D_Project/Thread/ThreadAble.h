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
public:
	ThreadAble()
	{
		isthreadAssigned = false;
	};
	virtual ~ThreadAble() = 0;

	void setThreadAble(bool thread_)
	{
		isthreadAssigned = thread_;
	};
	//Define This in my classes that are threadable
	virtual void operator ()() = 0;
protected:
	///Returns a function pointer of any type 
	template <typename T, typename ... Args>
	T getReturnType()
	{
		return std::function<T(Args ...)> temporaryReturn;
	};
	///A simple flag to redirect the functions calls to a multithreaded Format 
	template<typename T>
	static bool isThreadAble()
	{
		if (static_cast<this>(T)==true && isthreadAssigned==true) //This is saying if the upcast from whatever Type has the parent Threadable and the threadPtr is currently pointing somewhere, then true
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
	bool isthreadAssigned;
};
#endif // !ThreadAble

