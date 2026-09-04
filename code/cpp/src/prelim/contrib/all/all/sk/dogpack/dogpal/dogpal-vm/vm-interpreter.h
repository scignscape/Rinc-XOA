
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef VM_INTERPRETER__H
#define VM_INTERPRETER__H

#include "global-types.h"

#include "vm-reader.h"
#include "vm-opstatement.h"

#include "otns.h"

OTNS_(DogPal)

class VM_Interpreter
{
 VM_Reader reader_;

public:

 VM_Interpreter();

 void load_file(QString path);
 void parse();

};

_OTNS(DogPack)

#endif // VM_INTERPRETER__H
