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
		return event.key.keysym.sym;
	}
	return -1;
	}

void Game::doLogic() {
	if (initialized && Alive) {
			UserInput = getInput();
			if (!shape->inControl) {
				Alive = shape->generateNew(getRandomNumber(1, 7));
			}
			applyInput();
			if (timer->TimeElapsed() || SkipDelay) {
				SkipDelay = 0;
				controlledY++;
				if (!shape->CollideBot()) {
					shape->setPos(controlledX, controlledY);
				}
				else {
					shape->Fix();
					removeFullRows();
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
			shape = new Shape(FieldCols, FieldRows, Field);
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
	int randomNumber = (rand() % (max - min + 1)) + min;
	return randomNumber;
}

void Game::removeFullRows() {
	for (int i = 2; i < FieldRows; i++) {
		if (checkRow(i)) {
			removeRow(i);
		}
	}

	
}

Game::~Game() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(background);
	for (int i = 0; i < 8; i++) {
		SDL_DestroyTexture(blocks[i]);
	}
}

void Game::LoadTextures() {
	SDL_Surface* tmpSurface = IMG_Load("Assets/block0.png");
	blocks[0] = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	 tmpSurface = IMG_Load("Assets/block1.png");
	blocks[1] = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	 tmpSurface = IMG_Load("Assets/block2.png");
	blocks[2] = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	 tmpSurface = IMG_Load("Assets/block3.png");
	blocks[3] = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	 tmpSurface = IMG_Load("Assets/block4.png");
	blocks[4] = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	 tmpSurface = IMG_Load("Assets/block5.png");
	blocks[5] = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	 tmpSurface = IMG_Load("Assets/block6.png");
	blocks[6] = SDL_CreateTextureFromSurface(renderer, tmpSurface); 
	 tmpSurface = IMG_Load("Assets/block7.png");
	blocks[7] = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	tmpSurface = IMG_Load("Assets/background.png");
	background = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	

}

void Game::render() {
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, background, NULL, NULL);
	SDL_Rect dstRect;
	dstRect.w = 63;
	dstRect.h = 63;
	for (int i = 2; i < FieldRows; i++) {
		for (int j = 0; j < FieldCols; j++) {
			dstRect.x = 64 * j;
			dstRect.y = 64 * (i - 2);
			if (Field[FieldCols * i + j] == 0) {
			}
			else if (Field[FieldCols * i + j] == 9) {
				SDL_RenderCopy(renderer, blocks[shape->type], NULL, &dstRect);
			}
			else {
				SDL_RenderCopy(renderer, blocks[Field[FieldCols * i + j]], NULL, &dstRect);
			}
		}
	}
	SDL_RenderPresent(renderer);
}

void Game::removeRow(int RowNumber) {
	for (int k = 0; k < FieldCols; k++) {
		Field[FieldCols * RowNumber + k] = 0;
	}
	moveDown(RowNumber);
}

bool Game::checkRow(int RowNumber) {
	bool Full = 1;
	for (int k = 0; k < FieldCols; k++) {
		if (Field[FieldCols * RowNumber + k] == 0 || Field[FieldCols * RowNumber + k] == 9){
		Full = 0;
}
	}
	return Full;
}

void Game::moveDown(int TillRow) {
	for (int i = TillRow; i >3 ; i--) {
		for (int j = 0; j < FieldCols; j++) {
			Field[FieldCols * i + j] = Field[FieldCols * (i - 1) + j];
		}
	}
	for (int j = 0; j < FieldCols; j++) {
		Field[FieldCols * 2 + j] = 0;
	}
}

void Game::applyInput() {
	switch (UserInput) {
	case SDLK_a:
		if (!shape->CollideSide(LEFT)) {
			controlledX--;
		}
		shape->setPos(controlledX, controlledY);
		break;
	case SDLK_d:
		if (!shape->CollideSide(RIGHT)) {
			controlledX++;
		}
		shape->setPos(controlledX, controlledY);
		break;
	case SDLK_s:
		SkipDelay = 1;
		break;
	case SDLK_r:
		shape->rotate();
		break;
	case SDLK_SPACE:
		while (!shape->CollideBot()) {
			controlledY++;
			shape->setPos(controlledX, controlledY);
		}
		break;
	case -1:
		UserInput = 0; break;
	}
}