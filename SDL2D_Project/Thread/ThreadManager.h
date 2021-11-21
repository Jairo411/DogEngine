#ifndef THREADMANAGER_H
#define THREADMANAGER_H
#define MAXTHREADS = 8; //The maximum amount of threads you can have in this program
#define MINTHREADS = 4; // the minimum amount of threads you can have in this program
#include <vector>
#include <map>
#include <iostream>
#include <assert.h>
#include "ThreadAble.h"
#include "ThreadGuard.h"
#include "../Renderer/Renderer.h"
class ThreadManager
{
public:

	ThreadManager(ThreadManager& other) = delete;
	void operator =(const ThreadManager&) = delete;

	static ThreadManager* GetInstance();
	/// You can only choose two types of total Threads to be used 4,8.
	void setMaxAmountOfThreads(int MaxAmount_);
	//Actually pass it a object that is threadable, instead of a actual thread
	//The thread doesn't actually start running here
	void AddThreadAble(ThreadAble* threadAbleOBJ_);
	void RemoveThreadAble(ThreadAble* threaAbleOBJ_);

	
	void StartThread(ThreadAble* threadAbleOBJ_);

	void StopThread(ThreadAble* threadAbleOBJ_);

private:
	ThreadManager();
	~ThreadManager();

	static ThreadManager* instance;
	int AmountOfThreads;
	int MAXSIZE;
	std::map<ThreadAble*, Thread_Guard*> threadDictionary;
};
#endif //THREADMANAGER_H
