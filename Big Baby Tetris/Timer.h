#pragma once
#include <SDL.h>
class Timer
{
	int frameDelay;
	int FPS;
	Uint32 lastTickTime = SDL_GetTicks();
public:
	Timer(int FPS);
	bool TimeElapsed();

};

