#include "Timer.h"
#define MILLISECONDS_TO_SECONDS /1000.0f 

Timer::Timer()
{
	prevTicks = 0;
	currentTicks = 0;
	prevPerformaceTicks = 0;
	currentPerformanceTicks = 0;
}

void Timer::Start()
{
	prevTicks = SDL_GetTicks();
	currentTicks = SDL_GetTicks();
}

void Timer::UpdateGeneralFrameTicks()
{
	prevTicks = currentTicks;
	currentTicks = SDL_GetTicks();
}

void Timer::UpdatePerformanceTicks()
{
	
 	
}

float Timer::GetDeltaTime() const
{
	return static_cast<float>(currentTicks - prevTicks) MILLISECONDS_TO_SECONDS;
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
