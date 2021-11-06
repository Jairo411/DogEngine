#ifndef TIMER_H
#define TIMER_H
#include <SDL.h>
#include <chrono>
#include <assert.h>
#include <iostream>
#define ONESECOND 1000 /// This is exactly one second in milliseconds
#define SIXTYFRAMES_PER_SECOND 16.666 // 60FPS in milliseconds 1/60 
#define THIRTYFRAMES_PER_SECOND 33.333 // 30FPS in milliseconds
/*2021-07-09
This shit over here needs some work.
2021-11-01
Did the work.
*/

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
//	[[deprecated("replaced")]]
//	unsigned int GetSleepTime(unsigned int fps_) const;
//	[[deprecated("don't use")]]
	float GetCurrentTicks();
	/*New Code*/
	static Timer* GetInstance();
	void IncrementSleepTime();
	double getSleepTime();
	void IncrementFrames();
	void PrintFPS();
	///This will set the total system lag if any and make sure that the computer runs at an even 60, or 30 FPS
	void IncrementUpdateLag(double updateLag_);
	double GetUpdateLag();
	///This will set the machine loop speed rate in milliseconds, in relation to frameRate 1/60 = 0.0166*1000 to convert to milliseconds = 16.6
	void SetLogicLoopSpeed(int FPS_);
	double getMS_Machine_Update();
	///This will return the performance timer current delta time in milliseconds
	double GetDelta();
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
	double CalculateDelta();
	static Timer* instance;
	int FPS;
	int totalFrames; ///a frame is one draw call
	double delta;
	double updateLag;
	double thresHold;
	double updateLoopSpeed;
	double FramePerSecondFlag;
	std::pair<std::chrono::high_resolution_clock,std::chrono::high_resolution_clock> performanceClock;
	std::pair<std::chrono::steady_clock,std::chrono::steady_clock> steadyClock;
	std::pair<std::chrono::high_resolution_clock::time_point, std::chrono::high_resolution_clock::time_point> performanceTP;
	std::pair<std::chrono::steady_clock::time_point, std::chrono::steady_clock::time_point> steadyTP;
};



#endif // !TIMER_HEADER
