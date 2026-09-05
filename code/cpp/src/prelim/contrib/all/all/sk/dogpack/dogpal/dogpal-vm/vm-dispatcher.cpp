
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#include "vm-dispatcher.h"

#include "textio.h"

#include "global-macros.h"

USING_KANS(TextIO)

USING_OTNS(DogPal)

VM_Dispatcher::VM_Dispatcher()
{

}

//template <typename T>
//struct _first_argument;


//template <typename ARG_Type>
//struct _first_argument<void (VM_Opstatement::*)(ARG_Type)> {
//  using type = ARG_Type;
//};

#define WRAP_GET_VECTORX(m, c, name) \
   inline void* _getVector_##m##_##c() { return &name##_; }

