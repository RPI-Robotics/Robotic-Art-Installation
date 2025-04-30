#pragma once
#include "segment.h"

class WaitSegment : public Segment {
public:
	WaitSegment(Point& p0, double arcLength) : p0(p0), arcLength(arcLength) {};

	void print() const { std::cout << "Wait Segment, duration " << arcLength << std::endl; }

	bool isTravelSegment() const { return true; }
	bool isWaitSegment() const { return true; }
	double getArcLength() const { return arcLength; }
	Point getInitialPoint() const { return p0; }
	Point getFinalPoint() const { return p0; }

private:
	Point calculate(double t) const { return p0; }

	Point p0;

	double arcLength;
};