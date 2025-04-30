#pragma once
#include "segment.h"
#include <cmath>
#include <iostream>

class VectorSegment : public Segment {
public:
	VectorSegment(Point& p0, Point& p1, bool isTravel = false);

	Point calculate(double t) const { return Point::fromGraphicsOriented(x0 + a * t, y0 + b * t); }

	void print() const;

	bool isTravelSegment() const { return isTravel; }
	bool isWaitSegment() const { return false; }
	double getArcLength() const { return arcLength; }
	Point getInitialPoint() const { return p0; }
	Point getFinalPoint() const { return p1; }
private:
	Point p0;
	Point p1;

	bool isTravel;

	double x0;
	double y0;
	double a;
	double b;
	double arcLength;
};