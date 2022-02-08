//
// Created by Vladimir on 07.02.2022.
//

#include "Operations/Filler.h"

void Filler::process(std::vector<int32_t> &registers, std::unordered_map<int32_t, int32_t> &memory, int32_t &ip) {
    throw std::runtime_error("Unknown command by the address: " + decimal2hexadecimal(ip));
}

Filler::Filler() : IOperation(1) {}
