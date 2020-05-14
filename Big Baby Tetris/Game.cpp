#include "Game.h"
#include <ctime>
#include "Shape.h"
#include "SDL.h"
#include <cstdlib>

void Game::getUserInput(){
	SDL_PollEvent(&event);
	if (event.type == SDL_KEYDOWN) {
		UserInput = event.key.keysym.sym;
		}
	}

void Game::doLogic() {
	static int controlledY = 1;
	if (initialized) {
		if (!shape->inControl) {
			shape->generateNew(getRandomNumber(1, 7));
			shape->inControl = true;
		}
		if (!shape->CollideBot()) {
			shape->removeOldPos();
			shape->setPos(5, controlledY);
		}
		else {
			shape->Fix();
			shape->inControl = 0;
			controlledY = 1;
		}
	}
	controlledY++;
	SDL_Delay(100);
}

void Game::INITIALIZE() {
	if (!initialized) {
		for (int i = 0; i < FieldSize; i++) {
			Field[i] = 0;
		}
		if (!shape) {
			shape = new Shape(FieldCols,FieldRows,Field);
		}


		/*--------------------------SDL-----------------------*/

		SDL_Init(SDL_INIT_EVERYTHING);
		window = SDL_CreateWindow("Big Baby Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
		renderer = SDL_CreateRenderer(window, -1, 0);

		/*--------------------------SDL-----------------------*/
	}
	initialized = 1;
}

int* Game::getField_ptr() {
	return Field;
}

int Game::getRandomNumber(int min, int max) {
	std::srand(time(NULL));
	int randomNumber = (rand() % (max - min)) + min;
	return randomNumber;
}

void Game::removeFullRows() {
	
}

Game::~Game() { 
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}