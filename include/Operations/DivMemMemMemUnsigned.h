//
// Created by Vladimir on 06.02.2022.
//

#ifndef SM_INTERPRETER_DIVMEMMEMMEMUNSIGNED_H
#define SM_INTERPRETER_DIVMEMMEMMEMUNSIGNED_H

#include <cstdint>
#include "IOperation.h"

class DivMemMemMemUnsigned : public IOperation {
  public:
    explicit DivMemMemMemUnsigned(int32_t size, int32_t num_size, int32_t first_address, int32_t second_address, int32_t third_address);
    void process(std::vector<int32_t>& registers, std::unordered_map<int32_t, int32_t>& memory, int32_t& ip) override;
  private:
    int32_t first_address_;
    int32_t second_address_;
    int32_t third_address_;
    int32_t num_size_; // размер числа в ячейках
};

#endif //SM_INTERPRETER_DIVMEMMEMMEMUNSIGNED_H
