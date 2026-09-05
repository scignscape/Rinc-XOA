
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#include "vm-opmethods.h"

#include "textio.h"

USING_KANS(TextIO)

USING_OTNS(DogPal)

VM_OpMethods::VM_OpMethods()
{

}

void VM_OpMethods::sdi_new_sentence(u4 id)
{

}

void VM_OpMethods::sdi_sentence_switch_pos(u4 id, u4 pos, u4 row, u4 col)
{

}

void VM_OpMethods::sdi_sentence__end_pos(u4 id, u4 pos, u4 row, u4 col)
{

}

void VM_OpMethods::sdi_sentence_end_pos(u4 id, u4 pos, u4 row, u4 col)
{

}

void VM_OpMethods::sdi_sentence_end_punctuation(QString mark)
{

}

void VM_OpMethods::sdi_sentence_text(QString text)
{

}

//void ((VM_OpMethods::*)() get_method_x0)(QString inst);

VM_OpMethods::methods_x0 VM_OpMethods::get_method_x0(QString inst)
{
 return nullptr;
}

VM_OpMethods::methods_String VM_OpMethods::get_method_String(QString inst)
{
 QMap<QString, methods_String> static_map {
   {"sdi-sentence-end-punctuation", &VM_OpMethods::sdi_sentence_end_punctuation},
   {"sdi-sentence-text", &VM_OpMethods::sdi_sentence_text}

 };

 auto it = static_map.find(inst);
 if(it == static_map.end())
   return nullptr;
 return *it;

// QMap<SQstring, methods_x0> static_map {
//   {}
// };
}

VM_OpMethods::methods_U4x1 VM_OpMethods::get_method_U4x1(QString inst)
{
 QMap<QString, methods_U4x1> static_map {
   {"sdi-new-sentence", &VM_OpMethods::sdi_new_sentence}
 };

 auto it = static_map.find(inst);
 if(it == static_map.end())
   return nullptr;
 return *it;

}

VM_OpMethods::methods_U4x4 VM_OpMethods::get_method_U4x4(QString inst)
{
 QMap<QString, methods_U4x4> static_map {
   {"sdi-sentence-end-pos", &VM_OpMethods::sdi_sentence_end_pos},
   {"sdi-sentence--end-pos", &VM_OpMethods::sdi_sentence__end_pos},
   {"sdi-sentence-switch-pos", &VM_OpMethods::sdi_sentence_switch_pos},

 };

 auto it = static_map.find(inst);
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

