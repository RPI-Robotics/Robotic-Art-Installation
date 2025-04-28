#include "RAI.h"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Invalid number of arguments! Usage " << argv[0] << " input.svg" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::ifstream istr(filename);
	if (!istr.good()) {
		std::cerr << "Input file '" << filename << "' invalid" << std::endl;
		return 1;
	}

	std::cout << "Parsing file '" << filename << "'..." << std::endl;
	SegmentContainer::parseSVG(istr);
	istr.close();
	std::cout << "Parsing complete." << std::endl;

	std::cout << "Generating paths..." << std::endl;
	std::vector<Path>& paths = SegmentContainer::generatePaths();
	std::cout << "Paths generated successfully." << std::endl;

	HardwareContainer::initializeHardware();
	HardwareContainer::registerPaths(paths);
	std::cout << "Hardware initialized." << std::endl;

	std::cout << "Ready to begin drawing." << std::endl;
	std::cout << "Execute hardware sequence? [y/n]" << std::endl;

	std::string response;
	std::cin >> response;
	if (response != "y" && response != "Y") {
		std::cerr << "Aborting hardware sequence." << std::endl;
		return 0;
	}

	HardwareContainer::execute();
	std::cout << "Execution completed successfully." << std::endl;

	return 0;
}