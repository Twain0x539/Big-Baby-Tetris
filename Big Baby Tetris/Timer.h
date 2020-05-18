#pragma once
#include <SDL.h>
class Timer
{
	Uint32 lastTickTime;
	Uint32 Delay = 700;
public:
	Timer();
	bool TimeElapsed();

};
