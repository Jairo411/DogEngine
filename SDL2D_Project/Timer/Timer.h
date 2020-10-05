#ifndef TIMER_HEADER
#define TIMER_HEADER
#include <SDL.h>
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
