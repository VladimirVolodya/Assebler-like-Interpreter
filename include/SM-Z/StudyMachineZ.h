//
// Created by Vladimir on 05.02.2022.
//

#ifndef SM_INTERPRETER_STUDYMACHINEZ_H
#define SM_INTERPRETER_STUDYMACHINEZ_H

#include "Z_modules.h"

class StudyMachineZ : public IStudyMachine {
  public:
    explicit StudyMachineZ(int32_t num_of_registers);
    void printState() const override;
  private:
    void processMemorySetting(const std::string &memory_setting) override;
    void processProgramLine(const std::string &program_line) override;
};


#endif //SM_INTERPRETER_STUDYMACHINEZ_H
