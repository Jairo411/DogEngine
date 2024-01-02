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
/*
* 8/16/2022
* Singleton threadmanager Interface. 
*/
	class ThreadManager
	{
	public:

		ThreadManager(ThreadManager& other) = delete;
		ThreadManager(const ThreadManager&) = delete;
		ThreadManager& operator = (ThreadManager& other) = delete;
		ThreadManager& operator =(const ThreadManager&) = delete;

		static ThreadManager* GetInstance();
		///Set the maximum number of threads
		void setMaxAmountOfThreads(int MaxAmount_);
		///Add thread to ThreadManager
		void AddThreadAble(ThreadAble* threadAbleOBJ_);
		///Remove thread from ThreadManager
		void RemoveThreadAble(ThreadAble* threaAbleOBJ_);
		///Start thread
		void StartThread(ThreadAble* threadAbleOBJ_);
		///Stop thread
		void StopThread(ThreadAble* threadAbleOBJ_);
	private:
		ThreadManager();
		~ThreadManager();
		static ThreadManager* instance;
		std::map<ThreadAble*, Thread_Guard*> threadDictionary;

		int AmountOfThreads;
		int MAXSIZE;
	};

#endif //THREADMANAGER_H
