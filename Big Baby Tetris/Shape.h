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
	void setAln(int x1, int y1, int x2, int y2, int x3, int y3);
	Shape(int type);

	int x, y; // Center piece pos

	int Alnx1, Alny1;
	int Alnx2, Alny2;
	int Alnx3, Alny3;

	int x1, y1; 
	int x2, y2;
	int x3, y3;

public:
	void rotate();
	void setPos(int x, int y);
};

