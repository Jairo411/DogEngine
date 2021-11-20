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
 	
	delta = CalculateDelta();
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
	//std::chrono::nanoseconds elapsed = performanceTP1 - performanceTP2;
	//double delta = std::chrono::duration<double, std::micro>(elapsed).count();
	// return 
}

//unsigned int Timer::GetSleepTime(unsigned int fps_) const
//{
//	unsigned int milliPerFrame = 1000/fps_;
//	if (milliPerFrame==0)
//	{
//		return 0;
//	}
//
//	unsigned int sleepTime = milliPerFrame - SDL_GetTicks();
//	
//	if (sleepTime> milliPerFrame)
//	{
//		return milliPerFrame;
//	}
//
//	return sleepTime;
//}

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
	double tempDelta = CalculateDelta();
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
	else if (FramePerSecondFlag>=ONESECOND)
	{
		totalFrames = 0;
		FramePerSecondFlag = 0.0;
	}
}

void Timer::PrintFPS()
{
	std::cout << "FPS: " << FPS << std::endl;
}



void Timer::IncrementUpdateLag(double updateLag_)
{
	updateLag += updateLag_;
	std::cout << "sleepTime:" << updateLag << std::endl;
}

double Timer::GetUpdateLag()
{
	return updateLag;
}

void Timer::SetLogicLoopSpeed(int FPS_)
{
	updateLoopSpeed = 1.0/(double)FPS_; //1/60 = 0.016
}

double Timer::getMS_Machine_Update()
{
	return updateLoopSpeed;
}

double Timer::GetDelta()
{
	return delta;
}

double Timer::CalculateDelta()
{
	std::chrono::nanoseconds elasped = performanceTP.first - performanceTP.second; //elapsed == current - pervious 
	double time = std::chrono::duration<double, std::milli>(elasped).count();
	time /= 1000.0;
	return time;
}

int Timer::GetTotalAmountTime()
{
	std::chrono::duration<float> elasped = steadyTP.first - steadyTP.second; //elapsed == current - pervious 
	float time = elasped.count();
	assert(time<0.0f);
	return (int)time;
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
	tempLocalTimer->LocalTimerPair.first = std::chrono::steady_clock();
	currentLocaltimerPtr = tempLocalTimer;
}

void Timer::StartTimer(LocalTimer local_)
{
	assert(localTimersContainer.empty()==true);
	for (auto timer : localTimersContainer  )
	{
		if (timer==&local_)
		{
			timer->LocalTimerPair.first = std::chrono::steady_clock();
			currentLocaltimerPtr = timer;
		}
	}
	
}

void Timer::SetTimer(std::chrono::milliseconds milli_)
{
	currentLocaltimerPtr->timerLimit = (double)milli_.count();
}

void Timer::SetTimer(std::chrono::seconds secs_)
{
	currentLocaltimerPtr->timerLimit = (double)secs_.count();
}

bool Timer::getCurrentLocalTimerFlag()
{
	if (currentLocaltimerPtr->timerLimit<=0.0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Timer::UpdateAllLocalTimers()
{
}




