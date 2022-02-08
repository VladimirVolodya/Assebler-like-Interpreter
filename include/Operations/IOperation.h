#ifndef SM_INTERPRETER_IOPERATION_H
#define SM_INTERPRETER_IOPERATION_H

#include <unordered_map>
#include <vector>
#include "utils/utils.h"

class IOperation {
  protected:
    int32_t size_; // размер команды в ячейках
  public:
    virtual void process(std::vector<int32_t>& registers, std::unordered_map<int32_t, int32_t>& memory, int32_t& ip) = 0;
    explicit IOperation(int32_t size) : size_(size) {}
    virtual ~IOperation() = default;
    int32_t getSize() const {
        return size_;
    }
};

#endif //SM_INTERPRETER_IOPERATION_H
