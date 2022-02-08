#ifndef SM_INTERPRETER_ADDREGMEM_H
#define SM_INTERPRETER_ADDREGMEM_H

#include <cstdint>
#include "Operations/IOperation.h"

class AddRegMem : public IOperation {
  public:
    void process(std::vector<int32_t>& registers, std::unordered_map<int32_t, int32_t>& memory, int32_t& ip) override;
    explicit AddRegMem(int32_t size, int32_t first_address, int32_t second_address);
  private:
    int32_t reg_address_;
    int32_t mem_address_;
};

#endif //SM_INTERPRETER_ADDREGMEM_H
