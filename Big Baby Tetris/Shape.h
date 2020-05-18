#pragma once
enum Sides {
	LEFT,
	RIGHT
};
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
protected:
	int FieldCols;
	int FieldRows;
	int* Field;
	void setAln(int x1, int y1, int x2, int y2, int x3, int y3);

	int x, y; // Center piece pos

	int Alnx1, Alny1;
	int Alnx2, Alny2;
	int Alnx3, Alny3;

	int x1, y1; 
	int x2, y2;
	int x3, y3;

public:
	int type;
	bool inControl = 0;
	Shape(int FieldCols, int FieldRows, int* p_Field);
	void rotate();
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	bool generateNew(int type);
	void setPos(int x, int y);
	bool CollideBot();
	bool CollideSide(Sides side);
	void Fix();
	void removeOldPos();

	int gx() {
		return x;
	}
	int gx1() {
		return x1;
	}
	int gx2() {
		return x2;
	}
	int gx3() {
		return x3;
	}
	int gy() {
		return y;
	}
	int gy1() {
		return y1;
	}
	int gy2() {
		return y2;
	}
	int gy3() {
		return y3;
	}
};

