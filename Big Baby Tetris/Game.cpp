#include "Game.h"
#include <ctime>
#include "Shape.h"
#include <SDL.h>
#include <cstdlib>

void Game::getUserInput(){
int input = 0;
UserInput = input;
}

void Game::doLogic() {
	static int i = 1;
	if (initialized) {
		if (!shape->inControl) {
			shape->generateNew(getRandomNumber(1, 7));
			shape->inControl = true;
		}
		if (!shape->CollideBot()) {
			shape->removeOldPos();
			shape->setPos(5, i);
		}
		else {
			shape->Fix();
			shape->inControl = 0;
			i = 1;
		}
	}
	i++;
}

void Game::INITIALIZE() {
	if (!initialized) {
		for (int i = 0; i < FieldSize; i++) {
			Field[i] = 0;
		}
		if (!shape) {
			shape = new Shape(FieldCols,FieldRows,Field);
		}
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