#include "../include/segmentContainer.h"

std::vector<Path>& SegmentContainer::generatePaths() {
	int assignedSegments = 0;

	for (int i = 0; i < 4; ++i) {
		paths.push_back(Path(Constants::INITIAL_ARM_POINTS.at(i)));
	}

	while (assignedSegments < segments.size()) {
		Path& selectedPath = paths.at(0);
		double estimatedPhi = (selectedPath.getCumulativeArcLength() / Constants::ARM_MAX_SPEED) * Constants::CANVAS_ROTATION_SPEED * 360;


		std::sort(paths.begin(), paths.begin());
	}

	for (Path& path : paths) {
		path.returnToInitialPoint();
	}

	return paths;
}