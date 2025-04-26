#pragma once
#include "segment.h"

class VectorSegment : public Segment {
public:
	VectorSegment(Point& p0, Point& p1, bool isTravel = false) : p0(p0), p1(p1), isTravel(isTravel) {};

	void operator<< (std::ofstream& ostr) const;
private:
	const Point calculate(double t) const;

	Point p0;
	Point p1;

	bool isTravel;
};