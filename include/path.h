#pragma once
#include "point.h"

class Path {
public:
	Path(Point initialPoint);

	double getCumulativeArcLength() const { return cumulativeArcLength; }

	void addSegment();

private:
	Point initialPoint;
	Point finalPoint;
	double cumulativeArcLength;
};