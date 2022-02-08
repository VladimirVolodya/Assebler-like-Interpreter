#ifndef SM_INTERPRETER_ISTUDYMACHINE_H
#define SM_INTERPRETER_ISTUDYMACHINE_H

#include <vector>
#include <unordered_map>
#include <fstream>
#include <iostream>
#include "Operations/IOperation.h"

class IStudyMachine {
  public:
    void setUp(const std::string& memory_settings, const std::string& program_code);
    void run();
    explicit IStudyMachine(int32_t num_of_registers);
    virtual void printState() const = 0;
    virtual ~IStudyMachine();
  protected:
    int32_t instruction_pointer_;
    int32_t start_instruction_pointer_;
    std::vector<int> registers_;
    std::unordered_map<int, int> memory_;
    std::vector<IOperation*> program_;
  private:
    virtual void processMemorySetting(const std::string& memory_setting) = 0;
    virtual void processProgramLine(const std::string& program_line) = 0;
};

void IStudyMachine::setUp(const std::string &memory_settings, const std::string &program_code) {
    std::ifstream in_mem(memory_settings);
    std::ifstream in_code(program_code);
    std::string line;
    while (std::getline(in_mem, line)) {
        processMemorySetting(line);
    }
    while (std::getline(in_code, line)) {
        processProgramLine(line);
    }
}

void IStudyMachine::run() {
    instruction_pointer_ = start_instruction_pointer_;
    int32_t iteration = 0;
    while (instruction_pointer_ != -1) {
        std::cout << "Iteration #" << iteration++ << ":\n";
        printState();
        program_[instruction_pointer_ - start_instruction_pointer_]->process(
                registers_, memory_, instruction_pointer_);
    }
    std::cout << "Final state:\n\n";
    printState();
}

IStudyMachine::IStudyMachine(int32_t num_of_registers) : instruction_pointer_(-1), start_instruction_pointer_(-1),
registers_(num_of_registers) {
    for (int32_t& reg : registers_) {
        reg = randint();
    }
}

IStudyMachine::~IStudyMachine() {
    for (auto& p : program_) {
        delete p;
    }
}

#endif //SM_INTERPRETER_ISTUDYMACHINE_H
