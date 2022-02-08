//
// Created by vsm on 07.02.2022.
//

#include "utils/utils.h"

int32_t randint() {
    static std::random_device device;
    static std::mt19937 rng(device());
    static std::uniform_int_distribution distribution(std::numeric_limits<int32_t>::min(), std::numeric_limits<int32_t>::max());
    return distribution(rng);
}

std::string decimal2hexadecimal(int64_t num) {
    std::stringstream ss;
    ss << std::setw(8) << std::setfill('0') << std::hex << num;
    return "0x" + ss.str();
}
