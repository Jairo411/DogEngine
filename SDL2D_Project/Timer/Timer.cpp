#include "Timer.h"

Timer* Timer::instance = nullptr;

Timer::Timer() :  FPS(0),totalTime(0.0f),FramePerSecondFlag(0.0f), totalFrames(0), updateLag(0.0), delta(0.0f), updateLoopSpeed(0.0f)
{
}

Timer::~Timer()
{
}

void Timer::Start()
{
	performanceClock.first = PClock();
	performanceClock.second = PClock();

	performanceTP.second = performanceClock.second.now();
	performanceTP.first = performanceClock.first.now();

	steadyClock.first = SClock();
	steadyClock.second = SClock();

	steadyTP.second = steadyClock.second.now();
	steadyTP.first = steadyClock.first.now();
 
}

void Timer::UpdateSteadyClock()
{
	steadyTP.second = steadyTP.first;
	steadyTP.first = steadyClock.first.now();
	totalTime += CalculateTotalTime();
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
		PrintStats();
	}
}


Timer* Timer::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new Timer();
	}
	return instance;
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

void Timer::Increment_Time_Pass_Since_Update(double updateLag_)
{
	updateLag += updateLag_;
}

double Timer::GetUpdateLag()
{
	return updateLag;
}

void Timer::SetLogicLoopSpeed(int FPS_)
{
	updateLoopSpeed = 1.0f/(float)FPS_; 
	updateLoopSpeed *= 1000.0f;
}

double Timer::Get_Engine_Logic_Update_Speed()
{
	return updateLoopSpeed;
}

double Timer::GetDelta()
{
	return delta;
}


double Timer::CalculateDelta()
{
	double d =0.0;
	std::chrono::nanoseconds elasped = performanceTP.first - performanceTP.second; 
	std::chrono::duration<double,std::milli> time = elasped;
	d = time.count();
	return d;
}

float Timer::CalculateTotalTime()
{
	float totalT = 0.0f;
	std::chrono::nanoseconds elasped = steadyTP.first - steadyTP.second;
	std::chrono::duration<float> totalTime_ = elasped;
	totalT = totalTime_.count();
	return totalT;
}

void Timer::PrintDelta()
{
	std::cout << "Delta: " << delta << TimeUnit <<std::endl;
}


void Timer::PrintFPS()
{
	std::cout << "FPS: " << FPS << std::endl;
}

void Timer::PrintTotalTime()
{
	std::cout << "Total Time: " << totalTime << std::endl;
}


void Timer::PrintStats()
{
	PrintDelta();
	PrintFPS();
	PrintTotalTime();
}