#pragma once

class N17Motor {
public:
	N17Motor(CoordinateSystem arm);

	void setPositionAbsolute(double position);
	void stop();
private:

};