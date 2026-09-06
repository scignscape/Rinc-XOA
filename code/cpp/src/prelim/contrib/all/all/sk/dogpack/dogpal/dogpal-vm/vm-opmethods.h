
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef VM_OPMETHODS__H
#define VM_OPMETHODS__H

#include "global-types.h"

#include "vm-reader.h"
#include "vm-opstatement.h"

#include "modules/module-base.h"

#include "otns.h"

OTNS_(DogPal)

class SDI_Module;
class TAO_Module;

class VM_OpMethods
{

 SDI_Module* sdi_module_;
 TAO_Module* tao_module_;


public:

 VM_OpMethods();

 ACCESSORS(SDI_Module* ,sdi_module)
 ACCESSORS(TAO_Module* ,tao_module)

 u1 get_module_index(_Module_Base* module);

 _Module_Base* get_module_by_index(u1 index);

 _Module_Base* get_module_from_instruction(QString instr);

 enum class Signatures {
   N_A, x0, String, U4x1, U4x4
 };

// void sdi_new_sentence(u4 id);
// void sdi_sentence_switch_pos(u4 id, u4 pos, u4 row, u4 col);
// void sdi_sentence__end_pos(u4 id, u4 pos, u4 row, u4 col);
// void sdi_sentence_end_pos(u4 id, u4 pos, u4 row, u4 col);
// void sdi_sentence_end_punctuation(QString mark);
// void sdi_sentence_text(QString text);

 typedef void (_Module_Base::*methods_x0)();
 typedef void (_Module_Base::*methods_String)(QString);
 typedef void (_Module_Base::*methods_U4x1)(u4 arg);
 typedef void (_Module_Base::*methods_U4x4)(u4 arg1, u4 arg2, u4 arg3, u4 arg4);

 typedef methods_x0 methods_x0_opstatement_type;
 typedef QPair<methods_String, QString> methods_String_opstatement_type;
 typedef QPair<methods_U4x1, u4> methods_U4x1_opstatement_type;
 typedef QPair<methods_U4x4, QVector<u4>> methods_U4x4_opstatement_type;

 static constexpr u1 methods_x0_StackCode = 1;
 static constexpr u1 methods_String_StackCode = 2;
 static constexpr u1 methods_U4x1_StackCode = 3;
 static constexpr u1 methods_U4x4_StackCode = 4;

 methods_x0 get_method_x0(QString inst, _Module_Base*& module);
 methods_String get_method_String(QString inst, _Module_Base*& module);
 methods_U4x1 get_method_U4x1(QString inst, _Module_Base*& module);
 methods_U4x4 get_method_U4x4(QString inst, _Module_Base*& module);

// void ((VM_OpMethods::*get_method_x0)())(QString inst);
// void ((VM_OpMethods::*get_method_String)(QString))(QString inst);
// void ((VM_OpMethods::*get_method_U4x1)(u4 arg))(QString inst);
// void ((VM_OpMethods::*get_method_U4x4)(u4 arg1, u4 arg2, u4 arg3, u4 arg4))(QString inst);

};

_OTNS(DogPal)

#endif // VM_OPMETHODS__H
