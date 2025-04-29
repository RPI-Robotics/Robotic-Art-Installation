#pragma once
#include "point.h"
#include "segment.h"

class Path {
public:
	Path(Point initialPoint);

	double getCumulativeArcLength() const { return cumulativeArcLength; }

	void addSegment(Segment* segment);
	void addWaitingSegment();
	void generateTravelSegment(Point point);
	void returnToInitialPoint();

	bool operator< (const Path& rhs) const { return cumulativeArcLength < rhs.cumulativeArcLength; }
private:
	Point initialPoint;
	Point finalPoint;
	double cumulativeArcLength;
};