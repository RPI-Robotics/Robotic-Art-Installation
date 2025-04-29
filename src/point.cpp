#include "../include/point.h"

void Point::print() const {
	std::cout << "(" << x << ", " << y << ") type:" << system;
}