#include "Shape.h"

Shape::Shape(int type) {
	this->type = type;
	switch (type) {
	case 1: x1 = 1; y1 = 0; x2 = 1; y2 = 1; x3 = 0; y3 = 1; break;
	case 2:
	}
}

void Shape::rotate() {

}