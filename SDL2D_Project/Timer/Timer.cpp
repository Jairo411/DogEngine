#include "Timer.h"
#define MILLISECONDS_TO_SECONDS /1000.0f 

Timer* Timer::instance = nullptr;
std::list<LocalTimer*> Timer::localTimersContainer = std::list<LocalTimer*>();
LocalTimer* Timer::currentLocaltimerPtr = nullptr;

Timer::Timer()
{
	prevTicks = 0;
	currentTicks = 0;
	prevPerformaceTicks = 0;
	currentPerformanceTicks = 0;
	FramePerSecondFlag = 0.0;
	flag = 0;
	totalFrames = 0;
	updateLag = 0;
	delta = 0.0;
	thresHold = 0.0;
	updateLoopSpeed = 0.0f;
}

Timer::~Timer()
{
}

void Timer::Start()
{
	prevTicks = SDL_GetTicks();
	currentTicks = SDL_GetTicks();

	//masterPerformanceClock.first is the prevTimer and then second part of the pair is the current tick
	performanceClock.first = std::chrono::high_resolution_clock();
	performanceClock.second = std::chrono::high_resolution_clock();

	performanceTP.second = performanceClock.second.now();
	performanceTP.first = performanceClock.first.now();

	steadyClock.first = std::chrono::steady_clock();
	steadyClock.second = std::chrono::steady_clock();

	steadyTP.second = steadyClock.second.now();
	steadyTP.first = steadyClock.first.now();
}

void Timer::UpdateSteadyClock()
{
	//This Update is for our SteadyClock timePoints
	prevTicks = currentTicks;
	currentTicks = SDL_GetTicks();

	steadyTP.second = steadyTP.first;
	steadyTP.first = steadyClock.first.now();
}

void Timer::UpdatePerformanceClock()
{
	performanceTP.second = performanceTP.first;
	performanceTP.first = performanceClock.first.now();
 	
	delta = GetDelta();
	FramePerSecondFlag += delta;
	if (FramePerSecondFlag>=ONESECOND)
	{
		FPS = totalFrames;
		PrintFPS();
	}
}

float Timer::GetDeltaTime() const
{
	return static_cast<float>(currentTicks - prevTicks) MILLISECONDS_TO_SECONDS;
}



float Timer::GetCurrentTicks()
{
	return static_cast<float>(currentTicks)  MILLISECONDS_TO_SECONDS;
}

Timer* Timer::GetInstance()
{
	if (instance ==nullptr)
	{
		instance = new Timer();
	}
	else
	{
		return instance;
	}
}

void Timer::IncrementSleepTime()
{
	double tempDelta = GetDelta();
	updateLag += tempDelta;
}

double Timer::getSleepTime()
{
	return updateLag;
}


void Timer::IncrementFrames()
{
	if (FramePerSecondFlag<ONESECOND)
	{
		totalFrames++;
	}
	else if (FramePerSecondFlag>ONESECOND)
	{
		totalFrames = 0;
		FramePerSecondFlag = 0.0;
	}
}

void Timer::PrintFPS()
{
	std::cout << "FPS: " << FPS << std::endl;
}

double* Timer::GetUpdateLag()
{
	return &updateLag;
}

void Timer::SetLogicLoopSpeed(int FPS_)
{
	double conversion = (double)FPS_;
	updateLoopSpeed = 1.0 / conversion;
}



double Timer::GetMachineLoopSpeed()
{
	return updateLoopSpeed;
}

double Timer::GetDelta()
{
	std::chrono::nanoseconds elasped = performanceTP.first - performanceTP.second; //elapsed == current - pervious 
	double time = std::chrono::duration<double, std::milli>(elasped).count();
//	time /= 1000.0;
	return time;
}

int Timer::GetTotalAmountTime()
{
	return 0;
}

void Timer::AddLocalTimer(LocalTimer local_)
{
	localTimersContainer.push_back(&local_);
}

void Timer::StartTimer()
{
	assert(localTimersContainer.empty() == true);
	LocalTimer* tempLocalTimer = nullptr;
	tempLocalTimer = localTimersContainer.back();
	if (tempLocalTimer->steady==false)
	{
		tempLocalTimer->LocalTimerPairHigh.first = std::chrono::high_resolution_clock();
		currentLocaltimerPtr = tempLocalTimer;
	}
	else
	{
		tempLocalTimer->LocalTimerPairSteady.first = std::chrono::steady_clock();
		currentLocaltimerPtr = tempLocalTimer;
	}

	
}

void Timer::StartTimer(LocalTimer local_)
{
	assert(localTimersContainer.empty()==true);
	for (auto timer : localTimersContainer  )
	{
		if (timer==&local_)
		{
			if (timer->steady==false)
			{
				timer->LocalTimerPairHigh.first = std::chrono::high_resolution_clock();
				currentLocaltimerPtr = timer;
			}
			else
			{
				timer->LocalTimerPairHigh.first = std::chrono::steady_clock();
				currentLocaltimerPtr = timer;
			}
		}
	}
	
}

LocalTimer* Timer::GetLocalTimer()
{
	return currentLocaltimerPtr;
}

bool Timer::getCurrentLocalTimerFlag()
{
	return false;
}

void Timer::UpdateAllLocalTimers()
{
}




