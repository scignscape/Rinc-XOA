
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
 VM_OpMethods methods_;

 VM_Reader reader_;
 VM_Dispatcher dispatcher_;

 QMap<QString, QVector<QPair<void*, u4>>> ops_by_proc_name_;
 QVector<QPair<void*, u4>>& current_proc_name_ops_;

 QVector<QString> cached_strings_;

 void encode_which_stack(u1 num);
 u1 decode_which_stack(u4& number);

 void run_op_pair(QPair<void*, u4> pr);

 void parse_cached_string(const VM_Opstatement& opst);

 void parse_x0(const VM_Opstatement& opst);
 void parse_x1(const VM_Opstatement& opst);
 void parse_x2(const VM_Opstatement& opst);
 void parse_x3(const VM_Opstatement& opst);
 void parse_x4(const VM_Opstatement& opst);
 void parse_List(const VM_Opstatement& opst);

 template<typename FN_Type, typename ...ARGS>
 void parse_fn(FN_Type fn, const VM_Opstatement& opst, ARGS ...args);

public:

 VM_Interpreter();

 void load_file(QString path);
 void parse();
 void run_proc(QString proc_name);

 void run()
 {
  run_proc("<main>");
 }

};

_OTNS(DogPal)

#endif // VM_INTERPRETER__H
