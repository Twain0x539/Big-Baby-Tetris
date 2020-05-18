#include "Game.h"
#include <ctime>
#include "Shape.h"
#include "SDL.h"
#include <string>
#include <cstdlib>
#include "Timer.h"
extern enum Sides;


int Game::getInput(){
	SDL_Event event;
	SDL_PollEvent(&event);
	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym) {
		case SDLK_a: InputCaptured = 1; return SDLK_a; break;
		case SDLK_d: InputCaptured = 1; return SDLK_d; break;
		case SDLK_s: InputCaptured = 1; return SDLK_s; break;
		case SDLK_r: InputCaptured = 1; return SDLK_r; break;
		}
	}
	return -1;
	}

void Game::doLogic() {
	static int controlledY = 1;
	static int controlledX = 5;
	if (initialized && Alive) {

		if (!InputCaptured) {
			UserInput = getInput();
		}
			if (!shape->inControl) {
				Alive = shape->generateNew(getRandomNumber(1, 7));
			}
			switch (UserInput) {
			case SDLK_a:
				if (!shape->CollideSide(LEFT)) {
					controlledX--;
				}
				shape->setPos(controlledX, controlledY);
				InputCaptured = 0;
				break;
			case SDLK_d:
				if (!shape->CollideSide(RIGHT)) {
					controlledX++;
				}
				shape->setPos(controlledX, controlledY);
				InputCaptured = 0;
				break;
			case SDLK_s:
				InputCaptured = 0;
				break;
			case SDLK_r:
				InputCaptured = 0;
				break;
			case -1:
				UserInput = 0; break;
			}

		if (timer->TimeElapsed()) {
				controlledY++;
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
	}
	if (Alive == 0) {
		for (int i = 0; i < FieldSize; i++) {
			Field[i] = 0;
		}
		Alive = 1;
	}
}

void Game::INITIALIZE() {
	if (!initialized) {
		for (int i = 0; i < FieldSize; i++) {
			Field[i] = 0;
		}
		if (!shape) {
			shape = new Shape(FieldCols,FieldRows,Field);
		}
		if (!timer) {
			timer = new Timer();
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
	bool FieldCleared = 0;
	while (!FieldCleared) {

	}
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