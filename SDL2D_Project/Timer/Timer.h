#ifndef TIMER_H
#define TIMER_H
#include <SDL.h>
#include <assert.h>
#include <iostream>
#include <list>
#include <chrono>
#define ONESECOND 1000.0f //1 second in miliseconds
#define SIXTYFRAMES_PER_SECOND 16.666f // 60FPS in milliseconds 1/60 
#define THIRTYFRAMES_PER_SECOND 33.333f // 30FPS in milliseconds
/*
* 2022/8/16 
* Singleton timer interface.
* -Handles the GameLogic update speed.
* -Has two clocks a performance clock that updates with the ticks of the current machine's processor, in other words really accurate.  
*  Then steady clock is essentally the same as well, the difference is it isn't as accurate. 
* -Best way to thing about it is, There is a very accurate clock, that clocks in its time measurements in ticks, and a not so accurate clock that 
* clocks its measuresments of time in seconds. 
* 
*/
 
const std::string TimeUnit = " ms";
typedef std::chrono::high_resolution_clock PClock;
typedef std::chrono::steady_clock  SClock;
typedef std::chrono::milliseconds ms;
typedef std::chrono::duration<float> fsecs;
typedef std::chrono::steady_clock::time_point S_TimePoint;
typedef std::chrono::high_resolution_clock::time_point P_TimePoint;

class Timer
{
public:
	Timer(const Timer&) = delete;
	Timer(Timer&&) = delete;
	Timer& operator = (const Timer&)=delete;
	Timer& operator = (Timer&&) = delete;
	static Timer* GetInstance();
	///Will Start the Machine timer.
	void Start();
	///Update the SteadyClock
	void UpdateSteadyClock();
	///Update the PerformanceClock
	void UpdatePerformanceClock();
	void IncrementSleepTime();
	double getSleepTime();
	void IncrementFrames();
	///This will set the total system lag if any and make sure that the computer runs at an even 60, or 30 FPS
	void IncrementUpdateLag(double updateLag_);
	double GetUpdateLag();
	///This will set the GameLoop logic speed to whatever you put in the parameters, example is 1F/60FPS = 0.01666S , then convert that to MS. 1 S = 1000MS. 
	void SetLogicLoopSpeed(int FPS_);
	/// Returns the update unit of each frame in MS.
	double getMS_Machine_UpdateFPS();
	/// Returns the change of time of the machine
	double GetDelta();
	///DEBUG TOOLS
	/// Print the time inbetween frames 
	void PrintDelta();
	///Prints out the current FPS the current machine is getting. 
	void PrintFPS();
	/// Print total time since machine has been running in seconds
	void PrintTotalTime();
 private:
	 ///Print all the timer information. 
	void PrintStats();
	bool flag;
	Timer();
	~Timer();
	///This will return the total time between frames in miliseconds
	double CalculateDelta();
	///This will return the total time between frames in seconds
	float CalculateTotalTime();
	static Timer* instance;
	bool SecondsFlag;
	int FPS;
	int totalFrames; 
	float totalTime;
	double delta;
	double updateLag;
	double updateLoopSpeed;
	double FramePerSecondFlag;
	static double timerLimit; 
	std::pair<P_TimePoint, P_TimePoint> performanceTP;
	std::pair<PClock, PClock>performanceClock;
	std::pair<SClock, SClock>steadyClock;
	std::pair<S_TimePoint, S_TimePoint> steadyTP;
};



#endif // !TIMER_HEADER
