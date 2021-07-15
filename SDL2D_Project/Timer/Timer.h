#ifndef TIMER_H
#define TIMER_H
#include <SDL.h>
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

	void Start();
	void UpdateGeneralFrameTicks();
	void UpdatePerformanceTicks();
	float GetDeltaTime() const;
	unsigned int GetSleepTime(unsigned int fps_) const;
	float GetCurrentTicks();
private:
	unsigned int prevTicks, currentTicks;
	bool flag;
	Uint64 prevPerformaceTicks, currentPerformanceTicks;
};

#endif // !TIMER_HEADER
