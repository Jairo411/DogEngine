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
	std::thread& GetThread()
	{
		return t;
	}
	void CloseThread()
	{
		if (t.joinable()==true)
		{
			t.join();
		}
		else
		{
			std::cout << "Tried to join thread that wasn't joinable" << std::endl;
		}
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

