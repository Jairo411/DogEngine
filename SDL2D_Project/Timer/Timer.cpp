#include "Timer.h"

Timer* Timer::instance = nullptr;

Timer::Timer() :  FPS(0), SecondsFlag(false), thresHold(0.0f), prevPerformaceTicks(0), currentPerformanceTicks(0), FramePerSecondFlag(0.0f), flag(0), totalFrames(0), updateLag(0.0), delta(0.0f), updateLoopSpeed(0.0f)
{
}

Timer::~Timer()
{
}

void Timer::Start()
{
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
		PrintUpdate();
		PrintFPS();
	}

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

void Timer::IncrementUpdateLag(double updateLag_)
{
	updateLag += updateLag_;
//	std::cout << "sleepTime:" << updateLag << std::endl;
}

double Timer::GetUpdateLag()
{
	return updateLag;
}

void Timer::SetLogicLoopSpeed(int FPS_)
{
	updateLoopSpeed = ONESECOND/(float)FPS_; //1/60 = 0.0166 seconds 
	updateLoopSpeed *= ONESECOND; //convert 0.0166 seconds to 16 miliseconds

	int x = 0;
	x += 1;
}

double Timer::getMS_Machine_UpdateFPS()
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
	std::chrono::duration<double,std::milli> time = elasped;
	delta = time.count();
	return delta;
}

int Timer::GetTotalAmountTime()
{
	std::chrono::duration<float> elasped = steadyTP.first - steadyTP.second; //elapsed == current - pervious 
	int time = std::chrono::duration_cast<std::chrono::seconds>(elasped).count();
	assert(time<0.0f);
	return time;
}

void Timer::PrintUpdate()
{
	double miliconversion = delta * 1000;
	std::cout << "Current Machine Update" << miliconversion << TimeUnit <<std::endl;
}


void Timer::PrintFPS()
{
	std::cout << "FPS: " << FPS << std::endl;
}

