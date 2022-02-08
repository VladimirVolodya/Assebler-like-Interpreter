//
// Created by vsm on 07.02.2022.
//

#ifndef SM_INTERPRETER_JUMPGREATERMEMMEMMEMUNSIGNED_H
#define SM_INTERPRETER_JUMPGREATERMEMMEMMEMUNSIGNED_H

#include "IOperation.h"

class JumpGreaterMemMemMemUnsigned : public IOperation {
  public:
    explicit JumpGreaterMemMemMemUnsigned(int32_t size, int32_t first_address, int32_t second_address, int32_t third_address);
    void process(std::vector<int32_t> &registers, std::unordered_map<int32_t, int32_t> &memory, int32_t &ip) override;
  private:
    int32_t first_address_;
    int32_t second_address_;
    int32_t third_address_;
};

#endif //SM_INTERPRETER_JUMPGREATERMEMMEMMEMUNSIGNED_H
