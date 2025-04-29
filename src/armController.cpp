#pragma once
#include "../include/armController.h"

void ArmController::setSetpoint(int frame, double phi) {
	if (!path.inMotionAtFrame(frame)) {
		stop();
		actuator.liftPen();
		return;
	}

	Point setpoint = path.pointAtFrame(frame, phi).asSystem(arm);

	rotationMotor.setPositionAbsolute(setpoint.getTheta());
	radiusMotor.setPositionAbsolute(setpoint.getR());

	if (path.penActiveAtFrame(frame)) {
		actuator.dropPen();
	}
	else {
		actuator.liftPen();
	}
}

void ArmController::stop() {
	rotationMotor.stop();
	radiusMotor.stop();
}