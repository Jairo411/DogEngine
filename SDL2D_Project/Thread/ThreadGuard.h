#ifndef SCOPEDTHREAD_H
#define SCOPEDTHREAD_H
#include <thread>
#include <stdexcept>
class Thread_Guard
{
public:
	Thread_Guard()
	{
		
	}
	void setGuard(std::thread t_)
	{
		t = std::thread();
		t = std::move(t_);
	}
	~Thread_Guard()
	{
		
	}
	Thread_Guard(Thread_Guard const&) = delete;
	Thread_Guard& operator =(Thread_Guard const&) = delete;

	std::thread& getThread() 
	{
		return t;
	}

	void operator = (Thread_Guard rhs_)
	{
		//put logical condition here to check if the thread is running on a thread cause if not then crash
		this->t = std::move(rhs_.t);
	}
private:
	 std::thread t;
};

#endif // !SCOPEDTHREAD_H

