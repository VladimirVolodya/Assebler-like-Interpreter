//
// Created by Vladimir on 06.02.2022.
//

#include "Operations/DivRegRegUnsigned.h"

DivRegRegUnsigned::DivRegRegUnsigned(int32_t size, int32_t first_address, int32_t second_address) :
        IOperation(size), first_address_(first_address), second_address_(second_address) {}

void
DivRegRegUnsigned::process(std::vector<int32_t> &registers, std::unordered_map<int32_t, int32_t> &memory, int32_t &ip) {
    ip += size_;
    registers[first_address_ + 1] = static_cast<int32_t>(
            static_cast<uint32_t>(registers[first_address_]) % static_cast<uint32_t>(registers[second_address_])
    );
    registers[first_address_] = static_cast<int32_t>(
            static_cast<uint32_t>(registers[first_address_]) / static_cast<uint32_t>(registers[second_address_])
            );
}
