//
// Created by Vladimir on 06.02.2022.
//

#ifndef SM_INTERPRETER_DIVREGMEMSIGNED_H
#define SM_INTERPRETER_DIVREGMEMSIGNED_H

#include "IOperation.h"

class DivRegMemSigned : public IOperation {
  public:
    explicit DivRegMemSigned(int32_t size, int32_t reg_address, int32_t mem_address);
    void process(std::vector<int32_t>& registers, std::unordered_map<int32_t, int32_t>& memory, int32_t& ip) override;
  private:
    int32_t reg_address_;
    int32_t mem_address_;
};

#endif //SM_INTERPRETER_DIVREGMEMSIGNED_H
