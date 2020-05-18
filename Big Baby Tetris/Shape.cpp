#include "Shape.h"
/*
	O = 1;
	I = 2;
	T = 3;
	J = 4;
	L = 5;
	Z = 6;
	S = 7;
*/

bool Shape::generateNew(int type) {
	inControl = 1;
	this->type = type;
	switch (type) {
	case 1: setAln(1, 1, 1, 0, 0, 1); break;
	case 2: setAln(0, -1, 0, 1, 0, 2);  break;
	case 3: setAln(1, 0, -1, 0, 0, 1); break;
	case 4: setAln(-1, 0, 0, -1, 0, -2); break;
	case 5: setAln(1, 0, 0, -1, 0, -2); break;
	case 6: setAln(-1,0,0,1,1,1); break;
	case 7: setAln(-1,1,0,1,1,0); break;
	}
	this->x = 5;
	this->y = 1;
	this->x1 = x + Alnx1;
	this->x2 = x + Alnx2;
	this->x3 = x + Alnx3;
	this->y1 = y + Alny1;
	this->y2 = y + Alny2;
	this->y3 = y + Alny3;
	if (Field[FieldCols * y + x] != 0 || Field[FieldCols * y1 + x1] != 0 || Field[FieldCols * y2 + x2] != 0 || Field[FieldCols * y3 + x3] != 0)
	{
		return 0;
	}
	else {
		Field[FieldCols * this->y + this->x] = 9;
		Field[FieldCols * y1 + x1] = 9;
		Field[FieldCols * y2 + x2] = 9;
		Field[FieldCols * y3 + x3] = 9;
		inControl = true;
		return 1;
	}
}

void Shape::rotate() {

/*
 Вращение вокруг центра
 X = -y
 Y = x
 */
	int NewX1Aln = Alny1 * -1;
	int NewY1Aln = Alnx1;
	int NewX2Aln = Alny2 * -1;
	int NewY2Aln = Alnx2;
	int NewX3Aln = Alny3 * -1;
	int NewY3Aln = Alnx3;
	setAln(NewX1Aln, NewY1Aln, NewX2Aln, NewY2Aln, NewX3Aln, NewY3Aln);
	setPos(x, y);

}

void Shape::setAln(int x1, int y1, int x2, int y2, int x3, int y3) {
	this->Alnx1 = x1;
	this->Alny1 = y1;
	this->Alnx2 = x2;
	this->Alny2 = y2;
	this->Alnx3 = x3;
	this->Alny3 = y3;
}

void Shape::removeOldPos() {
	Field[FieldCols * this->y + this->x] = 0;
	Field[FieldCols * y1 + x1] = 0;
	Field[FieldCols * y2 + x2] = 0;
	Field[FieldCols * y3 + x3] = 0;
}
void Shape::setPos(int x, int y) {
	removeOldPos();
	this->x = x;
	this->y = y;
	this->x1 = x + Alnx1;
	this->x2 = x + Alnx2;
	this->x3 = x + Alnx3;
	this->y1 = y + Alny1;
	this->y2 = y + Alny2;
	this->y3 = y + Alny3;
	Field[FieldCols * this->y + this->x] = 9;
	Field[FieldCols * y1 + x1] = 9;
	Field[FieldCols * y2 + x2] = 9;
	Field[FieldCols * y3 + x3] = 9;
}

Shape::Shape(int FieldCols, int FieldRows, int* p_Field) {
	inControl = 0;
	x = 0;
	y = 0;
	x1 = 0;
	x2 = 0;
	x3 = 0;
	y1 = 0;
	y2 = 0;
	y3 = 0;
	this->FieldCols = FieldCols;
	this->FieldRows = FieldRows;
	this->Field = p_Field;
}

bool Shape::CollideBot() {
	bool Collide = 0;

	if ((y+1) == FieldRows || (y1+1) == FieldRows || (y2+1) == FieldRows || (y3+1) == FieldRows) {
		Collide = 1;
	}
	if (Field[FieldCols * (y + 1) + x] != 0 && Field[FieldCols * (y + 1) + x] != 9) {
		Collide = 1;
	}
	if (Field[FieldCols * (y1 + 1) + x1] != 0 && Field[FieldCols * (y1 + 1) + x1] != 9) {
		Collide = 1;
	}
	if (Field[FieldCols * (y2 + 1) + x2] != 0 && Field[FieldCols * (y2 + 1) + x2] != 9) {
		Collide = 1;
	}
	if (Field[FieldCols * (y3 + 1) + x3] != 0 && Field[FieldCols * (y3 + 1) + x3] != 9) {
		Collide = 1;
	}
	return Collide;
}

void Shape::Fix() {
	Field[FieldCols * y + x] = type;
	Field[FieldCols * y1 + x1] = type;
	Field[FieldCols * y2 + x2] = type;
	Field[FieldCols * y3 + x3] = type;
}

bool Shape::CollideSide(Sides side) {
	bool Collide = 0;
	switch (side) {
	case LEFT:
		if (x - 1 < 0 || x1 - 1 < 0 || x2 - 1 < 0 || x3 - 1 < 0) {
			Collide = 1;;
		}
		if (Field[FieldCols * y + (x-1)] != 0 && Field[FieldCols * y + (x - 1)] != 9) {
			Collide = 1;
		}
		if (Field[FieldCols * y1 + (x1 - 1)] != 0 && Field[FieldCols * y1 + (x1 - 1)] != 9) {
			Collide = 1;
		}
		if (Field[FieldCols * y2 + (x2 - 1)] != 0 && Field[FieldCols * y2 + (x2 - 1)] != 9) {
			Collide = 1;
		}
		if (Field[FieldCols * y3 + (x3 - 1)] != 0 && Field[FieldCols * y3 + (x3 - 1)] != 9) {
			Collide = 1;
		}
		break;
	case RIGHT:
		if (x + 1 >= FieldCols || x1 + 1 >= FieldCols || x2 + 1 >= FieldCols || x3 + 1 >= FieldCols) {
			Collide = 1;
		}
		if (Field[FieldCols * y + (x + 1)] != 0 && Field[FieldCols * y + (x + 1)] != 9) {
			Collide = 1;
		}
		if (Field[FieldCols * y1 + (x1 + 1)] != 0 && Field[FieldCols * y1 + (x1 + 1)] != 9) {
			Collide = 1;
		}
		if (Field[FieldCols * y2 + (x2 + 1)] != 0 && Field[FieldCols * y2 + (x2 + 1)] != 9) {
			Collide = 1;
		}
		if (Field[FieldCols * y3 + (x3 + 1)] != 0 && Field[FieldCols * y3 + (x3 + 1)] != 9) {
			Collide = 1;
		}
		break;
	}
	return Collide;
}