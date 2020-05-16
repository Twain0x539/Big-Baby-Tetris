#include "Game.h"
#include <ctime>
#include "Shape.h"
#include "SDL.h"
#include <string>
#include <cstdlib>

void Game::getInput(){
	SDL_PollEvent(&event);
	if (event.type == SDL_KEYDOWN) {
		UserInput = event.key.keysym.sym;
		}
	}

void Game::doLogic() {
	static int controlledY = 1;
	static int controlledX = 5;
	if (initialized) {

		switch (UserInput) {
		case SDLK_a: controlledX--; break;
		case SDLK_d: controlledX++; break;
		}
		if (!shape->inControl) {
			shape->generateNew(getRandomNumber(1, 7));
		}
		if (!shape->CollideBot()) {
			shape->setPos(controlledX, controlledY);
		}
		else {
			shape->Fix();
			shape->inControl = 0;
			controlledY = 1;
			controlledX = 5;
		}



	}
	UserInput = 0;
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
		window = SDL_CreateWindow("Big Baby Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 960, SDL_WINDOW_SHOWN);
		renderer = SDL_CreateRenderer(window, -1, 0);
		LoadTextures();
		/*--------------------------SDL-----------------------*/
	}
	initialized = 1;
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

void Game::LoadTextures() {
	SDL_Surface* tmpSurface = IMG_Load("Assets/block0.png");
	blocks[0] = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	
}

void Game::render() {
	SDL_RenderClear(renderer);
	SDL_Rect dstRect;
	dstRect.w = 64;
	dstRect.h = 64;
	for (int i = 2; i < FieldRows; i++) {
		for (int j = 0; j < FieldCols; j++) {
			if (Field[FieldCols * i + j] != 0) {
				dstRect.x = 64 * j;
				dstRect.y = 64 * (i-2);
				SDL_RenderCopy(renderer, blocks[0], NULL, &dstRect);
			}
		}
	}
	SDL_RenderPresent(renderer);
}