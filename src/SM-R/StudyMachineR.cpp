//
// Created by vsm on 07.02.2022.
//

#include "SM-R/StudyMachineR.h"

StudyMachineR::StudyMachineR(int32_t num_of_registers) : IStudyMachine(num_of_registers), reg_(false),
cur_operation_address(-1), reg_reg_codes({20, 21, 22, 23, 33, 24, 34, 25}) {}

void StudyMachineR::processMemorySetting(const std::string &memory_setting) {
    int32_t address, value;
    std::stringstream ss(memory_setting);
    if (memory_setting == "registers:") {
        reg_ = true;
        return;
    } else if (memory_setting == "memory:") {
        reg_ = false;
        return;
    }
    if (reg_) {
        ss >> std::dec >> address >> value;
        if (address >= registers_.size()) {
            throw std::runtime_error("Unknown register number.");
        }
        registers_[address] = value;
    } else {
        ss >> std::hex >> address >> std::dec;
        if (memory_.find(address - 1) != memory_.end()) {
            memory_[address - 1] = randint();
        }
        if (ss >> value) {
            memory_[address] = value;
        } else {
            memory_[address] = randint();
        }
    }
}

void StudyMachineR::processProgramLine(const std::string &program_line) {
    int command_address, operation_code, first_address, second_address;
    std::stringstream ss(program_line);
    ss >> std::hex >> command_address >> std::dec >> operation_code >> first_address;
    if (reg_reg_codes.find(operation_code) == reg_reg_codes.end()) {
        ss >> std::hex;
    }
    ss >> second_address;
    if (start_instruction_pointer_ == -1) {
        start_instruction_pointer_ = command_address;
        cur_operation_address = start_instruction_pointer_;
    }
    if (command_address != cur_operation_address) {
        // Предыдущая команда занимает столько места, что по
        // написанному адресу не может быть записана еще одна,
        // здесь должно быть продолжение предыдущей команды
        throw std::runtime_error("Address already in use: " + decimal2hexadecimal(command_address));
    }
    switch (operation_code) {
        case 99: {
            program_.push_back(new Stop(1));
            break;
        }
        case 0: {
            program_.push_back(new SendMem2Reg(2, first_address, second_address));
            break;
        }
        case 10: {
            program_.push_back(new SendReg2Mem(2, second_address, first_address));
            break;
        }
        case 20: {
            program_.push_back(new SendReg2Reg(1, first_address, second_address));
            break;
        }
        case 1: {
            program_.push_back(new AddRegMem(2, first_address, second_address));
            break;
        }
        case 21: {
            program_.push_back(new AddRegReg(1, first_address, second_address));
            break;
        }
        case 2: {
            program_.push_back(new SubtractRegMem(2, first_address, second_address));
            break;
        }
        case 22: {
            program_.push_back(new SubtractRegReg(1, first_address, second_address));
            break;
        }
        case 3: {
            program_.push_back(new MulRegMemSigned(2,first_address, second_address));
            break;
        }
        case 13: {
            program_.push_back(new MulRegMemUnsigned(2, first_address, second_address));
            break;
        }
        case 23: {
            program_.push_back(new MulRegRegSigned(1, first_address, second_address));
            break;
        }
        case 33: {
            program_.push_back(new MulRegRegUnsigned(1, first_address, second_address));
            break;
        }
        case 4: {
            program_.push_back(new DivRegMemSigned(2, first_address, second_address));
            break;
        }
        case 14: {
            program_.push_back(new DivRegMemUnsigned(2, first_address, second_address));
            break;
        }
        case 24: {
            program_.push_back(new DivRegRegSigned(1, first_address, second_address));
            break;
        }
        case 34: {
            program_.push_back(new DivRegRegUnsigned(1, first_address, second_address));
            break;
        }
        case 5: {
            program_.push_back(new CmpRegMem(2, first_address, second_address));
            break;
        }
        case 25: {
            program_.push_back(new CmpRegReg(1, first_address, second_address));
            break;
        }
        case 80: {
            program_.push_back(new JumpRegMem(2, second_address));
            break;
        }
        case 81: {
            program_.push_back(new JumpEqRegMem(2, first_address, second_address));
            break;
        }
        case 82: {
            program_.push_back(new JumpNotEqRegMem(2, first_address, second_address));
            break;
        }
        case 83: {
            program_.push_back(new JumpLessRegMem(2, first_address, second_address));
            break;
        }
        case 84: {
            program_.push_back(new JumpGEqRegMem(2, first_address, second_address));
            break;
        }
        case 85: {
            program_.push_back(new JumpGreaterRegMem(2, first_address, second_address));
            break;
        }
        case 86: {
            program_.push_back(new JumpLEqRegMem(2, first_address, second_address));
            break;
        }
        default: {
            throw std::runtime_error("Unknown command by the address: " + decimal2hexadecimal(command_address));
        }
    }
    cur_operation_address += program_.back()->getSize();
    int32_t back_size = program_.back()->getSize();
    for (int i = 1; i < back_size; ++i) {
        program_.push_back(new Filler());
    }
}

void StudyMachineR::printState() const {
    std::string delimiter = "+------------+-------------+\n";
    std::cout << "REGISTERS:\n" << delimiter;
    for (int i = 0; i < registers_.size(); ++i) {
        std::cout << "| " << std::setw(10) << std::setfill(' ') << i << " | " << std::setw(11)
                  << std::setfill(' ') << registers_[i] << " |\n" << delimiter;
    }
    std::cout << "MEMORY:\n";
    if (!memory_.empty()) {
        std::cout << delimiter;
        for (const auto& addr_val : memory_) {
            std::cout << "| " << decimal2hexadecimal(addr_val.first) << " | " << std::setw(11)
                      << std::setfill(' ') << addr_val.second << " |\n" << delimiter;
        }
    } else {
        std::cout << "-\n";
    }
    std::cout << '\n';
}
