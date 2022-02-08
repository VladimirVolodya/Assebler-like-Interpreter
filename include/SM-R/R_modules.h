//
// Created by vsm on 07.02.2022.
//

#ifndef SM_INTERPRETER_R_MODULES_H
#define SM_INTERPRETER_R_MODULES_H

#include "ISM/IStudyMachine.h"
#include "Operations/Stop.h"
#include "Operations/SendMem2Reg.h"
#include "Operations/SendReg2Mem.h"
#include "Operations/SendReg2Reg.h"
#include "Operations/AddRegMem.h"
#include "Operations/AddRegReg.h"
#include "Operations/SubtractRegMem.h"
#include "Operations/SubtractRegReg.h"
#include "Operations/MulRegMemSigned.h"
#include "Operations/MulRegMemUnsigned.h"
#include "Operations/MulRegRegSigned.h"
#include "Operations/MulRegRegUnsigned.h"
#include "Operations/DivRegMemSigned.h"
#include "Operations/DivRegMemUnsigned.h"
#include "Operations/DivRegRegSigned.h"
#include "Operations/DivRegRegUnsigned.h"
#include "Operations/CmpRegMem.h"
#include "Operations/CmpRegReg.h"
#include "Operations/JumpRegMem.h"
#include "Operations/JumpEqRegMem.h"
#include "Operations/JumpNotEqRegMem.h"
#include "Operations/JumpLessRegMem.h"
#include "Operations/JumpLEqRegMem.h"
#include "Operations/JumpGreaterRegMem.h"
#include "Operations/JumpGEqRegMem.h"
#include "Operations/Filler.h"

#endif //SM_INTERPRETER_R_MODULES_H
