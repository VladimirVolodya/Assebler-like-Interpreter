//
// Created by Vladimir on 07.02.2022.
//

#include "Operations/SendWithModifier.h"

SendWithModifier::SendWithModifier(int32_t size, int32_t reg_address, int32_t modifier_address, int32_t mem_address,
                                   int32_t num_size) :
        IOperation(size), reg_address_(reg_address), modifier_address_(modifier_address),
        num_size_(num_size), mem_address_(mem_address) {}

void
SendWithModifier::process(std::vector<int32_t> &registers, std::unordered_map<int32_t, int32_t> &memory, int32_t &ip) {
    ip += size_;
    registers[reg_address_] = memory.find(mem_address_ + num_size_ * registers[modifier_address_]) == memory.end() ?
            randint() : memory[mem_address_ + num_size_ * registers[modifier_address_]];
}
