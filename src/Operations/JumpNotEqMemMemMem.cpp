//
// Created by Vladimir on 06.02.2022.
//

#include "Operations/JumpNotEqMemMemMem.h"

JumpNotEqMemMemMem::JumpNotEqMemMemMem(int32_t size, int32_t first_address, int32_t second_address,
                                       int32_t third_address) :
        IOperation(size), first_address_(first_address), second_address_(second_address), third_address_(third_address) {}

void JumpNotEqMemMemMem::process(std::vector<int32_t> &registers, std::unordered_map<int32_t, int32_t> &memory,
                                 int32_t &ip) {
    int32_t first_val = memory.find(first_address_) == memory.end() ? randint() : memory[first_address_];
    int32_t second_val = memory.find(second_address_) == memory.end() ? randint() : memory[second_address_];
    ip += size_;
    if (first_val != second_val) {
        ip = third_address_;
    }
}
