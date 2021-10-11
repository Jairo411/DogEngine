#ifndef TIMER_H
#define TIMER_H
#include <SDL.h>
#include <chrono>
/*2021-07-09
This shit over here needs some work.*/
class Timer
{
public:
	Timer(const Timer&) = delete;
	Timer(Timer&&) = delete;
	Timer& operator = (const Timer&)=delete;
	Timer& operator = (Timer&&) = delete;
	Timer();
	/* Old Code*/
	void Start();
	void UpdateGeneralFrameTicks();
	void UpdatePerformanceTicks();
	float GetDeltaTime() const;
	unsigned int GetSleepTime(unsigned int fps_) const;
	float GetCurrentTicks();
	/*New Code*/
	Uint64 GetCurrentPerformanceMiliSeconds();
	float GetCurrentSteadySeconds();
private:
	/* Old Code*/
	unsigned int prevTicks, currentTicks;
	bool flag;
	Uint64 prevPerformaceTicks, currentPerformanceTicks;

	/*New Code*/
	std::chrono::high_resolution_clock masterPerformanceClock;
	std::chrono::steady_clock masterSteadyClock;
	//For the High Resoultion Clock
	std::chrono::high_resolution_clock::time_point performanceTP1,performanceTP2;
	//For the Steady Clock
	std::chrono::steady_clock::time_point steadyTP1, steadyTP2;
	
};

#endif // !TIMER_HEADER
