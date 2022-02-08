//
// Created by Vladimir on 06.02.2022.
//

#include "Operations/JumpRegMem.h"

JumpRegMem::JumpRegMem(int32_t size, int32_t mem_address) :
        IOperation(size), mem_address_(mem_address) {}

void JumpRegMem::process(std::vector<int32_t> &registers, std::unordered_map<int32_t, int32_t> &memory, int32_t &ip) {
    ip = mem_address_;
}
