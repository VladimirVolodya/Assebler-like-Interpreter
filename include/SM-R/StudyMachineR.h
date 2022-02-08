//
// Created by vsm on 07.02.2022.
//

#ifndef SM_INTERPRETER_STUDYMACHINER_H
#define SM_INTERPRETER_STUDYMACHINER_H

#include "R_modules.h"
#include <unordered_set>

class StudyMachineR : public IStudyMachine {
  public:
    explicit StudyMachineR(int32_t num_of_registers);
    void printState() const override;
  private:
    void processMemorySetting(const std::string &memory_setting) override;
    void processProgramLine(const std::string &program_line) override;
    bool reg_;
    int32_t cur_operation_address;
    std::unordered_set<int32_t> reg_reg_codes;
};

#endif //SM_INTERPRETER_STUDYMACHINER_H
