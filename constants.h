#pragma once

#include "include/point.h"
#include <vector>

namespace Constants {
	//Canvas dimensions, in inches
	static const double CANVAS_SIZE = 20.0;

	//Frame rate in hertz
	static const int FRAME_RATE = 0;

	//Canvas rotation speed, in rot/s
	static const double CANVAS_ROTATION_SPEED = 0;

	//Arm maximum speed, in inches/s
	static const int ARM_MAX_SPEED = 0;

	//Waiting time on segment find fail, in degrees
	static const int WAITING_TIME = 45;

	//Waiting time converted to arc length in inches, for sorting purposed
	static const double WAITING_TIME_ARC_LENGTH = WAITING_TIME / 360 / CANVAS_ROTATION_SPEED / ARM_MAX_SPEED;

	//Initial arm points in graphics oriented coordinates
	static const std::vector<Point> INITIAL_ARM_POINTS = {};
}