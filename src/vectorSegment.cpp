#include "../include/vectorSegment.h"
#include <cmath>

VectorSegment::VectorSegment(Point& p0, Point& p1, bool isTravel = false) : p0(p0), p1(p1), isTravel(isTravel) {
	x0 = p0.getX();
	y0 = p0.getY();
	a = p1.getX() - x0;
	b = p1.getY() - y0;
	arcLength = std::sqrt(a * a - b * b);
};