//
// Created by vsm on 07.02.2022.
//

#include "SM-Z/StudyMachineZ.h"
#include "sstream"

void StudyMachineZ::processMemorySetting(const std::string &memory_setting) {
    int address, value;
    std::stringstream ss(memory_setting);
    ss >> std::hex >> address >> std::dec;
    if (ss >> value) {
        memory_[address] = value;
    } else {
        memory_[address] = randint();
    }
}

void StudyMachineZ::processProgramLine(const std::string &program_line) {
    int command_address, operation_code, first_address, second_address, third_address;
    std::stringstream ss(program_line);
    ss >> std::hex >> command_address >> std::dec >> operation_code >> std::hex >> first_address >> second_address >> third_address;
    if (start_instruction_pointer_ == -1) {
        start_instruction_pointer_ = command_address;
    }
    switch (operation_code) {
        case 99: {
            program_.push_back(new Stop(1));
            break;
        }
        case 0: {
            program_.push_back(new SendMemMemMem(1, first_address, second_address, third_address));
            break;
        }
        case 1: {
            program_.push_back(new AddMemMemMem(1, first_address, second_address, third_address));
            break;
        }
        case 2: {
            program_.push_back(new SubtractMemMemMem(1, first_address, second_address, third_address));
            break;
        }
        case 3: {
            program_.push_back(new MulMemMemMemSigned(1, first_address, second_address, third_address));
            break;
        }
        case 13: {
            program_.push_back(new MulMemMemMemUnsigned(1, first_address, second_address, third_address));
            break;
        }
        case 4: {
            program_.push_back(new DivMemMemMemSigned(1, 1, first_address, second_address, third_address));
            break;
        }
        case 14: {
            program_.push_back(new DivMemMemMemUnsigned(1, 1, first_address, second_address, third_address));
            break;
        }
        case 80: {
            program_.push_back(new JumpMemMemMem(1, third_address));
            break;
        }
        case 81: {
            program_.push_back(new JumpEqMemMemMem(1, first_address, second_address, third_address));
            break;
        }
        case 82: {
            program_.push_back(new JumpNotEqMemMemMem(1, first_address, second_address, third_address));
            break;
        }
        case 83: {
            program_.push_back(new JumpLessMemMemMemSigned(1, first_address, second_address, third_address));
            break;
        }
        case 93: {
            program_.push_back(new JumpLessMemMemMemUnsigned(1, first_address, second_address, third_address));
            break;
        }
        case 84: {
            program_.push_back(new JumpGEqMemMemMemSigned(1, first_address, second_address, third_address));
            break;
        }
        case 94: {
            program_.push_back(new JumpGEqMemMemMemUnsigned(1, first_address, second_address, third_address));
            break;
        }
        case 85: {
            program_.push_back(new JumpGreaterMemMemMemSigned(1, first_address, second_address, third_address));
            break;
        }
        case 95: {
            program_.push_back(new JumpGreaterMemMemMemUnsigned(1, first_address, second_address, third_address));
            break;
        }
        case 86: {
            program_.push_back(new JumpLEqMemMemMemSigned(1, first_address, second_address, third_address));
            break;
        }
        case 96: {
            program_.push_back(new JumpLEqMemMemMemUnsigned(1, first_address, second_address, third_address));
            break;
        }
        default: {
            throw std::runtime_error("Unknown command by the address: " + decimal2hexadecimal(command_address));
        }
    }
}

StudyMachineZ::StudyMachineZ(int32_t num_of_registers) : IStudyMachine(num_of_registers) {}

void StudyMachineZ::printState() const {
    std::string delimiter = "+------------+-----------+";
    std::cout << "MEMORY:\n" << delimiter;
    for (const auto& addr_val : memory_) {
        std::cout << "| " << decimal2hexadecimal(addr_val.first) << " | " << std::setw(9)
        << std::setfill(' ') << addr_val.second << " |\n" << delimiter;
    }
}
