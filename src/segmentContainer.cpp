#include "../include/segmentContainer.h"

void SegmentContainer::parseSVG(std::ifstream& istr) {
	std::string token = "";

	//Get canvas bounds
	while (token.substr(0, 7) != "viewBox") {
		istr >> token;
	}

	double minX = std::stod(token.substr(token.size() - 1));
	istr >> token;
	double minY = std::stod(token);
	istr >> token;
	double maxX = std::stod(token);
	istr >> token;
	double maxY = std::stod(token.substr(0, token.size() - 1));

	double spanX = maxX - minX;
	double spanY = maxY - minY;

	while (istr >> token) {
		if (token.substr(0, 5) == "<path") {
			while (token.substr(0, 2) != "d=") {
				istr >> token;
			}

		}
		else if (token.substr(0, 5) == "<poly") {
			while (token.substr(0, 7) != "points=") {
				istr >> token;
			}

		}
		else if (token.substr(0, 5) == "<rect") {
			while (token.substr(0, 2) != "x=") {
				istr >> token;
			}

		}
	}
}

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