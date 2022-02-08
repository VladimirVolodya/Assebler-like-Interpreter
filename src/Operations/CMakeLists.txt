project(operations)

add_library(operations SHARED
        AddMemMemMem.cpp
        AddRegMem.cpp
        AddRegReg.cpp
        CmpRegMem.cpp
        CmpRegReg.cpp
        DivMemMemMemSigned.cpp
        DivMemMemMemUnsigned.cpp
        DivRegMemSigned.cpp
        DivRegMemUnsigned.cpp
        DivRegRegSigned.cpp
        DivRegRegUnsigned.cpp
        JumpEqMemMemMem.cpp
        JumpEqRegMem.cpp
        JumpGEqMemMemMemSigned.cpp
        JumpGEqRegMem.cpp
        JumpGreaterMemMemMemSigned.cpp
        JumpGreaterRegMem.cpp
        JumpLEqMemMemMemSigned.cpp
        JumpLEqRegMem.cpp
        JumpLessMemMemMemSigned.cpp
        JumpLessRegMem.cpp
        JumpMemMemMem.cpp
        JumpNotEqRegMem.cpp
        JumpNotEqMemMemMem.cpp
        JumpRegMem.cpp
        MulMemMemMemSigned.cpp
        MulMemMemMemUnsigned.cpp
        MulRegMemSigned.cpp
        MulRegMemUnsigned.cpp
        MulRegRegSigned.cpp
        MulRegRegUnsigned.cpp
        SendMem2Reg.cpp
        SendMemMemMem.cpp
        SendReg2Mem.cpp
        SendReg2Reg.cpp
        Stop.cpp
        SubtractMemMemMem.cpp
        SubtractRegMem.cpp
        SubtractRegReg.cpp
        Filler.cpp
        SendWithModifier.cpp
        JumpLessMemMemMemUnsigned.cpp JumpLEqMemMemMemUnsigned.cpp JumpGreaterMemMemMemUnsigned.cpp JumpGEqMemMemMemUnsigned.cpp)

target_link_libraries(operations utils)

add_dependencies(operations utils)
