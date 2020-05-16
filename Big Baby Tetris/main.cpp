using namespace std;
#include "Game.h"
int main(int argc, char* argv[]) {
	Game& game = Game::get_instance();
	game.INITIALIZE();
	while (game.isNotOver) {
		game.getInput();
		game.doLogic();
		game.render();
	}
	return 0;
}