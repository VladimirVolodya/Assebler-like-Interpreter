//
// Created by Vladimir on 06.02.2022.
//

#ifndef SM_INTERPRETER_JUMPMEMMEMMEM_H
#define SM_INTERPRETER_JUMPMEMMEMMEM_H

#include "IOperation.h"

class JumpMemMemMem : public IOperation {
  public:
    explicit JumpMemMemMem(int32_t size, int32_t address);
    void process(std::vector<int32_t> &registers, std::unordered_map<int32_t, int32_t> &memory, int32_t &ip) override;
  private:
    int32_t address_;
};

#endif //SM_INTERPRETER_JUMPMEMMEMMEM_H
