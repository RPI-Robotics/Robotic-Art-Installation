#pragma once
#include "point.h"
#include <fstream>

class Segment {
public:
	Segment();

	const Point operator() (double t) const { return t < 0.0 || t > 1.0 ? Point() : calculate(t); }

	virtual void operator<< (std::ofstream& ostr) const = 0;
private:
	virtual const Point calculate(double t) const = 0;
};