#include "Shape.h"
/*
	O = 0;
	I = 1;
	T = 3;
	J = 4;
	L = 5;
	Z = 6;
	S = 7;
*/

void Shape::generateNew(int type) {
	inControl = 1;
	x = 0;
	y = 0;
	this->type = type;
	switch (type) {
	case 1: setAln(1, 1, 1, 0, 0, 1); break;
	case 2: setAln(0, -1, 0, 1, 0, 2);  break;
	case 3: setAln(1, 0, -1, 0, 0, 1); break;
	case 4: setAln(-1, 0, 0, 1, 0, 2); break;
	case 5: setAln(1, 0, 0, 1, 0, 2); break;
	case 6: setAln(-1, 0, 0, 1, 1, 1); break;
	case 7: setAln(-1, -1, 0, -1, 1, 0); break;
	}
}

void Shape::rotate() {

}

void Shape::setAln(int x1, int y1, int x2, int y2, int x3, int y3) {
	this->Alnx1 = x1;
	this->Alny1 = y1;
	this->Alnx2 = x2;
	this->Alny2 = y2;
	this->Alnx3 = x3;
	this->Alny3 = y1;
}

void Shape::setPos(int x, int y) {
	
	if (x >= FieldCols) {
		this->x = 0;
	}
	else {
		this->x = x;
	}
	if (y >= FieldRows) {
		this->y = 0;
	}
	else {
		this->y = y;
	}
	this->x1 = x + Alnx1;
	this->x2 = x + Alnx2;
	this->x3 = x + Alnx3;
	this->y1 = y + Alny1;
	this->y2 = y + Alny2;
	this->y3 = y + Alny3;
	Field[FieldRows * this->y + this->x] = type;
	Field[FieldRows * y1 + x1] = type;
	Field[FieldRows * y2 + x2] = type;
	Field[FieldRows * y3 + x3] = type;
}

Shape::Shape(int FieldCols, int FieldRows, int* p_Field) {
	inControl = 0;
	x = 0;
	y = 0;
	this->FieldCols = FieldCols;
	this->FieldRows = FieldRows;
	this->Field = p_Field;
}