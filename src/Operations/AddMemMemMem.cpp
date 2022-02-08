#include "Operations/AddMemMemMem.h"

void AddMemMemMem::process(std::vector<int32_t> &registers, std::unordered_map<int32_t, int32_t> &memory, int32_t &ip) {
    ip += size_;
    if (memory.find(third_address_) == memory.end()) {
        throw std::runtime_error("entry at address " + decimal2hexadecimal(third_address_));
    }
    memory[third_address_] = (memory.find(first_address_) == memory.end() ? randint() : memory[first_address_])
            + (memory.find(second_address_) == memory.end() ? randint() : memory[second_address_]);
}

AddMemMemMem::AddMemMemMem(int32_t size, int32_t first_address, int32_t second_address, int32_t third_address) :
IOperation(size), first_address_(first_address), second_address_(second_address), third_address_(third_address) {}
