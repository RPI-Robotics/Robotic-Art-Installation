#pragma once
#include "segment.h"
#include <vector>

class BVHNode {
public:
	BVHNode(int levelsRemaining, BVHNode* parent, double x0, double xf, double y0, double yf, std::vector<Segment*> segments);

private:
	int levelsRemaining; //Desired tree height minus level

	BVHNode* left;
	BVHNode* right;
	BVHNode* parent;

	double xMin;
	double xMax;

	double yMin;
	double yMax;

	std::vector<Segment*> segments;
};