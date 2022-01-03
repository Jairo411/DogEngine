#ifndef THREADABLE_H
#define THREADABLE_H
#include "ThreadGuard.h"
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
	}
	virtual ~ThreadAble()
	{

	}
	void setThreadAble(bool thread_)
	{
		isthreadAssigned = thread_;
	};
	std::thread createThread()
	{
		return std::thread([=] {RunInstructions(); });
	}
	//Define This in my classes that are threadable
	virtual void RunInstructions() = 0;
protected:
	virtual bool getThreadAssignment()
	{
		return isthreadAssigned;
	}
private:
	bool isthreadAssigned;
};
#endif // !ThreadAble

