#pragma once
#include "point.h"
#include <fstream>

class Segment {
public:
	Segment() : initialFrame(0), finalFrame(0) {};

	virtual Point calculate(double t) const = 0;

	virtual void print() const = 0;
	virtual bool isTravelSegment() const = 0;
	virtual bool isWaitSegment() const = 0;
	virtual double getArcLength() const = 0;
	virtual Point getInitialPoint() const = 0;
	virtual Point getFinalPoint() const = 0;

	int getInitialFrame() const { return initialFrame; }
	int getFinalFrame() const { return finalFrame; }
	void setInitialFrame(int frame) { initialFrame = frame; }
	void setFinalFrame(int frame) { finalFrame = frame; }
private:
	int initialFrame;
	int finalFrame;
};