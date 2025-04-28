#pragma once
#include "segment.h"

class VectorSegment : public Segment {
public:
	VectorSegment(Point& p0, Point& p1, bool isTravel = false);

	void operator<< (std::ofstream& ostr) const;

	bool isTravelSegment() const { return isTravel; }
	double getArcLength() const { return arcLength; }
private:
	Point calculate(double t) const { return Point::fromGraphicsOriented(x0 + a * t, y0 + b * t); }

	Point p0;
	Point p1;

	bool isTravel;

	double x0;
	double y0;
	double a;
	double b;
	double arcLength;
};