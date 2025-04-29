#pragma once

class M57Motor {
public:
	M57Motor();

	void setVelocity(double velocity);
	void stop();
	double readEncoder();
private:

};