#include "../constants.h"
#include "../include/point.h"

void Point::print() const {
	std::cout << "(" << x << ", " << y << ") type:" << system;
}

double Point::getR() {
	if (!polar) {
		r = std::sqrt(x * x + y * y);
		polar = true;
	}
	return r;
}

double Point::getTheta() {
	if (!polar) {
		theta = std::atan(x / y) * 180 / M_PI;
		polar = true;
	}
	return theta;
}

double Point::distanceBetween(Point& p0, Point& p1) {
	return std::sqrt((p0.getX() - p1.getX()) * (p0.getX() - p1.getX()) + (p0.getY() - p1.getY()) * (p0.getY() - p1.getY()));
}

Point Point::asRobotGlobal(double phi) {
	phi *= M_PI / 180;
	switch (system) {
	case GRAPHICS_ORIENTED:
		return Point(x * std::cos(phi) + y * std::cos(phi + M_PI / 2), x * std::sin(phi) + y * std::sin(phi + M_PI / 2), ROBOT_GLOBAL);
	case ROBOT_GLOBAL:
		//TODO: add conversions for arms if needed
	case ARM_I:
	case ARM_II:
	case ARM_III:
	case ARM_IV:
	default:
		return Point(x, y, ROBOT_GLOBAL);
	}
}

Point Point::asArm(CoordinateSystem arm) {
	switch (system) {
	case ROBOT_GLOBAL:
		switch (arm) {
		case ARM_I:
			return Point(-(Constants::CANVAS_SIZE / 2 - x), -(Constants::CANVAS_SIZE / 2 - y), ARM_I);
		case ARM_II:
			return Point(-(Constants::CANVAS_SIZE / 2 - y), (Constants::CANVAS_SIZE / 2 + x), ARM_II);
		case ARM_III:
			return Point((Constants::CANVAS_SIZE / 2 + x), (Constants::CANVAS_SIZE / 2 + y), ARM_III);
		case ARM_IV:
			return Point((Constants::CANVAS_SIZE / 2 + y), -(Constants::CANVAS_SIZE / 2 - x), ARM_IV);
			//TODO: add conversions for other systems if needed
		case GRAPHICS_ORIENTED:
		case ROBOT_GLOBAL:
			return Point(x, y, ROBOT_GLOBAL);
		}
		//TODO: add conversions for other systems if needed
	case GRAPHICS_ORIENTED:
	case ARM_I:
	case ARM_II:
	case ARM_III:
	case ARM_IV:
	default:
		return Point(x, y, ROBOT_GLOBAL);
	}
}

Point Point::fromRobotGlobal(double x, double y) {
	return Point(x, y, ROBOT_GLOBAL);
}

Point Point::fromGraphicsOriented(double x, double y) {
	return Point(x, y, GRAPHICS_ORIENTED);
}

Point Point::withCoordinateSystem(double x, double y, CoordinateSystem system) {
	return Point(x, y, system);
}