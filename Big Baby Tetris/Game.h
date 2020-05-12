#pragma once
#include "Shape.h"
class Game
{
private:
	bool initialized = 0;
	static const int FieldCols = 10;
	static const int FieldRows = 17;
	static const int FieldSize = FieldCols * FieldRows;
	int Field[FieldSize];
	int UserInput;
	Shape* shape;

//*********************_____________SDL_SECTION_____________*********************//





//*******************************************************************************//
public: 
	bool isNotOver = 1;
	static Game& get_instance() {
		static Game instance;
		return instance;
	}

	int* getField_ptr();
	int getFieldSize() {
		return FieldSize;
	}
	int getFieldCols() {
		return FieldCols;
	}
	int getFieldRows() {
		return FieldRows;
	}
	void INITIALIZE(); // initialises everything, needs to run before doing anything with game
	void getUserInput(); // gets keyboard input and saves in UserInput
	void doLogic(); // doing game logic using userInput value

	int getRandomNumber(int min, int max); // return random integer value in range min...max
};

