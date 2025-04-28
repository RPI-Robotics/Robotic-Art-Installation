#pragma once
#include "armController.h"
#include "canvasController.h"
#include "timingUtility.h"
#include <vector>

class HardwareContainer {
public:
	static void initializeHardware();
	static void registerPaths(std::vector<Path>& paths);
	static void execute();
	static void stop();

private:
	static std::vector<ArmController> armControllers;
	static CanvasController canvasController;
	static TimingUtility timingUtility;
};