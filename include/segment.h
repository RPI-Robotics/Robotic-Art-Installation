#pragma once
#include "point.h"
#include <fstream>

const double SEGMENT_LEFT_BOUND = 0.0;
const double SEGMENT_RIGHT_BOUND = 1.0;

class Segment {
public:
	Segment();

	const Point operator() (double t) const { return t < SEGMENT_LEFT_BOUND || t > SEGMENT_RIGHT_BOUND ? Point() : calculate(t); }

	virtual void operator<< (std::ofstream& ostr) const = 0;
private:
	virtual const Point calculate(double t) const = 0;
};