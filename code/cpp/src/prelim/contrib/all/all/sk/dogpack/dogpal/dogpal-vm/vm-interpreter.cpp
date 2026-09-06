
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#include "vm-interpreter.h"

#include "vm-opmethods.h"

#include "modules/sdi-module.h"
#include "modules/tao-module.h"

#include <functional>

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
  case VM_Opstatement::Control_Coords::_EOF:
   break;
  case VM_Opstatement::Control_Coords::_CMD:
   if(opst.instruction() == "=done")
     goto break_outer;
  case VM_Opstatement::Control_Coords::_Comment:
   break;
  case VM_Opstatement::Control_Coords::_Cached_String:
   parse_cached_string(opst); break;
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
break_outer:
 return;
}

void VM_Interpreter::run_op_pair(QPair<void*, u4> pr)
{
 auto which_pr = decode_which_stack(pr.second);
 u1 stack_code = which_pr.first;
 _Module_Base* module = which_pr.second;

 switch(stack_code)
 {
 case VM_OpMethods::methods_String_StackCode:
 {
  auto op_pair = (*(QVector<VM_OpMethods::methods_String_opstatement_type>*)pr.first)[pr.second];


//?  std::invoke(op_pair.first, methods_.sdi_module(), op_pair.second);

  std::invoke(op_pair.first, module, op_pair.second);
  //(methods_.sdi_module()->*op_pair.first)(op_pair.second);
   break;
 }
 case VM_OpMethods::methods_U4x1_StackCode:
 {
  auto op_pair = (*(QVector<VM_OpMethods::methods_U4x1_opstatement_type>*)pr.first)[pr.second];
  std::invoke(op_pair.first, module, op_pair.second);
//  (methods_.sdi_module()->*op_pair.first)(op_pair.second);
   break;
 }
 case VM_OpMethods::methods_U4x4_StackCode:
 {
  auto op_pair = (*(QVector<VM_OpMethods::methods_U4x4_opstatement_type>*)pr.first)[pr.second];
  std::invoke(op_pair.first, module,
    op_pair.second[0], op_pair.second[1], op_pair.second[2], op_pair.second[3]);
//  (methods_.sdi_module()->*op_pair.first)(op_pair.second[0], op_pair.second[1], op_pair.second[2], op_pair.second[3]);
   break;
 }
 case VM_OpMethods::methods_x0_StackCode:
 {
  auto op = (*(QVector<VM_OpMethods::methods_x0_opstatement_type>*)pr.first)[pr.second];
  std::invoke(op, module);
//  (methods_.sdi_module()->*op_pair)();
   break;
 }
 default: break;
 }
}

void VM_Interpreter::run_proc(QString proc_name)
{
 QVector<QPair<void*, u4>> ops = ops_by_proc_name_.value(proc_name);

 for(auto pr : ops)
 {
  run_op_pair(pr);
 }
}

template<typename FN_Type, typename... ARGS>
void VM_Interpreter::parse_fn(FN_Type fn, const VM_Opstatement& opst, ARGS... args)
{
//? auto fns = swap_member_class_t<FN_Type, _Module_Base>(fn);

 auto pr = dispatcher_.get_vector(opst.mid_control_kind(), opst.control_coords(), fn, args...);
 current_proc_name_ops_.push_back(pr);
}

//template<typename FN_Type>
//void VM_Interpreter::parse_fn(FN_Type fn, const VM_Opstatement& opst)
//{
// auto pr = dispatcher_.get_vector(opst.mid_control_kind(), opst.control_coords(), fn);
// current_proc_name_ops_.push_back(pr);
//}



void VM_Interpreter::parse_cached_string(const VM_Opstatement& opst)
{
 if(cached_strings_.size() < opst.id())
   cached_strings_.resize(opst.id());
 cached_strings_[opst.id() - 1] = opst.instruction();
}

void VM_Interpreter::parse_x0(const VM_Opstatement& opst)
{

}

void VM_Interpreter::encode_which_stack(u1 num, _Module_Base* module)
{
 u4& number = current_proc_name_ops_.last().second;
 number <<= 5;
 number |= num;

 u1 c = methods_.get_module_index(module);

 number <<= 5;
 number |= methods_.get_module_index(module);

}

QPair<u1, _Module_Base*> VM_Interpreter::decode_which_stack(u4& number)
{
 u1 module_index = number & 0b00011111;
 number >>= 5;

 u1 result = number & 0b00011111;
 number >>= 5;

 _Module_Base* module = methods_.get_module_by_index(module_index);

 return {result, module};
}


void VM_Interpreter::parse_x1(const VM_Opstatement& opst)
{
 _Module_Base* module = nullptr;
 switch (opst.mid_control_kind())
 {
 case VM_Opstatement::Mid_Control_Kinds::Cached_String:
 {
  VM_OpMethods::methods_String fn = methods_.get_method_String(opst.instruction(), module);
  VM_Opstatement copy = opst.copy_as_string();
  QString cs = cached_strings_[opst.param().toUInt() - 1];
  parse_fn(fn, copy, cs);
  encode_which_stack(VM_OpMethods::methods_String_StackCode, module);
  break;
 }
 case VM_Opstatement::Mid_Control_Kinds::String:
 {
  VM_OpMethods::methods_String fn = methods_.get_method_String(opst.instruction(), module);
  parse_fn(fn, opst, opst.param());
  encode_which_stack(VM_OpMethods::methods_String_StackCode, module);
  break;
 }
 case VM_Opstatement::Mid_Control_Kinds::U4:
 {
  u4 arg = opst.param().toUInt();
  VM_OpMethods::methods_U4x1 fn = methods_.get_method_U4x1(opst.instruction(), module);
  parse_fn(fn, opst, arg);
  encode_which_stack(VM_OpMethods::methods_U4x1_StackCode, module);
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

u4 QString_to_u4(const QString& basis)
{
 return basis.toUInt();
}

void VM_Interpreter::parse_x4(const VM_Opstatement& opst)
{
 _Module_Base* module;

 switch (opst.mid_control_kind())
 {
 case VM_Opstatement::Mid_Control_Kinds::U4:
 {
  QStringList qsl = opst.param().simplified().split(" ");
  QVector<u4> args(4);
  std::transform(qsl.begin(), qsl.end(), args.begin(), &QString_to_u4);

  VM_OpMethods::methods_U4x4 fn = methods_.get_method_U4x4(opst.instruction(), module);
  parse_fn(fn, opst, args);
  encode_which_stack(VM_OpMethods::methods_U4x4_StackCode, module);

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
