#include "Timer.h"
#include "SDL.h"

Timer::Timer(int FPS) {
	this->FPS = FPS;
	this->frameDelay = 1000 / FPS;
}

bool Timer::TimeElapsed() {
	Uint32 currTime = SDL_GetTicks();
	if ((currTime - lastTickTime) >= frameDelay) {
		lastTickTime = SDL_GetTicks();
		return 1;
	}
	else {
		return 0;
	}
}