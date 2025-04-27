#pragma once
#include "path.h"
#include <fstream>
#include <vector>

class SegmentContainer {
public:
	static void parseSVG(std::ifstream& istr);
	static std::vector<Path>& generatePaths();

private:
	static std::vector<Path> paths;
};