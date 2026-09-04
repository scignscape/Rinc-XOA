
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef VM_DISPATCER__H
#define VM_DISPATCER__H

#include "global-types.h"

#include "vm-reader.h"
#include "vm-opstatement.h"

#include "otns.h"

OTNS_(DogPal)

class VM_Dispatcher
{
 QVector<void (VM_Dispatcher::*)()> instr_x0;
 QVector<void (VM_Dispatcher::*)(QString)> instr_x1_qstr;
 QVector<void (VM_Dispatcher::*)(QStringList)> instr_x1_qstrl;

#define VEC_1_ARG(type) \
  QVector<void (VM_Dispatcher::*)(type)> instr_x1_##type;

#define VEC_2_ARG(type) \
  QVector<void (VM_Dispatcher::*)(type, type)> instr_x2_##type;

#define VEC_3_ARG(type) \
  QVector<void (VM_Dispatcher::*)(type, type, type)> instr_x3_##type;

#define VEC_4_ARG(type) \
  QVector<void (VM_Dispatcher::*)(type, type, type, type)> instr_x4_##type;

#define VEC_LIST_ARG(type) \
  QVector<void (VM_Dispatcher::*)(QVector<type>)> instr_xx_##type;

#define VECS_ARG(type) \
  VEC_1_ARG(type) VEC_2_ARG(type) VEC_3_ARG(type) VEC_4_ARG(type) VEC_LIST_ARG(type)

 VECS_ARG(u1)
 VECS_ARG(u2)
 VECS_ARG(u4)
 VECS_ARG(n8)

 VECS_ARG(s1)
 VECS_ARG(s2)
 VECS_ARG(s4)
 VECS_ARG(s8)

public:

 VM_Dispatcher();


};

_OTNS(DogPack)

#endif // VM_INTERPRETER__H
