//
// Created by Vladimir on 06.02.2022.
//

#ifndef SM_INTERPRETER_SENDREG2REG_H
#define SM_INTERPRETER_SENDREG2REG_H

#include "IOperation.h"

class SendReg2Reg : public IOperation {
  public:
    void process(std::vector<int32_t> &registers, std::unordered_map<int32_t, int32_t> &memory, int32_t &ip) override;
    explicit SendReg2Reg(int32_t size, int32_t first_address, int32_t second_address);
  private:
    int32_t first_address_;
    int32_t second_address_;
};

#endif //SM_INTERPRETER_SENDREG2REG_H
