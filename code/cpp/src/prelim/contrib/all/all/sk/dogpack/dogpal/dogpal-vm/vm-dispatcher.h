
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef VM_DISPATCER__H
#define VM_DISPATCER__H

#include "global-types.h"

#include "vm-reader.h"
#include "vm-opstatement.h"

#include "vm-opmethods.h"

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

//QVector<void (VM_OpMethods::*)()> instr_x0_;
//// WRAP_GET_VECTOR(N_A, x0, instr_x0_)

//  template<>
//  inline void* get_vector<VM_Opstatement::Mid_Control_Kinds::N_A, VM_Opstatement::Control_Coords::x0>()
//  {
//   return &instr_x0_;
//  }


class VM_Dispatcher
{

// WRAP_GET_VECTOR(uctype, x1, instr_x1_##type)


#define WRAP_GET_VECTOR(m, c, name) \
   template<typename ...WRONG_Types> \
   inline QPair<void*, u4> _getVector_##m##_##c(WRONG_Types...) { return {nullptr, 0}; } \
   inline QPair<void*, u4> _getVector_##m##_##c(decltype(name##_)::value_type::first_type fn, \
     decltype(name##_)::value_type::second_type val) \
   { name##_.push_back({fn, val}); \
     return {&name##_, name##_.size() - 1}; }

#define WRAP_GET_VECTOR_X0(m, c, name) \
   template<typename ...WRONG_Types> \
   inline QPair<void*, u4> _getVector_##m##_##c(WRONG_Types...) { return {nullptr, 0}; } \
   inline QPair<void*, u4> _getVector_##m##_##c(typename decltype(name##_)::value_type fn) \
   { name##_.push_back(fn); \
     return {&name##_, name##_.size() - 1}; }

//name##_.push_back({fn}); \
//    return {&name##_, name##_.size()};


 QVector<void (VM_OpMethods::*)()> instr_x0_;
 WRAP_GET_VECTOR_X0(N_A, x0, instr_x0)

// template<typename WRONG_Type>
// inline QPair<void*, u4> _getVector_N_A_x0(WRONG_Type)
// {
//  return {nullptr, 0};
// }

// inline QPair<void*, u4> _getVector_N_A_x0(decltype(instr_x0_)::value_type vt)
// {
//  instr_x0_.push_back(vt);
//  return {&instr_x0_, instr_x0_.size()};
// }




 QVector<QPair<void (VM_OpMethods::*)(QString), QString>> instr_x1_qstr_;
 WRAP_GET_VECTOR(String, x1, instr_x1_qstr)

 QVector<QPair<void (VM_OpMethods::*)(QStringList), QStringList>> instr_x1_qstrl_;
 WRAP_GET_VECTOR(String, List, instr_x1_qstrl)

#define VEC_1_ARG(type, uctype) \
  QVector<QPair<void (VM_OpMethods::*)(type), type>> instr_x1_##type##_; \
  WRAP_GET_VECTOR(uctype, x1, instr_x1_##type)

#define VEC_2_ARG(type, uctype) \
  QVector<QPair<void (VM_OpMethods::*)(type, type), QVector<type>>> instr_x2_##type##_; \
  WRAP_GET_VECTOR(uctype, x2, instr_x2_##type)

#define VEC_3_ARG(type, uctype) \
  QVector<QPair<void (VM_OpMethods::*)(type, type, type), QVector<type>>> instr_x3_##type##_; \
  WRAP_GET_VECTOR(uctype, x3, instr_x3_##type)

#define VEC_4_ARG(type, uctype) \
  QVector<QPair<void (VM_OpMethods::*)(type, type, type, type), QVector<type>>> instr_x4_##type##_; \
  WRAP_GET_VECTOR(uctype, x4, instr_x4_##type)

#define VEC_LIST_ARG(type, uctype) \
  QVector<QPair<void (VM_OpMethods::*)(QVector<type>), QVector<type>>> instr_xx_##type##_; \
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


//   template<typename ...WRONG_Types>
//   inline QPair<void*, u4> test_getVector_U4_x1(WRONG_Types... args)
//   {
//    auto first = std::get<0>(std::forward_as_tuple(std::forward<WRONG_Types>(args)...));
//    auto secomd = std::get<1>(std::forward_as_tuple(std::forward<WRONG_Types>(args)...));

////?    decltype(instr_x1_u4_)::value_type* vt = first;

//    return {nullptr, 0};
//   }
//   inline QPair<void*, u4> test_getVector_U4_x1(decltype(instr_x1_u4_)::value_type::first_type vt,
//                                                decltype(instr_x1_u4_)::value_type::second_type arg)
//   {
////?    instr_x1_u4_.push_back({vt, arg});
//    return {&instr_x1_u4_, instr_x1_u4_.size() - 1};
//   }


public:

 VM_Dispatcher();

 template<typename FN_Type, typename ARG_Type>
 QPair<void*, u4> get_vector(VM_Opstatement::Mid_Control_Kinds mck,
   VM_Opstatement::Control_Coords cc, FN_Type fn, ARG_Type args);

 template<typename FN_Type>
 QPair<void*, u4> get_vector(VM_Opstatement::Mid_Control_Kinds mck,
   VM_Opstatement::Control_Coords cc, FN_Type fn);

 struct _get_vector_x0
 {
  VM_Dispatcher* _this;
  template<typename FN_Type>
  QPair<void*, u4> _get_vector(VM_Opstatement::Mid_Control_Kinds mck,
    FN_Type fn);
 };

 struct _get_vector_x1
 {
  VM_Dispatcher* _this;
  template<typename FN_Type, typename ARG_Type>
  QPair<void*, u4> _get_vector(VM_Opstatement::Mid_Control_Kinds mck,
    FN_Type fn, ARG_Type arg);
 };

 struct _get_vector_x2
 {
  VM_Dispatcher* _this;

  template<typename FN_Type, typename ARG_Type>
  QPair<void*, u4> _get_vector(VM_Opstatement::Mid_Control_Kinds mck,
    FN_Type fn, ARG_Type args) { return {nullptr, 0}; }

  template<typename FN_Type, typename ARG_Type>
  QPair<void*, u4> _get_vector(VM_Opstatement::Mid_Control_Kinds mck,
    FN_Type fn, QVector<ARG_Type> args);
 };

 struct _get_vector_x3
 {
  VM_Dispatcher* _this;

  template<typename FN_Type, typename ARG_Type>
  QPair<void*, u4> _get_vector(VM_Opstatement::Mid_Control_Kinds mck,
    FN_Type fn, ARG_Type args) { return {nullptr, 0}; }

  template<typename FN_Type, typename ARG_Type>
  QPair<void*, u4> _get_vector(VM_Opstatement::Mid_Control_Kinds mck,
    FN_Type fn, QVector<ARG_Type> args);
 };

 struct _get_vector_x4
 {
  VM_Dispatcher* _this;

  template<typename FN_Type, typename ARG_Type>
  QPair<void*, u4> _get_vector(VM_Opstatement::Mid_Control_Kinds mck,
    FN_Type fn, ARG_Type args) { return {nullptr, 0}; }

  template<typename FN_Type, typename ARG_Type>
  QPair<void*, u4> _get_vector(VM_Opstatement::Mid_Control_Kinds mck,
    FN_Type fn, QVector<ARG_Type> args);
 };

 struct _get_vector_xx
 {
  VM_Dispatcher* _this;

  template<typename FN_Type, typename ARG_Type>
  QPair<void*, u4> _get_vector(VM_Opstatement::Mid_Control_Kinds mck,
    FN_Type fn, ARG_Type args) { return {nullptr, 0}; }

  template<typename FN_Type, typename ARG_Type>
  QPair<void*, u4> _get_vector(VM_Opstatement::Mid_Control_Kinds mck,
    FN_Type fn, QVector<ARG_Type> args);
 };

};

#define _GET_VECTOR_CASE_1(m) \
  case VM_Opstatement::Mid_Control_Kinds::m: return _this->_getVector_##m(fn, args);

#define _GET_VECTOR_CASE_2(m, c) \
  case VM_Opstatement::Mid_Control_Kinds::m: return _this->_getVector_##m##_##c(fn, args);

#define GET_VECTOR_CASE(...) \
  _preproc_CONCAT(_GET_VECTOR_CASE_, _preproc_NUM_ARGS(__VA_ARGS__))(__VA_ARGS__)



template<typename FN_Type>
QPair<void*, u4> VM_Dispatcher::_get_vector_x0::_get_vector
   (VM_Opstatement::Mid_Control_Kinds mck, FN_Type fn)
 {
  switch (mck)
  {
//  case VM_Opstatement::Mid_Control_Kinds::N_A:
//    return _getVector_N_A_x0(fn);
 //? GET_VECTOR_CASE(N_A, x0)
    case VM_Opstatement::Mid_Control_Kinds::N_A: return _this->_getVector_N_A_x0(fn);
  default: return {nullptr, 0};
  }
 }


#define GET_VECTOR_CASES(c) \
  GET_VECTOR_CASE(U1, c) \
  GET_VECTOR_CASE(U2, c) \
  GET_VECTOR_CASE(U4, c) \
  GET_VECTOR_CASE(U8, c) \
  GET_VECTOR_CASE(S1, c) \
  GET_VECTOR_CASE(S2, c) \
  GET_VECTOR_CASE(S4, c) \
  GET_VECTOR_CASE(S8, c) \
  GET_VECTOR_CASE(R4, c) \
  GET_VECTOR_CASE(R8, c) \


template<typename FN_Type, typename ARG_Type>
QPair<void*, u4> VM_Dispatcher::_get_vector_x1::_get_vector
   (VM_Opstatement::Mid_Control_Kinds mck, FN_Type fn, ARG_Type args)
{
 switch (mck)
 {
 GET_VECTOR_CASE(String, x1)
 GET_VECTOR_CASE(String_List)
 GET_VECTOR_CASES(x1)

// GET_VECTOR_CASE(U4, x1)
//   case VM_Opstatement::Mid_Control_Kinds::U4:
//     return _this->test_getVector_U4_x1(fn, args);


//   case VM_Opstatement::Mid_Control_Kinds::String:
//   return _getVector_String_x1(fn);
 default: return {nullptr, 0};
 }
}

//GET_VECTOR_CASE(String, c) \
GET_VECTOR_CASE(String_List, c) \


template<typename FN_Type, typename ARG_Type>
QPair<void*, u4> VM_Dispatcher::_get_vector_x2::_get_vector
   (VM_Opstatement::Mid_Control_Kinds mck, FN_Type fn, QVector<ARG_Type> args)
{
 switch (mck)
 {
 GET_VECTOR_CASES(x2)
 default: return {nullptr, 0};
 }
}


template<typename FN_Type, typename ARG_Type>
//template<>
QPair<void*, u4> VM_Dispatcher::_get_vector_x3::_get_vector
   (VM_Opstatement::Mid_Control_Kinds mck, FN_Type fn, QVector<ARG_Type> args)
{
 switch (mck)
 {
 GET_VECTOR_CASES(x3)
 default: return {nullptr, 0};
 }
}


template<typename FN_Type, typename ARG_Type>
QPair<void*, u4> VM_Dispatcher::_get_vector_x4::_get_vector
   (VM_Opstatement::Mid_Control_Kinds mck, FN_Type fn, QVector<ARG_Type> args)
{
 switch (mck)
 {
 GET_VECTOR_CASES(x4)
 default: return {nullptr, 0};
 }
}


template<typename FN_Type, typename ARG_Type>
QPair<void*, u4> VM_Dispatcher::_get_vector_xx::_get_vector
   (VM_Opstatement::Mid_Control_Kinds mck, FN_Type fn, QVector<ARG_Type> args)
{
 switch (mck)
 {
 GET_VECTOR_CASES(List)
 default: return {nullptr, 0};
 }
}

template<typename FN_Type>
QPair<void*, u4> VM_Dispatcher::get_vector(VM_Opstatement::Mid_Control_Kinds mck,
  VM_Opstatement::Control_Coords cc, FN_Type fn)
{
 switch (cc)
 {
 case VM_Opstatement::Control_Coords::x0:
   return _get_vector_x0{this}._get_vector(mck, fn);
 default: return {nullptr, 0};
 }
}

template<typename FN_Type, typename ARG_Type>
QPair<void*, u4> VM_Dispatcher::get_vector(VM_Opstatement::Mid_Control_Kinds mck,
  VM_Opstatement::Control_Coords cc, FN_Type fn, ARG_Type args)
{
#define GET_VECTOR_CC_CASE(c) \
  case VM_Opstatement::Control_Coords::c: \
    return _get_vector_##c{this}._get_vector(mck, fn, args);

 switch (cc)
 {
// GET_VECTOR_CC_CASE(x0)
 GET_VECTOR_CC_CASE(x1)
 GET_VECTOR_CC_CASE(x2)
 GET_VECTOR_CC_CASE(x3)
 GET_VECTOR_CC_CASE(x4)

//? GET_VECTOR_CC_CASE(xx)

 default: return {nullptr, 0};
 }

}


_OTNS(DogPal)

#endif // VM_INTERPRETER__H
