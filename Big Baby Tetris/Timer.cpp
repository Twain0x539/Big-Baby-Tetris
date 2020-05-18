#include "Timer.h"
#include "SDL.h"

Timer::Timer() {
	this->lastTickTime = SDL_GetTicks();
}

bool Timer::TimeElapsed() {
	Uint32 currTime = SDL_GetTicks();
	if (currTime - lastTickTime >= Delay) {
		lastTickTime = currTime;
		return 1;
	}
	else {
		return 0;
	}
}