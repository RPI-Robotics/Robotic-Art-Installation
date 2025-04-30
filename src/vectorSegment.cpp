#include "../include/vectorSegment.h"

VectorSegment::VectorSegment(Point& p0, Point& p1, bool isTravel) : p0(p0), p1(p1), isTravel(isTravel) {
	x0 = p0.getX();
	y0 = p0.getY();
	a = p1.getX() - x0;
	b = p1.getY() - y0;
	arcLength = std::sqrt(a * a + b * b);
};

void VectorSegment::print() const {
	std::cout << "Vector Segment" << std::endl;

	std::cout << "  Point 1: ";
	p0.print();
	std::cout << std::endl;

	std::cout << "  Point 2: ";
	p1.print();
	std::cout << std::endl;
}