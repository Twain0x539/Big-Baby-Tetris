#pragma once
class Game
{
private:
	static const int FieldX = 15;
	static const int FieldY = 10;
	static const int FieldSize = FieldX * FieldY;
	bool pieceHolds = 0;
	int Field[FieldSize];
	int UserInput;
public: 
	static Game& get_instance() {
		static Game instance;
		return instance;
	}
	int* getField_ptr();
	int getFieldSize() {
		return FieldSize;
	}
	int getFieldX() {
		return FieldX;
	}
	int getFieldY() {
		return FieldY;
	}
	void INITIALIZE();
	void getUserInput();
	void DoLogic();

	int getRandomNumber(int min, int max);
};

