#pragma once

/*
	O = 0;
	I = 1;
	T = 3;
	J = 4;
	L = 5;
	Z = 6;
	S = 7;
*/



class Shape
{
private: 
	int type;

	Shape(int type) {
		this->type = type;
		switch (type) {
		}
	}

	int x, y; // Center piece pos

/*		Additional pieces positions, changing only by rotate() function		*/
	int x1, y1; 
	int x2, y2;
	int x3, y3;

public:
	void rotate();
};

