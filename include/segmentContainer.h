#pragma once
#include "../constants.h"
#include "BVHNode.h"
#include "path.h"
#include "segment.h"
#include <algorithm>
#include <fstream>
#include <vector>

class SegmentContainer {
public:
	static void parseSVG(std::ifstream& istr);
	static std::vector<Path>& generatePaths();

private:
	static int assignedSegments;

	static std::vector<Path> paths;
	static std::vector<Segment*> segments;
	static BVHNode* tree;
};