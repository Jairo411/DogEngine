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
	assert(AmountOfThreads > MAXSIZE);
	if (static_cast<ThreadAble*>(threadAbleOBJ_))
	{
		Scoped_Thread* threadPtr = nullptr;
		threadDictionary.insert(std::pair<ThreadAble*, Scoped_Thread*>(threadAbleOBJ_,threadPtr));
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

void ThreadManager::StartThread(ThreadAble* threadAbleOBJ_)
{
	threadAbleOBJ_->setThreadAble(true);
	Scoped_Thread* temp = threadDictionary.at(threadAbleOBJ_);
	std::thread tempThread = std::thread(threadAbleOBJ_);
	temp = new Scoped_Thread(&tempThread);
}

void ThreadManager::StopThread(ThreadAble* threadAbleOBJ_)
{
	threadAbleOBJ_->setThreadAble(false);
	Scoped_Thread* temp = threadDictionary.at(threadAbleOBJ_);
	RemoveThreadAble(threadAbleOBJ_);
	temp->~Scoped_Thread();
}
