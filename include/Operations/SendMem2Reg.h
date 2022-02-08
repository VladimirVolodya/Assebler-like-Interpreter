//
// Created by Vladimir on 06.02.2022.
//

#ifndef SM_INTERPRETER_SENDMEM2REG_H
#define SM_INTERPRETER_SENDMEM2REG_H

#include "IOperation.h"

class SendMem2Reg : public IOperation {
  public:
    void process(std::vector<int32_t> &registers, std::unordered_map<int32_t, int32_t> &memory, int32_t &ip) override;
    explicit SendMem2Reg(int32_t size, int32_t reg_address, int32_t mem_address);
  private:
    int32_t reg_address_;
    int32_t mem_address_;
};

#endif //SM_INTERPRETER_SENDMEM2REG_H
