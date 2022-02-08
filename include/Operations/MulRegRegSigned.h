//
// Created by Vladimir on 06.02.2022.
//

#ifndef SM_INTERPRETER_MULREGREGSIGNED_H
#define SM_INTERPRETER_MULREGREGSIGNED_H

#include "IOperation.h"

class MulRegRegSigned : public IOperation {
  public:
    explicit MulRegRegSigned(int32_t size, int32_t first_address, int32_t second_address);
    void process(std::vector<int32_t> &registers, std::unordered_map<int32_t, int32_t> &memory, int32_t &ip) override;
  private:
    int32_t first_address_;
    int32_t second_address_;
};

#endif //SM_INTERPRETER_MULREGREGSIGNED_H
