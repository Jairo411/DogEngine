#include "Timer.h"
#define MILLISECONDS_TO_SECONDS /1000.0f 

Timer* Timer::instance = nullptr;

Timer::Timer()
{
	prevTicks = 0;
	currentTicks = 0;
	prevPerformaceTicks = 0;
	currentPerformanceTicks = 0;
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
 	
	FramePerSecondFlag += GetDelta();
	if (FramePerSecondFlag>=ONESECOND)
	{
		CalculateFrames();
	}
}

float Timer::GetDeltaTime() const
{
	return static_cast<float>(currentTicks - prevTicks) MILLISECONDS_TO_SECONDS;
	//std::chrono::nanoseconds elapsed = performanceTP1 - performanceTP2;
	//double delta = std::chrono::duration<double, std::micro>(elapsed).count();
	// return 
}

unsigned int Timer::GetSleepTime(unsigned int fps_) const
{
	unsigned int milliPerFrame = 1000/fps_;
	if (milliPerFrame==0)
	{
		return 0;
	}

	unsigned int sleepTime = milliPerFrame - SDL_GetTicks();
	
	if (sleepTime> milliPerFrame)
	{
		return milliPerFrame;
	}

	return sleepTime;
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

void Timer::SetFPS(int FrameRatePerSecond_)
{
	FPS = FrameRatePerSecond_;
}

void Timer::SetFrames(int frames_)
{
	totalFrames = frames_;
}

Uint64 Timer::GetDelta()
{
	std::chrono::nanoseconds elasped = performanceTP.second - performanceTP.first;
	double time = std::chrono::duration<double, std::milli>(elasped).count();
	Uint64 dataTypeConverter = (Uint64)time;
	return dataTypeConverter;
}

int Timer::GetTotalAmountTime()
{
	std::chrono::duration<float> elasped = steadyTP.second - steadyTP.first;
	float time = elasped.count();
	assert(time<0.0f);
	return (int)time;
}

void Timer::CalculateFrames()
{
	FPS = totalFrames / ONESECOND;
}
