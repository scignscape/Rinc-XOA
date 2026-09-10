
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#include "vm-opmethods.h"

#include "modules/asl-module.h"
#include "modules/rcs-module.h"
#include "modules/sdi-module.h"
#include "modules/tao-module.h"

#define MODULE_LIST_INCLUDE(m) "modules/m##-module.h"

//MODULE_LIST_LC_INCLUDES(MODULE_LIST_INCLUDE)

//MACRO_EXPAND_EVENS_INCLUDES_8(MODULE_LIST_INCLUDE, ASL, asl,  RCS, rcs, SDI, sdi, TAO, tao)

#include "textio.h"

USING_KANS(TextIO)

USING_OTNS(DogPal)

VM_OpMethods::VM_OpMethods()
{
#define MODULE_MEMBER_INIT(type, member) member##_module##_ = new type##_Module;
MODULE_LIST_PAIRED(MODULE_MEMBER_INIT)


// asl_module_ = new ASL_Module;
// rcs_module_ = new RCS_Module;
// sdi_module_ = new SDI_Module;
// tao_module_ = new TAO_Module;

}

u1 VM_OpMethods::get_module_index(_Module_Base* module)
{
#define MODULE_MEMBER_INDEX(index, m) \
 { static_cast<_Module_Base*>(m##_module_), index},

 static QMap<_Module_Base*, u1> static_map {
  MODULE_LIST_LC_INDEXED(MODULE_MEMBER_INDEX)
 };

 return static_map.value(module);
}

_Module_Base* VM_OpMethods::get_module_by_index(u1 index)
{
#define MODULE_MEMBER_CASE(index, m) \
 case index: return static_cast<_Module_Base*>(m##_module_);

 switch (index)
 {
 MODULE_LIST_LC_INDEXED(MODULE_MEMBER_CASE)

 default: return nullptr;
 }
}

//void VM_OpMethods::sdi_new_sentence(u4 id)
//{

//}

//void VM_OpMethods::sdi_sentence_switch_pos(u4 id, u4 pos, u4 row, u4 col)
//{

//}

//void VM_OpMethods::sdi_sentence__end_pos(u4 id, u4 pos, u4 row, u4 col)
//{

//}

//void VM_OpMethods::sdi_sentence_end_pos(u4 id, u4 pos, u4 row, u4 col)
//{

//}

//void VM_OpMethods::sdi_sentence_end_punctuation(QString mark)
//{

//}

//void VM_OpMethods::sdi_sentence_text(QString text)
//{

//}

//void ((VM_OpMethods::*)() get_method_x0)(QString inst);


_Module_Base* VM_OpMethods::get_module_from_instruction(QString instr)
{
 int ix = instr.indexOf(QChar('-'));

 QString module_code = instr.left(ix);

 static QMap<QString, _Module_Base*> modules_map {
   {"asl", asl_module_},
   {"rcs", rcs_module_},
   {"sdi", sdi_module_},
   {"tao", tao_module_},

 };

 return modules_map.value(module_code);
}


VM_OpMethods::methods_x0 VM_OpMethods::get_method_x0(QString instr, _Module_Base*& module)
{
 QMap<QString, methods_x0> static_map {
#define METHODS_Empty 1
#include "modules/asl-module.cxx"
#include "modules/rcs-module.cxx"
#include "modules/sdi-module.cxx"
#include "modules/tao-module.cxx"
#undef METHODS_Empty

//   {"tao-test-empty", (methods_x0) &TAO_Module::test_empty},
 };

 module = get_module_from_instruction(instr);

 auto it = static_map.find(instr);
 if(it == static_map.end())
   return nullptr;
 return *it;
}

//primary-acc-cached $# 10 ;.
//end-sentence $  ;.
//primary-acc-spaces 8# 1 ;.
//end-sentence $ . ;.
//primary-acc $  All of the eligible bachelors in this town are married ;.
//primary-acc-spaces 8# 3 ;.
//leave-element $ exsGroup-list ;.
//leave-subparagraph-with-continue ;.

VM_OpMethods::methods_String VM_OpMethods::get_method_String(QString instr, _Module_Base*& module)
{
 QMap<QString, methods_String> static_map {
#define METHODS_String 1
#include "modules/asl-module.cxx"
#include "modules/rcs-module.cxx"
#include "modules/sdi-module.cxx"
#include "modules/tao-module.cxx"
#undef METHODS_String
 };

 module = get_module_from_instruction(instr);

 auto it = static_map.find(instr);
 if(it == static_map.end())
   return nullptr;
 return *it;

}

VM_OpMethods::methods_StringList VM_OpMethods::get_method_StringList(QString instr, _Module_Base*& module)
{
 QMap<QString, methods_StringList> static_map {
#define METHODS_StringList 1
#include "modules/asl-module.cxx"
#include "modules/rcs-module.cxx"
#include "modules/sdi-module.cxx"
#include "modules/tao-module.cxx"
#undef METHODS_StringList
 };

 module = get_module_from_instruction(instr);

 auto it = static_map.find(instr);
 if(it == static_map.end())
   return nullptr;
 return *it;

}


VM_OpMethods::methods_U4x1 VM_OpMethods::get_method_U4x1(QString instr, _Module_Base*& module)
{
 QMap<QString, methods_U4x1> static_map {
#define METHODS_U4x1 1
#include "modules/asl-module.cxx"
#include "modules/rcs-module.cxx"
#include "modules/sdi-module.cxx"
#include "modules/tao-module.cxx"
#undef METHODS_U4x1
 };

 module = get_module_from_instruction(instr);

 auto it = static_map.find(instr);
 if(it == static_map.end())
   return nullptr;
 return *it;

}

VM_OpMethods::methods_U2x1 VM_OpMethods::get_method_U2x1(QString instr, _Module_Base*& module)
{
 QMap<QString, methods_U2x1> static_map {
#define METHODS_U2x1 1
#include "modules/asl-module.cxx"
#include "modules/rcs-module.cxx"
#include "modules/sdi-module.cxx"
#include "modules/tao-module.cxx"
#undef METHODS_U2x1
 };

 module = get_module_from_instruction(instr);

 auto it = static_map.find(instr);
 if(it == static_map.end())
   return nullptr;
 return *it;

}

VM_OpMethods::methods_N8x1 VM_OpMethods::get_method_N8x1(QString instr, _Module_Base*& module)
{
 QMap<QString, methods_N8x1> static_map {
#define METHODS_N8x1 1
#include "modules/asl-module.cxx"
#include "modules/rcs-module.cxx"
#include "modules/sdi-module.cxx"
#include "modules/tao-module.cxx"
#undef METHODS_N8x1

//?   {"sdi-new-sentence", (methods_U4x1) &SDI_Module::new_sentence}
 };

 module = get_module_from_instruction(instr);

 auto it = static_map.find(instr);
 if(it == static_map.end())
   return nullptr;
 return *it;

}


VM_OpMethods::methods_U2x2 VM_OpMethods::get_method_U2x2(QString instr, _Module_Base*& module)
{
 static QMap<QString, methods_U2x2> static_map {
#define METHODS_U2x2 1
#include "modules/asl-module.cxx"
#include "modules/rcs-module.cxx"
#include "modules/sdi-module.cxx"
#include "modules/tao-module.cxx"
#undef METHODS_U2x2
 };

 module = get_module_from_instruction(instr);

 auto it = static_map.find(instr);
 if(it == static_map.end())
   return nullptr;
 return *it;
}


VM_OpMethods::methods_U4x4 VM_OpMethods::get_method_U4x4(QString instr, _Module_Base*& module)
{
 static QMap<QString, methods_U4x4> static_map {
#define METHODS_U4x4 1
#include "modules/asl-module.cxx"
#include "modules/rcs-module.cxx"
#include "modules/sdi-module.cxx"
#include "modules/tao-module.cxx"
#undef METHODS_U4x4
 };

 module = get_module_from_instruction(instr);

 auto it = static_map.find(instr);
 if(it == static_map.end())
   return nullptr;
 return *it;
}

//void ((VM_OpMethods::*get_method_x0)())(QString inst)
//{
// return nullptr;
//}
//void (VM_OpMethods::*get_method_String)() (QString inst);
//void (VM_OpMethods::*get_method_U4x1)() (QString inst);
//void (VM_OpMethods::*get_method_U4x4)() (QString inst);

