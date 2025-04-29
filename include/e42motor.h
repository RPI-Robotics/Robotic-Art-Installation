#pragma once

class E42Motor {
public:
	E42Motor(CoordinateSystem arm);

	void setPositionAbsolute(double position);
	void stop();
private:

};