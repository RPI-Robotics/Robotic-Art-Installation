#include "../include/path.h"


Path::Path(Point initialPoint) : initialPoint(initialPoint), finalPoint(initialPoint) {
	cumulativeArcLength = 0;
	currentSegmentIndex = 0;
}

void Path::addDrawSegment(Segment* segment) {
	addTravelSegment(segment->getInitialPoint());
	cumulativeArcLength += segment->getArcLength();
	segments.push_back(segment);
	finalPoint = segment->getFinalPoint();
}

void Path::addTravelSegment(Point point) {
	segments.push_back(new VectorSegment(finalPoint, point, true));
	cumulativeArcLength += Point::distanceBetween(finalPoint, point);
	finalPoint = point;
}

void Path::returnToInitialPoint() {
	addTravelSegment(initialPoint);
}

void Path::addWaitSegment() {
	segments.push_back(new WaitSegment(finalPoint, Constants::WAITING_TIME_ARC_LENGTH));
	cumulativeArcLength += Constants::WAITING_TIME_ARC_LENGTH;
}

Segment* Path::segmentAtFrame(int frame) {
	while (frame > segments.at(currentSegmentIndex)->getFinalFrame()) {
		currentSegmentIndex++;
	}
	return segments.at(currentSegmentIndex);
}

bool Path::inMotionAtFrame(int frame) {
	return !segmentAtFrame(frame)->isWaitSegment();
}

Point Path::pointAtFrame(int frame, double phi) {
	Segment* current = segmentAtFrame(frame);
	double t = (double)(frame - current->getInitialFrame()) / (current->getFinalFrame() - current->getInitialFrame());
	return current->calculate(t).asRobotGlobal(phi);
}

bool Path::penActiveAtFrame(int frame) {
	return !segmentAtFrame(frame)->isTravelSegment();
}