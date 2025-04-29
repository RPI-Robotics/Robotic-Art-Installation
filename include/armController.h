#pragma once
#include "e42motor.h"
#include "n17motor.h"
#include "path.h"
#include "penActuator.h"
#include "point.h"

class ArmController {
public:
	ArmController(CoordinateSystem arm) : arm(arm), actuator(PenActuator(arm)), rotationMotor(E42Motor(arm)), radiusMotor(N17Motor(arm)) {};

	void registerPath(Path& path) { this->path = path; }
	void setSetpoint(int frame, double phi);
	void stop();
private:
	const CoordinateSystem arm;

	Path path;

	PenActuator actuator;
	E42Motor rotationMotor;
	N17Motor radiusMotor;
};