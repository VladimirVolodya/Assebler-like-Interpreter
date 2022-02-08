//
// Created by Vladimir on 06.02.2022.
//

#ifndef SM_INTERPRETER_MULREGMEMSIGNED_H
#define SM_INTERPRETER_MULREGMEMSIGNED_H

#include "IOperation.h"

class MulRegMemSigned : public IOperation {
  public:
    explicit MulRegMemSigned(int32_t size, int32_t reg_address, int32_t mem_address);
    void process(std::vector<int32_t> &registers, std::unordered_map<int32_t, int32_t> &memory, int32_t &ip) override;
  private:
    int32_t reg_address_;
    int32_t mem_address_;
};

#endif //SM_INTERPRETER_MULREGMEMSIGNED_H
