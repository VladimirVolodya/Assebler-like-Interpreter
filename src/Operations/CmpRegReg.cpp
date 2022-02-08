//
// Created by Vladimir on 06.02.2022.
//

#include "Operations/CmpRegReg.h"

CmpRegReg::CmpRegReg(int32_t size, int32_t first_address, int32_t second_address) :
        IOperation(size), first_address_(first_address), second_address_(second_address) {}

void CmpRegReg::process(std::vector<int32_t> &registers, std::unordered_map<int32_t, int32_t> &memory, int32_t &ip) {
    ip += size_;
    if (registers[first_address_] == registers[second_address_]) {
        if (!registers[first_address_]) {
            registers[first_address_] = 1;
        }
    } else {
        registers[first_address_] = 0;
    }
}
