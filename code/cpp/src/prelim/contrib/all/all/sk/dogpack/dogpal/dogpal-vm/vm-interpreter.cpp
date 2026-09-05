
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#include "vm-interpreter.h"

#include "vm-opmethods.h"

#include "textio.h"

USING_KANS(TextIO)

USING_OTNS(DogPal)

VM_Interpreter::VM_Interpreter()
 :  current_proc_name_ops_(ops_by_proc_name_["<main>"])
{

}


void VM_Interpreter::load_file(QString path)
{
 reader_.load_file(path);
}

void VM_Interpreter::parse()
{
 while (true)
 {
  VM_Opstatement opst = reader_.next_opstatement();

  switch(opst.control_coords())
  {
  case VM_Opstatement::Control_Coords::x0:
   parse_x0(opst); break;
  case VM_Opstatement::Control_Coords::x1:
   parse_x1(opst); break;
  case VM_Opstatement::Control_Coords::x2:
   parse_x2(opst); break;
  case VM_Opstatement::Control_Coords::x3:
   parse_x3(opst); break;
  case VM_Opstatement::Control_Coords::x4:
   parse_x4(opst); break;

  case VM_Opstatement::Control_Coords::List:
   parse_List(opst); break;


  }
 }
}

template<typename FN_Type, typename... ARGS>
void VM_Interpreter::parse_fn(FN_Type fn, const VM_Opstatement& opst, ARGS... args)
{
 auto pr = dispatcher_.get_vector(opst.mid_control_kind(), opst.control_coords(), fn, args...);
 current_proc_name_ops_.push_back(pr);
}

//template<typename FN_Type>
//void VM_Interpreter::parse_fn(FN_Type fn, const VM_Opstatement& opst)
//{
// auto pr = dispatcher_.get_vector(opst.mid_control_kind(), opst.control_coords(), fn);
// current_proc_name_ops_.push_back(pr);
//}



void VM_Interpreter::parse_x0(const VM_Opstatement& opst)
{

}

void VM_Interpreter::parse_x1(const VM_Opstatement& opst)
{
 switch (opst.mid_control_kind())
 {
 case VM_Opstatement::Mid_Control_Kinds::String:
 {
  VM_OpMethods::methods_String fn = VM_OpMethods::get_method_String(opst.instruction());
  parse_fn(fn, opst);
  break;
 }
 case VM_Opstatement::Mid_Control_Kinds::U4:
 {
  u4 arg = opst.param().toUInt();
  VM_OpMethods::methods_U4x1 fn = VM_OpMethods::get_method_U4x1(opst.instruction());
  parse_fn(fn, opst, arg);
  break;
 }
 default:
  break;
 }
}

void VM_Interpreter::parse_x2(const VM_Opstatement& opst)
{

}

void VM_Interpreter::parse_x3(const VM_Opstatement& opst)
{

}

void VM_Interpreter::parse_x4(const VM_Opstatement& opst)
{
 switch (opst.mid_control_kind())
 {
 case VM_Opstatement::Mid_Control_Kinds::U4:
 {
  VM_OpMethods::methods_U4x4 fn = VM_OpMethods::get_method_U4x4(opst.instruction());
  parse_fn(fn, opst);
  //   auto pr = dispatcher_.get_vector(opst.mid_control_kind(), opst.control_coords(), fn, opst.param());
  break;
 }
 default:
  break;
 }

}

void VM_Interpreter::parse_List(const VM_Opstatement& opst)
{

}
