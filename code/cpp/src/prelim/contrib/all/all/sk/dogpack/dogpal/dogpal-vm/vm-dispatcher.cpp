
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#include "vm-dispatcher.h"

#include "textio.h"

USING_KANS(TextIO)

USING_OTNS(DogPal)

VM_Dispatcher::VM_Dispatcher()
{

}

template <typename T>
struct _first_argument;


template <typename ARG_Type>
struct _first_argument<void (VM_Opstatement::*)(ARG_Type)> {
  using type = ARG_Type;
};


#define GET_VECTOR_CASE(m, c) \
  case VM_Opstatement::Mid_Control_Kinds::m: return _getVector_##m##_##c(fn);

template<typename FN_Type>
QPair<void*, u4> VM_Dispatcher::_get_vector_x0::_get_vector
   (VM_Opstatement::Mid_Control_Kinds mck, FN_Type fn)
 {
  switch (mck)
  {
//  case VM_Opstatement::Mid_Control_Kinds::N_A:
//    return _getVector_N_A_x0(fn);
  GET_VECTOR_CASE(N_A, x0)
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


template<typename FN_Type>
QPair<void*, u4> VM_Dispatcher::_get_vector_x1::_get_vector
   (VM_Opstatement::Mid_Control_Kinds mck, FN_Type fn, QString arg)
{
 switch (mck)
 {
 GET_VECTOR_CASE(String, x1)
 GET_VECTOR_CASE(String_List, x1)
 GET_VECTOR_CASES(x1)
//   case VM_Opstatement::Mid_Control_Kinds::String:
//   return _getVector_String_x1(fn);
 default: return {nullptr, 0};
 }
}

//GET_VECTOR_CASE(String, c) \
GET_VECTOR_CASE(String_List, c) \

#ifdef HIDE

template<typename FN_Type>
void* VM_Dispatcher::_get_vector<VM_Opstatement::Control_Coords::x1>(VM_Opstatement::Mid_Control_Kinds mck)
{
 switch (mck)
 {
// GET_VECTOR_CASES(x1)
 default: return nullptr;
 }
}
#endif

template<typename FN_Type>
QPair<void*, u4> VM_Dispatcher::_get_vector_x2::_get_vector
   (VM_Opstatement::Mid_Control_Kinds mck, FN_Type fn, QString arg)
{
 switch (mck)
 {
 GET_VECTOR_CASES(x2)
 default: return {nullptr, 0};
 }
}


template<typename FN_Type>
//template<>
QPair<void*, u4> VM_Dispatcher::_get_vector_x3::_get_vector
   (VM_Opstatement::Mid_Control_Kinds mck, FN_Type fn, QString arg)
{
 switch (mck)
 {
 GET_VECTOR_CASES(x3)
 default: return {nullptr, 0};
 }
}


template<typename FN_Type>
QPair<void*, u4> VM_Dispatcher::_get_vector_x4::_get_vector
   (VM_Opstatement::Mid_Control_Kinds mck, FN_Type fn, QString arg)
{
 switch (mck)
 {
 GET_VECTOR_CASES(x4)
 default: return {nullptr, 0};
 }
}


template<typename FN_Type>
QPair<void*, u4> VM_Dispatcher::_get_vector_xx::_get_vector
   (VM_Opstatement::Mid_Control_Kinds mck, FN_Type fn, QString arg)
{
 switch (mck)
 {
 GET_VECTOR_CASES(List)
 default: return {nullptr, 0};
 }
}

template<typename FN_Type>
QPair<void*, u4> VM_Dispatcher::get_vector(VM_Opstatement::Mid_Control_Kinds mck,
  VM_Opstatement::Control_Coords cc, FN_Type fn, QString args)
{
#define GET_VECTOR_CC_CASE(c) \
  case VM_Opstatement::Control_Coords::c: \
    return _get_vector_##c::_get_vector(mck, fn, args);

 switch (cc)
 {
 case VM_Opstatement::Control_Coords::x0:
   return _get_vector_x0::_get_vector(mck, fn);

// GET_VECTOR_CC_CASE(x0)
 GET_VECTOR_CC_CASE(x1)
 GET_VECTOR_CC_CASE(x2)
 GET_VECTOR_CC_CASE(x3)
 GET_VECTOR_CC_CASE(x4)

//? GET_VECTOR_CC_CASE(xx)

 default: return {nullptr, 0};
 }

}

#define WRAP_GET_VECTORX(m, c, name) \
   inline void* _getVector_##m##_##c() { return &name##_; }

