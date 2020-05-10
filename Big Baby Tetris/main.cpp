#include <iostream>   // for temp output
using namespace std;
#include "Game.h"
int main() {
	Game& game = Game::get_instance();
/* while(game.IsNotOver){
		 game.getInput();
		 game.doLogic();
		 game.render();
*/ 
	int* p_Field = game.getField_ptr();
	int FieldX = game.getFieldX();
	int FieldY = game.getFieldY();
	for (int i = 0; i < FieldY; i++) {
		for (int j = 0; j < FieldX; j++) {
			cout << p_Field[j * FieldY + FieldX];
		}
		cout << endl;
	}
	return 0;
}