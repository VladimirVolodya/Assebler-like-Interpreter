//
// Created by Vladimir on 07.02.2022.
//

#ifndef SM_INTERPRETER_FILLER_H
#define SM_INTERPRETER_FILLER_H

#include "Operations/IOperation.h"

/*
 * класс нужен лишь чтобы кидать исключение при попытке выполнения
 * строки, в которой не записано никакой команды
 * (если, например, каждая команда занимает 2 ячейки, и
 * ячейка с некоторым адресом является "хвостом" команды)
 */
class Filler : public IOperation {
  public:
    explicit Filler();
    void process(std::vector<int32_t> &registers, std::unordered_map<int32_t, int32_t> &memory, int32_t &ip) override;
};

#endif //SM_INTERPRETER_FILLER_H
