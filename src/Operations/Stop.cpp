//
// Created by Vladimir on 06.02.2022.
//

#include "Operations/Stop.h"

void Stop::process(std::vector<int32_t> &registers, std::unordered_map<int32_t, int32_t> &memory, int32_t &ip) {
    ip = -1;
}

Stop::Stop(int32_t size) : IOperation(size) {}
