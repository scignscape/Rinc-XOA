
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#include "vm-reader.h"

#include "textio.h"

USING_KANS(TextIO)

USING_OTNS(DogPal)

VM_Reader::VM_Reader()
 : current_pos_(0), opstatement_index_(0)//?, cache_index_(0)
{

}

VM_Opstatement VM_Reader::_EOF()
{
 VM_Opstatement result = VM_Opstatement(0, "<error>");
 result.set_control_coords(VM_Opstatement::Control_Coords::_EOF);
 return result;
}

void VM_Reader::load_file(QString path)
{
 file_path_ = path;
 file_contents_ = KA::TextIO::load_file(path);
}

VM_Opstatement VM_Reader::next_opstatement()
{
 if(opstatement_index_ == 0)
 {
  s4 pos = file_contents_.indexOf("=prog");
  if(pos == -1)
    return _EOF();
  ++opstatement_index_;
  current_pos_ = pos + 5;
  skip_space();
 }

 QString instruction = "=err";
 current_pos_ = advance_past_instruction(&instruction);

 if(instruction.startsWith("$.#"))
 {
  u4 cache_index = instruction.mid(3).toUInt();

  QString acc;
  current_pos_ = advance_past_cached_string(file_contents_, current_pos_, &acc);
  return VM_Opstatement(cache_index, acc, VM_Opstatement::Control_Coords::_Cached_String);
 }

 ++opstatement_index_;

 if(instruction.startsWith("="))
   return VM_Opstatement(opstatement_index_, instruction, VM_Opstatement::Control_Coords::_CMD);



 VM_Opstatement::Mid_Control_Kinds mck = VM_Opstatement::Mid_Control_Kinds::N_A;
 VM_Opstatement::Control_Coords cc = VM_Opstatement::Control_Coords::N_A;

 current_pos_ = advance_past_mid_control(mck, cc);

 VM_Opstatement result = VM_Opstatement(opstatement_index_, instruction, mck, cc);

 if(cc == VM_Opstatement::Control_Coords::x0 || cc == VM_Opstatement::Control_Coords::N_A)
   return result;

 QString params;
 current_pos_ = advance_past_end_control(&params);

 result.set_param(params);

 return result;
}

#define STATIC_BASIC_SPACE static QChar basic_space = QChar::fromLatin1(' ');
#define STATIC_END_CONTROL static QString end_control = ";.";
#define STATIC_NEWLINE_SPACE static QChar newline_space = QChar::fromLatin1('\n');

void VM_Reader::skip_space()
{
 STATIC_BASIC_SPACE
 STATIC_NEWLINE_SPACE

 while(file_contents_[current_pos_] == basic_space)
   ++current_pos_;

 while(file_contents_[current_pos_] == newline_space)
   ++current_pos_;
}


u4 VM_Reader::advance_past_cached_string(QString& basis, u4 start_pos, QString* result)
{
 STATIC_BASIC_SPACE
 STATIC_NEWLINE_SPACE

 u4 end_pos;
 while(true)
 {
  end_pos = basis.indexOf(newline_space, start_pos);
  QString line = basis.mid(start_pos + 3, end_pos - start_pos - 2);
  (*result) += line;

  if(basis[start_pos] == ".")
    break;

  start_pos = end_pos + 1;
 }


 return end_pos;
}


u4 _advance_past(QString& basis, QString* skipped, int ix0 = 0)
{
 STATIC_BASIC_SPACE
 STATIC_NEWLINE_SPACE

 int ix1 = basis.indexOf(basic_space, ix0);

 int ix1n = basis.indexOf(newline_space, ix0);


 if(ix1 == 0)
   return 0;

 if(ix1 == -1)
 {
  if(ix1n == -1)
    return 0;
  ix1 = ix1n;
 }
 else if(ix1n < ix1)
 {
  if(basis[ix0] == QChar('$'))
    ix1 = ix1n;
  else
    return 0;
 }

 int ix2 = ix1 + 1;

 while(basis[ix2] == basic_space)
   ++ix2;

 if(skipped)
   *skipped = basis.mid(ix0, ix1 - ix0);

 //?basis = basis.mid(ix2);

 return ix2;
}

u4 _advance_past_end(QString& basis, QString* skipped, int ix0 = 0)
{
 STATIC_BASIC_SPACE
 STATIC_END_CONTROL
 STATIC_NEWLINE_SPACE

 int ix1 = basis.indexOf(end_control, ix0);

 if(ix1 == 0)
   return 0;
 if(ix1 == -1)
   return 0;

 int ix01 = ix1 - 1;

 while(basis[ix01] == basic_space)
   --ix01;

 if(skipped)
   *skipped = basis.mid(ix0, ix01 - ix0 + 1);

 int ix2 = ix1 + 2;

 while(basis[ix2] == basic_space)
   ++ix2;

 if(basis[ix2] == newline_space)
   ++ix2;

 //?basis = basis.mid(ix2);

 return ix2;
}


u4 VM_Reader::advance_past_instruction(QString* skipped)
{
 STATIC_BASIC_SPACE

 while(file_contents_[current_pos_] == basic_space)
   ++current_pos_;

 return _advance_past(file_contents_, skipped, current_pos_);
}

u4 VM_Reader::advance_past_mid_control(QString* skipped)
{
 STATIC_BASIC_SPACE

 if(file_contents_[current_pos_] == ";" && file_contents_[current_pos_ + 1] == "." )
   return current_pos_ + 2;

 return _advance_past(file_contents_, skipped, current_pos_);
}

u4 VM_Reader::advance_past_mid_control(VM_Opstatement::Mid_Control_Kinds& mck, VM_Opstatement::Control_Coords& cc)
{
 static QMap<QString, VM_Opstatement::Mid_Control_Kinds> known_mid_controls {
   {"$", VM_Opstatement::Mid_Control_Kinds::String},
   {"$$", VM_Opstatement::Mid_Control_Kinds::String_List},
   {"$#", VM_Opstatement::Mid_Control_Kinds::Cached_String},
   {"1#", VM_Opstatement::Mid_Control_Kinds::U1},
   {"2#", VM_Opstatement::Mid_Control_Kinds::U2},
   {"4#", VM_Opstatement::Mid_Control_Kinds::U4},
   {"8#", VM_Opstatement::Mid_Control_Kinds::U8},
   {"1-#", VM_Opstatement::Mid_Control_Kinds::S1},
   {"2-#", VM_Opstatement::Mid_Control_Kinds::S2},
   {"4-#", VM_Opstatement::Mid_Control_Kinds::S4},
   {"8-#", VM_Opstatement::Mid_Control_Kinds::S8},

 };

 QString control;
 u4 result = advance_past_mid_control(&control);

 if(control.isEmpty())
   cc = VM_Opstatement::Control_Coords::x0;
 else
 {
  u2 cutpoint = control.size();
  if(cutpoint > 2)
  {
   if(control[cutpoint - 2] == QChar('/'))
   {
    u1 last = control[cutpoint - 1].toLatin1();
    switch (last)
    {
    case '2': cc = VM_Opstatement::Control_Coords::x2; break;
    case '3': cc = VM_Opstatement::Control_Coords::x3; break;
    case '4': cc = VM_Opstatement::Control_Coords::x4; break;
    default: cc = VM_Opstatement::Control_Coords::x1; break;
    }
    cutpoint -= 2;
   }
   else if(control[cutpoint - 2] == control[cutpoint - 1])
   {
    cc = VM_Opstatement::Control_Coords::List;
    cutpoint -= 1;
   }
   else if(control[cutpoint - 2] == QChar('*'))
   {
    if(control[cutpoint - 1] == "2")
      cc = VM_Opstatement::Control_Coords::Matrix;
    else
      cc = VM_Opstatement::Control_Coords::Tensor;
    cutpoint -= 2;
   }
  }
  else if(cutpoint == 2)
  {
   if(control[1] == "#")
     cc = VM_Opstatement::Control_Coords::x1;
  }
  else if(cutpoint == 1)
  {
   if(control[1] == "$")
     cc = VM_Opstatement::Control_Coords::x1;
  }

  QString control_key = control.left(cutpoint);
  mck = known_mid_controls.value(control_key, VM_Opstatement::Mid_Control_Kinds::N_A);
 }

 return result;
}


u4 VM_Reader::advance_past_end_control(QString* skipped)
{
 return _advance_past_end(file_contents_, skipped, current_pos_);
}

u4 VM_Reader::advance_past_end_control(QStringList* skipped)
{
 QString sk;
 u4 result = _advance_past(file_contents_, &sk);
 *skipped = sk.simplified().split(" ");
 return result;
}

u4 VM_Reader::advance_past_end_control(quint64* skipped)
{
 QString sk;
 u4 result = _advance_past(file_contents_, &sk);
 *skipped = sk.toULongLong();
 return result;
}

u4 VM_Reader::advance_past_end_control(qint64* skipped)
{
 QString sk;
 u4 result = _advance_past(file_contents_, &sk);
 *skipped = sk.toLongLong();
 return result;
}

u4 VM_Reader::advance_past_end_control(qreal* skipped)
{
 QString sk;
 u4 result = _advance_past(file_contents_, &sk);
 *skipped = sk.toDouble();
 return result;
}

u4 VM_Reader::advance_past_end_control(float* skipped)
{
 QString sk;
 u4 result = _advance_past(file_contents_, &sk);
 *skipped = sk.toFloat();
 return result;
}

