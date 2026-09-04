
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

#define GET_VECTOR_CASE(m, c) \
  case VM_Opstatement::Mid_Control_Kinds::m: return _getVector_##m##_##c();

template<>
void* VM_Dispatcher::_get_vector<VM_Opstatement::Control_Coords::x0>(VM_Opstatement::Mid_Control_Kinds mck)
{
 switch (mck)
 {
 GET_VECTOR_CASE(N_A, x0)
 default: return nullptr;
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


//GET_VECTOR_CASE(String, c) \
GET_VECTOR_CASE(String_List, c) \

template<>
void* VM_Dispatcher::_get_vector<VM_Opstatement::Control_Coords::x1>(VM_Opstatement::Mid_Control_Kinds mck)
{
 switch (mck)
 {
 GET_VECTOR_CASES(x1)
 default: return nullptr;
 }
}

template<>
void* VM_Dispatcher::_get_vector<VM_Opstatement::Control_Coords::x2>(VM_Opstatement::Mid_Control_Kinds mck)
{
 switch (mck)
 {
 GET_VECTOR_CASES(x2)
 default: return nullptr;
 }
}


template<>
void* VM_Dispatcher::_get_vector<VM_Opstatement::Control_Coords::x3>(VM_Opstatement::Mid_Control_Kinds mck)
{
 switch (mck)
 {
 GET_VECTOR_CASES(x3)
 default: return nullptr;
 }
}


template<>
void* VM_Dispatcher::_get_vector<VM_Opstatement::Control_Coords::x4>(VM_Opstatement::Mid_Control_Kinds mck)
{
 switch (mck)
 {
 GET_VECTOR_CASES(x4)
 default: return nullptr;
 }
}


template<>
void* VM_Dispatcher::_get_vector<VM_Opstatement::Control_Coords::List>(VM_Opstatement::Mid_Control_Kinds mck)
{
 switch (mck)
 {
 GET_VECTOR_CASES(List)
 default: return nullptr;
 }
}



void* VM_Dispatcher::get_vector(VM_Opstatement::Mid_Control_Kinds mck,
  VM_Opstatement::Control_Coords cc)
{
#define GET_VECTOR_CC_CASE(c) \
  case VM_Opstatement::Control_Coords::c: return _get_vector<VM_Opstatement::Control_Coords::c>(mck);

 switch (cc)
 {
 GET_VECTOR_CC_CASE(x0)
 GET_VECTOR_CC_CASE(x1)
 GET_VECTOR_CC_CASE(x2)
 GET_VECTOR_CC_CASE(x3)
 GET_VECTOR_CC_CASE(x4)
 GET_VECTOR_CC_CASE(List)

 default: return nullptr;
 }

}


#define WRAP_GET_VECTORX(m, c, name) \
   inline void* _getVector_##m##_##c() { return &name##_; }

