#pragma once

//Frame rate in hertz
static const int FRAME_RATE = 0;

class TimingUtility {
public:
	TimingUtility();

	int getFrame();
	bool intervalComplete();
private:
	int currentFrame;
	int finalFrame;
};