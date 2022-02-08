//
// Created by Vladimir on 06.02.2022.
//

#include "Operations/SendReg2Mem.h"

SendReg2Mem::SendReg2Mem(int32_t size, int32_t mem_address, int32_t reg_address) :
        IOperation(size), mem_address_(mem_address), reg_address_(reg_address) {}

void SendReg2Mem::process(std::vector<int32_t> &registers, std::unordered_map<int32_t, int32_t> &memory, int32_t &ip) {
    ip += size_;
    if (memory.find(mem_address_) == memory.end()) {
        throw std::runtime_error("entry at address " + decimal2hexadecimal(mem_address_));
    }
    memory[mem_address_] = registers[reg_address_];
}
