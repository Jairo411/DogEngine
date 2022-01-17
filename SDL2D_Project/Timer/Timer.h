#ifndef TIMER_H
#define TIMER_H
#include <SDL.h>
#include <chrono>
#include <assert.h>
#include <iostream>
#include <list>
#define ONESECOND 1000 /// This is exactly one second in milliseconds
#define SIXTYFRAMES_PER_SECOND 16.666 // 60FPS in milliseconds 1/60 
#define THIRTYFRAMES_PER_SECOND 33.333 // 30FPS in milliseconds
/*2022-01-07
Happy New Year ! 
Well just to inform you overhere, you having been working them the same time units in your timer.
Thanks to how smart you've gotten. You've been actually able to figure out wtf is going on. For future reference 
when you're doing any kind of math, MAKE SURE, I CAN'T STRESS THIS ENOUGH, MAKE SURE YOU ARE USING THE CORRECT UNITS. 
AS WELL MAKE SURE THAT YOU'RE USING THE CORRECT MATH.

I'm not being dramatic this could cause so many future problems if you do not take into account if your math is soild. 

2022-01-09
The math is soild but because of floating point errors, ill switch the units of time from seconds to miliseconds. 
*/
struct LocalTimer
{
	double timerLimit = 0.0;
	std::pair<std::chrono::steady_clock, std::chrono::steady_clock::time_point> LocalTimerPair;
};

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
	///This will set the GameLoop logic speed to whatever you put in the parameters, example is 1F/60FPS = 0.01666S , then convert that to MS. 1 S = 1000MS. 
	void SetLogicLoopSpeed(int FPS_);
	/// Returns the update unit of each frame in MS.
	double getMS_Machine_UpdateFPS();
	/// Returns the change of time of the machine 
	double GetDelta();
	///This will return the total seconds the engine has been running at
	int GetTotalAmountTime();
	///Will add my local timer structure to my list of local timers
	static void AddLocalTimer(LocalTimer local_);
	///Will just simply start the timer at the end of the list 
	static void StartTimer();
	///Can Pass the localTimer directly 
	static void StartTimer(LocalTimer local_);
	///Remember when working with std::chrono::<insert time variable here> that you know exactly what unit of time you are working in, i.e secs, millisecs,mircosecs 
	static void SetTimer(std::chrono::milliseconds milli_);
	///Remember when working with std::chrono::<insert time variable here> that you know exactly what unit of time you are working in, i.e secs, millisecs,mircosecs 
	static void SetTimer(std::chrono::seconds secs_);
	///get the Current local Timer flag
	static bool getCurrentLocalTimerFlag();
	///Update all local timers
	static void UpdateAllLocalTimers();
	/// Print Update
	void PrintUpdate();
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
	bool SecondsFlag;
	int FPS;
	int totalFrames; ///a frame is one draw call
	double delta;
	double updateLag;
	double thresHold;
	double updateLoopSpeed;
	double FramePerSecondFlag;
	static double timerLimit;
	static LocalTimer* currentLocaltimerPtr;
	static std::list<LocalTimer*>localTimersContainer;
	static std::pair<std::chrono::steady_clock, std::chrono::steady_clock::time_point> timer;
	std::pair<std::chrono::high_resolution_clock,std::chrono::high_resolution_clock> performanceClock;
	std::pair<std::chrono::steady_clock,std::chrono::steady_clock> steadyClock;
	std::pair<std::chrono::high_resolution_clock::time_point, std::chrono::high_resolution_clock::time_point> performanceTP;
	std::pair<std::chrono::steady_clock::time_point, std::chrono::steady_clock::time_point> steadyTP;
};



#endif // !TIMER_HEADER
