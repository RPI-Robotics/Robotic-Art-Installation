#include "../include/segmentContainer.h"

std::vector<Path>& SegmentContainer::generatePaths() {
	for (int i = 0; i < 4; ++i) {
		paths.push_back(Path(Constants::INITIAL_ARM_POINTS.at(i)));
	}

	while () {
		Path& selectedPath = paths.at(0);
		double estimatedPhi = (selectedPath.getCumulativeArcLength() / Constants::ARM_MAX_SPEED) * Constants::CANVAS_ROTATION_SPEED * 360;

	}

	return paths;
}