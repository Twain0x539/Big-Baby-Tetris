#include <iostream>   // for temp output
using namespace std;
#include "Game.h"
int main(int argc, char* argv[]) {
	Game& game = Game::get_instance();
	game.INITIALIZE();
	int* p_Field = game.getField_ptr();
	int FieldCols = game.getFieldCols();
	int FieldRows = game.getFieldRows();
	while (game.isNotOver) {
		// game.getInput();
		game.doLogic();
		// game.render();
		for (int i = 0; i < FieldRows; i++) {
			for (int j = 0; j < FieldCols; j++) {
				cout << p_Field[FieldCols * i + j];
			}
			cout << endl;
		}
		cout << endl;
		system("CLS");
	}
	return 0;;
}