#pragma once
#include "e42motor.h"
#include "n17motor.h"
#include "path.h"
#include "penActuator.h"
#include "point.h"

class ArmController {
public:
	ArmController(CoordinateSystem arm);

	void registerPath(Path& path);
	void setSetpoint(int frame, double phi);
	void stop();
private:
	const CoordinateSystem arm;

	Path path;


	E42Motor rotationMotor;
	N17Motor radiusMotor;
};