#include "ThreadManager.h"

ThreadManager* ThreadManager::instance = nullptr;

ThreadManager::ThreadManager()
{
	AmountOfThreads = 0;
	MAXSIZE = 4;
}

ThreadManager::~ThreadManager()
{
}

ThreadManager* ThreadManager::GetInstance()
{
	if (instance==nullptr)
	{
		instance = new ThreadManager();
		return instance;
	}
	else 
	{
		return instance;
	}
}

void ThreadManager::setMaxAmountOfThreads(int MaxAmount_)
{
	assert(MaxAmount_ != 4 || 8);
	MAXSIZE = MaxAmount_;
}

void ThreadManager::AddThreadAble(ThreadAble* threadAbleOBJ_)
{
	assert(AmountOfThreads > MAXSIZE!=true);
	if (static_cast<ThreadAble*>(threadAbleOBJ_))
	{
		Thread_Guard tempThreadG = Thread_Guard();
		threadDictionary.insert(std::pair<ThreadAble*, Thread_Guard*>(threadAbleOBJ_,&tempThreadG));
		AmountOfThreads++;
	}
	else
	{
		std::cout << "Object does not have the threadable Interface: " << __LINE__ << std::endl;
		std::cout << "Failed Object: " << typeid(threadAbleOBJ_).name() << std::endl;
	}
}

void ThreadManager::RemoveThreadAble(ThreadAble* threadAbleOBJ_)
{
	assert(AmountOfThreads == 0);
	threadDictionary.erase(threadAbleOBJ_);
}

void ThreadManager::StartThread(ThreadAble* threadAbleOBJ_, std::function<void()> call_)
{
	threadAbleOBJ_->setThreadAble(true);
	Thread_Guard* temp = threadDictionary.at(threadAbleOBJ_);
	temp->setGuard(std::thread(call_));
}


//void ThreadManager::StartThread(ThreadAble* threadAbleOBJ_)
//{
//	threadAbleOBJ_->setThreadAble(true);
//	Thread_Guard* temp = threadDictionary.at(threadAbleOBJ_);
//	temp->setGuard(std::thread(threadAbleOBJ_));
//}

void ThreadManager::StopThread(ThreadAble* threadAbleOBJ_)
{
//	threadAbleOBJ_->setThreadAble(false);
//	Thread_Guard* temp = threadDictionary.at(threadAbleOBJ_);
//	RemoveThreadAble(threadAbleOBJ_);
//	temp->~Thread_Guard();
}
