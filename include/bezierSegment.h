#pragma once
#include "segment.h"

class BezierSegment : public Segment {
public:
	BezierSegment(Point& p0, Point& p1, Point& p2, Point& p3) : p0(p0), p1(p1), p2(p2), p3(p3) {};

	void operator<< (std::ofstream& ostr) const;
	bool isTravelSegment() const { return false; }
private:
	Point calculate(double t) const;

	Point p0;
	Point p1;
	Point p2;
	Point p3;
};