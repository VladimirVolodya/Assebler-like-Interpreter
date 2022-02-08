//
// Created by Vladimir on 06.02.2022.
//

#ifndef SM_INTERPRETER_STOP_H
#define SM_INTERPRETER_STOP_H

#include "IOperation.h"

class Stop : public IOperation {
  public:
    explicit Stop(int32_t size);
    void process(std::vector<int32_t> &registers, std::unordered_map<int32_t, int32_t> &memory, int32_t &ip) override;
};

#endif //SM_INTERPRETER_STOP_H
