#ifndef THREADMANAGER_H
#define THREADMANAGER_H
#include <vector>
#include "ThreadAble.h"
#include "ScopedThread.h"
class ThreadManager
{
public:
	ThreadManager();
	~ThreadManager();

	//Actually pass it a object that is threadable, instead of a actual thread
	void CreateThread(ThreadAble* threadAbleOBJ_);


	void RemoveThread(int index_);
	void RemoveThread(ThreadAble* threaAbleOBJ_);


private:
	std::vector<std::thread> ThreadContainer;
};
#endif //THREADMANAGER_H
