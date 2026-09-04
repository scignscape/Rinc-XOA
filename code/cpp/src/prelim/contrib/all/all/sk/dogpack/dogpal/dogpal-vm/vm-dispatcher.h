
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef VM_DISPATCER__H
#define VM_DISPATCER__H

#include "global-types.h"

#include "vm-reader.h"
#include "vm-opstatement.h"

#include <QPair>

#include "otns.h"

OTNS_(DogPal)

//template<VM_Opstatement::Mid_Control_Kinds MCK, VM_Opstatement::Control_Coords cc>
//void* get_vector();

////#define WRAP_GET_VECTOR(m, c, name) \
//// template<> \
//// void* get_vector<VM_Opstatement::Mid_Control_Kinds::m, VM_Opstatement::Control_Coords::c> \
//// { \
////  return &name; \
//// } \

//QVector<void (VM_Dispatcher::*)()> instr_x0_;
//// WRAP_GET_VECTOR(N_A, x0, instr_x0_)

//  template<>
//  inline void* get_vector<VM_Opstatement::Mid_Control_Kinds::N_A, VM_Opstatement::Control_Coords::x0>()
//  {
//   return &instr_x0_;
//  }


class VM_Dispatcher
{
#define WRAP_GET_VECTOR(m, c, name) \
   inline QPair<void*, u4> _getVector_##m##_##c(decltype(name##_)::value_type vt) \
  { name##_.push_back(vt); \
    return {&name##_, name##_.size()}; }



 QVector<void (VM_Dispatcher::*)()> instr_x0_;
 WRAP_GET_VECTOR(N_A, x0, instr_x0)

 QVector<QPair<void (VM_Dispatcher::*)(QString), QString>> instr_x1_qstr_;
 WRAP_GET_VECTOR(String, x1, instr_x1_qstr)

 QVector<QPair<void (VM_Dispatcher::*)(QStringList), QStringList>> instr_x1_qstrl_;
 WRAP_GET_VECTOR(String, List, instr_x1_qstrl)

#define VEC_1_ARG(type, uctype) \
  QVector<QPair<void (VM_Dispatcher::*)(type), type>> instr_x1_##type##_; \
  WRAP_GET_VECTOR(uctype, x1, instr_x1_##type)

#define VEC_2_ARG(type, uctype) \
  QVector<QPair<void (VM_Dispatcher::*)(type, type), QVector<type>>> instr_x2_##type##_; \
  WRAP_GET_VECTOR(uctype, x2, instr_x2_##type)

#define VEC_3_ARG(type, uctype) \
  QVector<QPair<void (VM_Dispatcher::*)(type, type, type), QVector<type>>> instr_x3_##type##_; \
  WRAP_GET_VECTOR(uctype, x3, instr_x3_##type)

#define VEC_4_ARG(type, uctype) \
  QVector<QPair<void (VM_Dispatcher::*)(type, type, type, type), QVector<type>>> instr_x4_##type##_; \
  WRAP_GET_VECTOR(uctype, x4, instr_x4_##type)

#define VEC_LIST_ARG(type, uctype) \
  QVector<QPair<void (VM_Dispatcher::*)(QVector<type>), QVector<type>>> instr_xx_##type##_; \
  WRAP_GET_VECTOR(uctype, List, instr_xx_##type)

#define VECS_ARG(type, uctype) \
  VEC_1_ARG(type, uctype) VEC_2_ARG(type, uctype) VEC_3_ARG(type, uctype) \
  VEC_4_ARG(type, uctype) VEC_LIST_ARG(type, uctype)

 VECS_ARG(u1, U1)
 VECS_ARG(u2, U2)
 VECS_ARG(u4, U4)
 VECS_ARG(n8, U8)

 VECS_ARG(s1, S1)
 VECS_ARG(s2, S2)
 VECS_ARG(s4, S4)
 VECS_ARG(s8, S8)

 VECS_ARG(r4, R4)
 VECS_ARG(r8, R8)

public:

 VM_Dispatcher();

 template<typename FN_Type>
 QPair<void*, u4> get_vector(VM_Opstatement::Mid_Control_Kinds mck,
   VM_Opstatement::Control_Coords cc, FN_Type fn, QString args);

 struct _get_vector_x0
 {
  template<typename FN_Type>
  QPair<void*, u4> _get_vector(VM_Opstatement::Mid_Control_Kinds mck,
    FN_Type fn);
 };

 struct _get_vector_x1
 {
  template<typename FN_Type>
  QPair<void*, u4> _get_vector(VM_Opstatement::Mid_Control_Kinds mck,
    FN_Type fn, QString arg);
 };

 struct _get_vector_x2
 {
  template<typename FN_Type>
  QPair<void*, u4> _get_vector(VM_Opstatement::Mid_Control_Kinds mck,
    FN_Type fn, QString args);
 };

 struct _get_vector_x3
 {
  template<typename FN_Type>
  QPair<void*, u4> _get_vector(VM_Opstatement::Mid_Control_Kinds mck,
    FN_Type fn, QString args);
 };

 struct _get_vector_x4
 {
  template<typename FN_Type>
  QPair<void*, u4> _get_vector(VM_Opstatement::Mid_Control_Kinds mck,
    FN_Type fn, QString args);
 };

 struct _get_vector_xx
 {
  template<typename FN_Type>
  QPair<void*, u4> _get_vector(VM_Opstatement::Mid_Control_Kinds mck,
    FN_Type fn, QString args);
 };

};

#ifdef HIDE
template<>
struct VM_Dispatcher::_get_vector_s<VM_Opstatement::Control_Coords::x0>
{
 template<typename FN_Type>
 QPair<void*, u4> _get_vector(VM_Opstatement::Mid_Control_Kinds mck,
   FN_Type fn);
};
#endif

_OTNS(DogPack)

#endif // VM_INTERPRETER__H
