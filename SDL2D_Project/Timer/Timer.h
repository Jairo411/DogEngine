#ifndef TIMER_H
#define TIMER_H
#include <SDL.h>
#include <chrono>
#include <assert.h>
#include <iostream>
#define ONESECOND 1000 /// This is exactly one second in milliseconds
/*2021-07-09
This shit over here needs some work.*/
class Timer
{
public:
	Timer(const Timer&) = delete;
	Timer(Timer&&) = delete;
	Timer& operator = (const Timer&)=delete;
	Timer& operator = (Timer&&) = delete;
	/* Old Code*/
	void Start();
	void UpdateSteadyClock();
	void UpdatePerformanceClock();
	[[deprecated("replaced by Uint64 get delta")]]
	float GetDeltaTime() const;
	[[deprecated("replaced")]]
	unsigned int GetSleepTime(unsigned int fps_) const;
	[[deprecated("don't use")]]
	float GetCurrentTicks();
	/*New Code*/
	Timer* GetInstance();
	///Will clamp FPS to whatever It is set too
	void SetFPS(int FrameRatePerSecond_);
	void SetFrames(int frames_);
	/// return current update time, which is the frames per seconds
	void CalculateFrames();
	///This will return the performance timer current delta time in milliseconds
	Uint64 GetDelta();
	///This will return the total seconds the engine has been running at
	int GetTotalAmountTime();
private:
	/* Old Code*/
	unsigned int prevTicks, currentTicks;
	bool flag;
	Uint64 prevPerformaceTicks, currentPerformanceTicks;
	/*New Code*/

	Timer();
	~Timer();

	static Timer* instance;
	int FPS;
	int totalFrames; ///a frame is one draw call
	double FramePerSecondFlag;
	std::pair<std::chrono::high_resolution_clock,std::chrono::high_resolution_clock> performanceClock;
	std::pair<std::chrono::steady_clock,std::chrono::steady_clock> steadyClock;
	std::pair<std::chrono::high_resolution_clock::time_point, std::chrono::high_resolution_clock::time_point> performanceTP;
	std::pair<std::chrono::steady_clock::time_point, std::chrono::steady_clock::time_point> steadyTP;
	
};



#endif // !TIMER_HEADER
