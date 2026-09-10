
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef VM_OPMETHODS__H
#define VM_OPMETHODS__H

#include "global-types.h"

#include "global-macros.h"

#include "vm-reader.h"
#include "vm-opstatement.h"

#include "modules/module-base.h"

#include "otns.h"

OTNS_(DogPal)


//#define MODULE_LIST_UC(X) _MACRO_EXPAND(X, ASL, RCS, SDI, TAO)
//#define MODULE_LIST_LC(X) _MACRO_EXPAND(X, asl, rcs, sdi, tao)

#define MODULE_LIST(X, ALT) _MACRO_EXPAND_ALT(X, ALT,\
  ASL, asl,  RCS, rcs, SDI, sdi, TAO, tao)

#define MODULE_LIST_PAIRED(X) MODULE_LIST(X, PAIRED)
#define MODULE_LIST_UC(X) MODULE_LIST(X, ODDS)
#define MODULE_LIST_LC(X) MODULE_LIST(X, EVENS)
#define MODULE_LIST_LC_INDEXED(X) MODULE_LIST(X, EVENS_INDEXED)
#define MODULE_LIST_LC_INCLUDES(X) MODULE_LIST(X, EVENS_INCLUDES)


#define MODULE_CLASS_DECLARE(x) class x##_Module;
MODULE_LIST_UC(MODULE_CLASS_DECLARE)

class VM_OpMethods
{
 #define MODULE_MEMBER(type, member) type##_Module* member##_module##_;
 MODULE_LIST_PAIRED(MODULE_MEMBER)



public:

 VM_OpMethods();

#define MODULE_MEMBER(type, member) ACCESSORS(type##_Module* ,member##_module)
MODULE_LIST_PAIRED(MODULE_MEMBER)

// ACCESSORS(ASL_Module* ,asl_module)
// ACCESSORS(RCS_Module* ,rcs_module)
// ACCESSORS(SDI_Module* ,sdi_module)
// ACCESSORS(TAO_Module* ,tao_module)

 u1 get_module_index(_Module_Base* module);

 _Module_Base* get_module_by_index(u1 index);

 _Module_Base* get_module_from_instruction(QString instr);

 enum class Signatures {
   N_A, x0, String, StringList, U2x2, U4x1, U4x4, N8x1
 };

// void sdi_new_sentence(u4 id);
// void sdi_sentence_switch_pos(u4 id, u4 pos, u4 row, u4 col);
// void sdi_sentence__end_pos(u4 id, u4 pos, u4 row, u4 col);
// void sdi_sentence_end_pos(u4 id, u4 pos, u4 row, u4 col);
// void sdi_sentence_end_punctuation(QString mark);
// void sdi_sentence_text(QString text);

 typedef void (_Module_Base::*methods_x0)();
 typedef void (_Module_Base::*methods_String)(QString);
 typedef void (_Module_Base::*methods_StringList)(QStringList);
 typedef void (_Module_Base::*methods_U4x1)(u4 arg);
 typedef void (_Module_Base::*methods_U2x1)(u2 arg);
 typedef void (_Module_Base::*methods_N8x1)(n8 arg);
 typedef void (_Module_Base::*methods_U2x2)(u2 arg1, u2 arg2);
 typedef void (_Module_Base::*methods_U4x4)(u4 arg1, u4 arg2, u4 arg3, u4 arg4);

 typedef methods_x0 methods_x0_opstatement_type;
 typedef QPair<methods_String, QString> methods_String_opstatement_type;
 typedef QPair<methods_StringList, QStringList> methods_StringList_opstatement_type;
 typedef QPair<methods_N8x1, n8> methods_N8x1_opstatement_type;
 typedef QPair<methods_U4x1, u4> methods_U4x1_opstatement_type;
 typedef QPair<methods_U4x4, QVector<u4>> methods_U4x4_opstatement_type;
 typedef QPair<methods_U2x2, QVector<u2>> methods_U2x2_opstatement_type;
 typedef QPair<methods_U2x1, u2> methods_U2x1_opstatement_type;

 static constexpr u1 methods_x0_StackCode = 1;
 static constexpr u1 methods_String_StackCode = 2;
 static constexpr u1 methods_StringList_StackCode = 3;
 static constexpr u1 methods_U2x1_StackCode = 4;
 static constexpr u1 methods_U2x2_StackCode = 5;
 static constexpr u1 methods_U4x1_StackCode = 6;
 static constexpr u1 methods_N8x1_StackCode = 7;
 static constexpr u1 methods_U4x4_StackCode = 8;

 methods_x0 get_method_x0(QString inst, _Module_Base*& module);
 methods_String get_method_String(QString inst, _Module_Base*& module);
 methods_StringList get_method_StringList(QString inst, _Module_Base*& module);
 methods_U2x1 get_method_U2x1(QString inst, _Module_Base*& module);
 methods_U4x1 get_method_U4x1(QString inst, _Module_Base*& module);
 methods_N8x1 get_method_N8x1(QString inst, _Module_Base*& module);
 methods_U2x2 get_method_U2x2(QString inst, _Module_Base*& module);
 methods_U4x4 get_method_U4x4(QString inst, _Module_Base*& module);

// void ((VM_OpMethods::*get_method_x0)())(QString inst);
// void ((VM_OpMethods::*get_method_String)(QString))(QString inst);
// void ((VM_OpMethods::*get_method_U4x1)(u4 arg))(QString inst);
// void ((VM_OpMethods::*get_method_U4x4)(u4 arg1, u4 arg2, u4 arg3, u4 arg4))(QString inst);

};

_OTNS(DogPal)

#endif // VM_OPMETHODS__H
