//
// Created by Vladimir on 07.02.2022.
//

#ifndef SM_INTERPRETER_SENDWITHMODIFIER_H
#define SM_INTERPRETER_SENDWITHMODIFIER_H

#include "Operations/IOperation.h"

class SendWithModifier : public IOperation {
  public:
    explicit SendWithModifier(int32_t size, int32_t reg_address, int32_t modifier_address, int32_t mem_address, int32_t num_size);
    void process(std::vector<int32_t> &registers, std::unordered_map<int32_t, int32_t> &memory, int32_t &ip) override;
  private:
    int32_t num_size_;
    int32_t reg_address_;
    int32_t modifier_address_;
    int32_t mem_address_;
};

#endif //SM_INTERPRETER_SENDWITHMODIFIER_H
