#pragma once

class TimingUtility {
public:
	TimingUtility();

	int getFrame();
	bool intervalComplete();
private:
	int currentFrame;
	int finalFrame;
};