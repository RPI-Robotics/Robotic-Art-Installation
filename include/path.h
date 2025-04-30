#pragma once
#include "constants.h"
#include "point.h"
#include "segment.h"
#include "vectorSegment.h"
#include "waitSegment.h"
#include <vector>

class Path {
public:
	Path(Point initialPoint);

	double getCumulativeArcLength() const { return cumulativeArcLength; }

	void addDrawSegment(Segment* segment);
	void addTravelSegment(Point point);
	void returnToInitialPoint();
	void addWaitSegment();

	bool inMotionAtFrame(int frame);
	Point pointAtFrame(int frame, double phi);
	bool penActiveAtFrame(int frame);

	bool operator< (const Path& rhs) const { return cumulativeArcLength < rhs.cumulativeArcLength; }
private:
	Segment* segmentAtFrame(int frame);

	Point initialPoint;
	Point finalPoint;
	double cumulativeArcLength;

	int currentSegmentIndex;
	std::vector<Segment*> segments;
};