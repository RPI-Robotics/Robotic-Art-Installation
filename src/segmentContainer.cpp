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

	bool padX = spanY > spanX;
	double padding = padX ? (spanY - spanX) / 2 : (spanX - spanY) / 2;
	double conversionFactor = Constants::CANVAS_SIZE / (padX ? spanY : spanX);

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
			double x = std::stod(token.substr(3, token.size() - 1));
			istr >> token;
			double y = std::stod(token.substr(3, token.size() - 1));
			istr >> token;
			double width = std::stod(token.substr(3, token.size() - 1));
			istr >> token;
			double height = std::stod(token.substr(3, token.size() - 3));

			if (padX) {
				x += padding;
			}
			else {
				y += padding;
			}

			Point topLeft = Point::fromGraphicsOriented(x * conversionFactor - (Constants::CANVAS_SIZE / 2), y * conversionFactor - (Constants::CANVAS_SIZE / 2));
			Point topRight = Point::fromGraphicsOriented((x + width) * conversionFactor - (Constants::CANVAS_SIZE / 2), y * conversionFactor - (Constants::CANVAS_SIZE / 2));
			Point bottomLeft = Point::fromGraphicsOriented(x * conversionFactor - (Constants::CANVAS_SIZE / 2), (y + height) * conversionFactor - (Constants::CANVAS_SIZE / 2));
			Point bottomRight = Point::fromGraphicsOriented((x + width) * conversionFactor - (Constants::CANVAS_SIZE / 2), (y + height) * conversionFactor - (Constants::CANVAS_SIZE / 2));

			//Top/bottom segments
			if (topLeft.getX() < 0 && topRight.getX() > 0) {
				Point yIntercept = Point::fromGraphicsOriented(0, topLeft.getY());
				segments.push_back(new VectorSegment(topLeft, yIntercept));
				segments.push_back(new VectorSegment(yIntercept, topRight));

				Point yInterceptBottom = Point::fromGraphicsOriented(0, bottomLeft.getY());
				segments.push_back(new VectorSegment(bottomLeft, yInterceptBottom));
				segments.push_back(new VectorSegment(yInterceptBottom, bottomRight));
			}
			else {
				segments.push_back(new VectorSegment(topLeft, topRight));
				segments.push_back(new VectorSegment(bottomLeft, bottomRight));
			}

			//Side segments
			if (topLeft.getY() > 0 && bottomLeft.getY() < 0) {
				Point xIntercept = Point::fromGraphicsOriented(topLeft.getX(), 0);
				segments.push_back(new VectorSegment(topLeft, xIntercept));
				segments.push_back(new VectorSegment(xIntercept, bottomLeft));

				Point xInterceptRight = Point::fromGraphicsOriented(bottomLeft.getX(), 0);
				segments.push_back(new VectorSegment(topRight, xInterceptRight));
				segments.push_back(new VectorSegment(xInterceptRight, bottomRight));
			}
			else {
				segments.push_back(new VectorSegment(topLeft, bottomLeft));
				segments.push_back(new VectorSegment(topRight, bottomRight));
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