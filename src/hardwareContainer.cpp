#include "../include/hardwareContainer.h"

void HardwareContainer::initializeHardware() {
	for (int i = 0; i < 4; ++i) {
		armControllers.push_back(ArmController((CoordinateSystem)(i + 2)));
	}
	canvasController = CanvasController();
	timingUtility = TimingUtility();
}

void HardwareContainer::registerPaths(std::vector<Path>& paths) {
	for (int i = 0; i < 4; ++i) {
		armControllers.at(i).registerPath(paths.at(i));
	}
}

void HardwareContainer::execute() {
	canvasController.start();

	while (!timingUtility.intervalComplete()) {
		double canvasPhi = canvasController.getPhi();
		for (ArmController& arm : armControllers) {
			arm.setSetpoint(timingUtility.getFrame(), canvasPhi);
		}
	}

	stop();
}

void HardwareContainer::stop() {
	canvasController.stop();
	for (ArmController& arm : armControllers) {
		arm.stop();
	}
}