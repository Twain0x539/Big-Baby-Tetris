#pragma once
class Game
{
private:
	Game();
public: 
	static Game& get_instance() {
		static Game instance;
		return instance;
	}

	int UserInput;
	int getUserInput();
};

