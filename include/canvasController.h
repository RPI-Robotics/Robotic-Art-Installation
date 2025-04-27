#pragma once
#include "m57motor.h"

class CanvasController {
public:
	CanvasController();

	void start();
	void stop();
	double getPhi();
private:
	M57Motor motor;
};