#pragma once
#include "m57motor.h"

//Canvas rotation speed, in rot/s
static const double CANVAS_ROTATION_SPEED = 0;

class CanvasController {
public:
	CanvasController();

	void start();
	void stop();
	double getPhi();
private:
	M57Motor motor;
};