
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#include "vm-opmethods.h"

#include "modules/sdi-module.h"
#include "modules/tao-module.h"

#include "textio.h"

USING_KANS(TextIO)

USING_OTNS(DogPal)

VM_OpMethods::VM_OpMethods()
{

}

u1 VM_OpMethods::get_module_index(_Module_Base* module)
{
 static QMap<_Module_Base*, u1> static_map {
  { static_cast<_Module_Base*>(sdi_module_), 1},
  { static_cast<_Module_Base*>(tao_module_), 2},
 };

 return static_map.value(module);
}

_Module_Base* VM_OpMethods::get_module_by_index(u1 index)
{
 switch (index)
 {
 case 1: return static_cast<_Module_Base*>(sdi_module_);
 case 2: return static_cast<_Module_Base*>(tao_module_);
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
   {"sdi", sdi_module_},
   {"tao", tao_module_},
 };

 return modules_map.value(module_code);
}


VM_OpMethods::methods_x0 VM_OpMethods::get_method_x0(QString instr, _Module_Base*& module)
{
 QMap<QString, methods_x0> static_map {
#define METHOD_Empty
#include "modules/sdi-module.cxx"
#include "modules/tao-module.cxx"
#undef METHOD_Empty

//   {"tao-test-empty", (methods_x0) &TAO_Module::test_empty},
 };

 module = get_module_from_instruction(instr);

 auto it = static_map.find(instr);
 if(it == static_map.end())
   return nullptr;
 return *it;
}

VM_OpMethods::methods_String VM_OpMethods::get_method_String(QString instr, _Module_Base*& module)
{
 QMap<QString, methods_String> static_map {
#define METHOD_String
#include "modules/sdi-module.cxx"
#include "modules/tao-module.cxx"
#undef METHOD_String

//   {"sdi-sentence-end-punctuation", (methods_String) &SDI_Module::sentence_end_punctuation},
//   {"sdi-sentence-text", (methods_String) &SDI_Module::sentence_text},

//   {"tao-restrict-to-layer", (methods_String) &TAO_Module::restrict_to_layer}
 };

 module = get_module_from_instruction(instr);

 auto it = static_map.find(instr);
 if(it == static_map.end())
   return nullptr;
 return *it;

// QMap<SQstring, methods_x0> static_map {
//   {}
// };
}

VM_OpMethods::methods_U4x1 VM_OpMethods::get_method_U4x1(QString instr, _Module_Base*& module)
{
 QMap<QString, methods_U4x1> static_map {
#define METHOD_U4x1
#include "modules/sdi-module.cxx"
#include "modules/tao-module.cxx"
#undef METHOD_U4x1

//?   {"sdi-new-sentence", (methods_U4x1) &SDI_Module::new_sentence}
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
#define METHOD_U4x4
#include "modules/sdi-module.cxx"
#include "modules/tao-module.cxx"
#undef METHOD_U4x1


//   {"sdi-sentence-end-pos", (methods_U4x4) &SDI_Module::sentence_end_pos},
//   {"sdi-sentence--end-pos", (methods_U4x4) &SDI_Module::sentence__end_pos},
//   {"sdi-sentence-switch-pos", (methods_U4x4) &SDI_Module::sentence_switch_pos},

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

