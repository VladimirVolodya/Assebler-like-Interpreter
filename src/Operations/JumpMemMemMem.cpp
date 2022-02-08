//
// Created by Vladimir on 06.02.2022.
//

#include "Operations/JumpMemMemMem.h"

JumpMemMemMem::JumpMemMemMem(int32_t size, int32_t address) :
        IOperation(size), address_(address) {}

void
JumpMemMemMem::process(std::vector<int32_t> &registers, std::unordered_map<int32_t, int32_t> &memory, int32_t &ip) {
    ip = address_;
}
