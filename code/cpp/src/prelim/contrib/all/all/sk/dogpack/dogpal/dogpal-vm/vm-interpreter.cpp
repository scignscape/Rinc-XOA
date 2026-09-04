
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#include "vm-interpreter.h"

#include "textio.h"

USING_KANS(TextIO)

USING_OTNS(DogPal)

VM_Interpreter::VM_Interpreter()
{

}


void VM_Interpreter::load_file(QString path)
{
 reader_.load_file(path);
}

void VM_Interpreter::parse()
{
 VM_Opstatement vmo = reader_.next_opstatement();
}

