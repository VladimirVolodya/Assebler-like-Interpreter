//
// Created by Vladimir on 06.02.2022.
//

#include "Operations/SubtractRegReg.h"

SubtractRegReg::SubtractRegReg(int32_t size, int32_t first_reg, int32_t second_reg) :
        IOperation(size), first_reg_(first_reg), second_reg_(second_reg) {}

void
SubtractRegReg::process(std::vector<int32_t> &registers, std::unordered_map<int32_t, int32_t> &memory, int32_t &ip) {
    ip += size_;
    registers[first_reg_] -= registers[second_reg_];
}
