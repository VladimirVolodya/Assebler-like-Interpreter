//
// Created by Vladimir on 06.02.2022.
//

#include "Operations/JumpGreaterRegMem.h"

JumpGreaterRegMem::JumpGreaterRegMem(int32_t size, int32_t reg_address, int32_t mem_address) :
        IOperation(size), reg_address_(reg_address), mem_address_(mem_address) {}

void
JumpGreaterRegMem::process(std::vector<int32_t> &registers, std::unordered_map<int32_t, int32_t> &memory, int32_t &ip) {
    ip += size_;
    if (registers[reg_address_] > 0) {
        ip = mem_address_;
    }
}
