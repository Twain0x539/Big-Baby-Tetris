#include <iostream>   // for temp output
using namespace std;
#include "Game.h"
int main() {
	Game& game = Game::get_instance();
	game.INITIALIZE();
	int* p_Field = game.getField_ptr();
	int FieldCols = game.getFieldCols();
	int FieldRows = game.getFieldRows();
	while (game.isNotOver) {
		// game.getInput();
		game.doLogic();
		// game.render();
		for (int i = 0; i < FieldCols; i++) {
			for (int j = 0; j < FieldRows; j++) {
				cout << p_Field[FieldRows * i + j];
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}