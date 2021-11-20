#ifndef SCOPEDTHREAD_H
#define SCOPEDTHREAD_H
#include <thread>
#include <stdexcept>
class Scoped_Thread
{
public:
	explicit Scoped_Thread(std::thread t_):t(std::move(t_)) 
	{
		if (!t.joinable())
		{
			throw std::logic_error("no thread");
		}
	}
	~Scoped_Thread()
	{
		t.join();
	}
	Scoped_Thread(Scoped_Thread const&) = delete;
	Scoped_Thread& operator =(Scoped_Thread const&) = delete;

	std::thread& getThread() 
	{
		return t;
	}

	void operator = (Scoped_Thread rhs_)
	{
		//put logical condition here to check if the thread is running on a thread cause if not then crash
		this->t = std::move(rhs_.t);
	}
private:
	 std::thread t;
};

#endif // !SCOPEDTHREAD_H

