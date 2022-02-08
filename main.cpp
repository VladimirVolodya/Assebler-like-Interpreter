#include "SM-R/StudyMachineR.h"
#include "SM-Z/StudyMachineZ.h"
#include <iostream>

int main(int argc, char** argv) {
    if (argc < 4) {
        std::cout << "Program needs three arguments:\n";
	std::cout << " - id of machine to interpret (0 for three-address machine, 1 for two-address)\n";
	std::cout << " - path to file with memory settings\n";
	std::cout << " - path to file with program code\n";
	return 1;
    }
    int32_t machine_id = atoi(argv[1]);
    IStudyMachine* sm;
    if (machine_id == 0) {
        sm = new StudyMachineZ(0);
    } else if (machine_id == 1) {
        sm = new StudyMachineR(16);
    } else {
        std::cout << "Study machine id must be 0 or 1.\n";
	return 1;
    }
    sm->setUp(argv[2], argv[3]);
    sm->run();
    delete sm;
    return 0;
}
