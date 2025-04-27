#include "../include/BVHNode.h"

BVHNode::BVHNode(int levelsRemaining, BVHNode* parent, double x0, double xf, double y0, double yf, std::vector<Segment*> segments) : parent(parent), xMin(x0), xMax(xf), yMin(y0), yMax(yf), segments(segments) {
	if (levelsRemaining <= 0) {
		left = nullptr;
		right = nullptr;
	}
	else if (levelsRemaining % 2 == 0) {
		//left = BVHNode(levelsRemaining - 1, this, x0, xf / 2, y0, yf, segments);
	}
	else {

	}

}
