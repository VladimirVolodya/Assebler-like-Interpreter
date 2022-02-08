//
// Created by Vladimir on 06.02.2022.
//

#ifndef SM_INTERPRETER_SUBTRACTREGREG_H
#define SM_INTERPRETER_SUBTRACTREGREG_H

#include "IOperation.h"

class SubtractRegReg : public IOperation {
  public:
    explicit SubtractRegReg(int32_t size, int32_t first_reg, int32_t second_reg);
    void process(std::vector<int32_t> &registers, std::unordered_map<int32_t, int32_t> &memory, int32_t &ip) override;
  private:
    int32_t first_reg_;
    int32_t second_reg_;
};

#endif //SM_INTERPRETER_SUBTRACTREGREG_H
