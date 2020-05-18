#pragma once
#include <SDL.h>
class Timer
{
	Uint32 lastTickTime;
	Uint32 Delay = 500;
public:
	Timer();
	bool TimeElapsed();

};
