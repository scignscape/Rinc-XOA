
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef VM_INTERPRETER__H
#define VM_INTERPRETER__H

#include "global-types.h"

#include "vm-reader.h"
#include "vm-opstatement.h"
#include "vm-dispatcher.h"

#include "otns.h"

OTNS_(DogPal)

class VM_Interpreter
{
 VM_Reader reader_;
 VM_Dispatcher dispatcher_;

 QMap<QString, QVector<QPair<void*, u4>>> ops_by_proc_name_;
 QVector<QPair<void*, u4>>& current_proc_name_ops_;

 void parse_x0(const VM_Opstatement& opst);
 void parse_x1(const VM_Opstatement& opst);
 void parse_x2(const VM_Opstatement& opst);
 void parse_x3(const VM_Opstatement& opst);
 void parse_x4(const VM_Opstatement& opst);
 void parse_List(const VM_Opstatement& opst);

public:

 VM_Interpreter();

 void load_file(QString path);
 void parse();

 template<typename FN_Type, typename ...ARGS>
 void parse_fn(FN_Type fn, const VM_Opstatement& opst, ARGS ...args);

};

_OTNS(DogPal)

#endif // VM_INTERPRETER__H
