#pragma once
#include "Shape.h"
#include "SDL.h"
#include "SDL_image.h"
#include "Timer.h"
#include "SDL_mixer.h"
class Game
{
private:
	bool initialized = 0;
	static const int FieldCols = 10;
	static const int FieldRows = 17;
	static const int FieldSize = FieldCols * FieldRows;
	int Field[FieldSize];
	int UserInput;
	bool Alive = 1;
	bool SkipDelay = 0;
	bool Menu = 1;
	bool MusicOn = 1;
	Shape* shape;
	Timer* timer;
	int controlledX = 5;
	int controlledY = 1;
	bool checkRow(int RowNumber);
	void removeRow(int RowNumber);
	void moveDown(int TillRow);
	void showMenu();

//*********************_____________SDL_SECTION_____________*********************//
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* blocks[8];
	SDL_Texture* background;
	SDL_Texture* menu;
	Mix_Music* bgm;
	void switchMusic();

	void LoadTextures();
//*******************************************************************************//
public: 
	bool isNotOver = 1;
	static Game& get_instance() {
		static Game instance;
		return instance;
	}
	void INITIALIZE(); // initialises everything, needs to run before doing anything with game
	int getInput(); // gets keyboard input and saves in UserInput
	void applyInput();
	void doLogic(); // doing game logic using userInput value
	void removeFullRows(); // removes filled rows

	int getRandomNumber(int min, int max);
	void render();

	~Game();
};

