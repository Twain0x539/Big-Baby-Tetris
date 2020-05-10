#pragma once
class Game
{
private:
	Game();
	int UserInput;
public: 
	static Game& get_instance() {
		static Game instance;
		return instance;
	}
	int getUserInput();
	int DoLogic();
};

