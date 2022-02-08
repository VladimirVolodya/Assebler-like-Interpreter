//
// Created by vsm on 07.02.2022.
//

#include "Operations/JumpLEqMemMemMemUnsigned.h"

JumpLEqMemMemMemUnsigned::JumpLEqMemMemMemUnsigned(int32_t size, int32_t first_address, int32_t second_address,
                                                 int32_t third_address) :
        IOperation(size), first_address_(first_address), second_address_(second_address), third_address_(third_address) {}

void
JumpLEqMemMemMemUnsigned::process(std::vector<int32_t> &registers, std::unordered_map<int32_t, int32_t> &memory, int32_t &ip) {
    uint32_t first_val = static_cast<uint32_t>(memory.find(first_address_) == memory.end() ? randint() : memory[first_address_]);
    uint32_t second_val = static_cast<uint32_t>(memory.find(second_address_) == memory.end() ? randint() : memory[second_address_]);
    ip += size_;
    if (first_val <= second_val) {
        ip = third_address_;
    }
}