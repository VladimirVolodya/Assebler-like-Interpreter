//
// Created by Vladimir on 06.02.2022.
//

#include "Operations/SendMem2Reg.h"

void SendMem2Reg::process(std::vector<int32_t> &registers, std::unordered_map<int32_t, int32_t> &memory, int32_t &ip) {
    ip += size_;
    registers[reg_address_] = memory.find(mem_address_) == memory.end() ? randint() : memory[mem_address_];
}

SendMem2Reg::SendMem2Reg(int32_t size, int32_t reg_address, int32_t mem_address) :
        IOperation(size), reg_address_(reg_address), mem_address_(mem_address) {}
