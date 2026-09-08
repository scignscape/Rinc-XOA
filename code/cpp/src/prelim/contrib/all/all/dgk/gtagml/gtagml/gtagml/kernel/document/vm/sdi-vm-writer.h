
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef SDI_VM_WRITER__H
#define SDI_VM_WRITER__H

#include "relae-graph/relae-node-ptr.h"

#include "accessors.h"

#include "global-types.h"

#include "flags.h"

#include "kans.h"

#include <QStringList>
#include <QTextStream>

KANS_(GTagML)


class GTagML_Parser;
class GTagML_Output_Blocks;


class SDI_VM_Writer
{
 QString avm_;
 QTextStream avm_acc_;

 QString svm_;
 QTextStream svm_acc_;

 u4 current_atext_block_id_;
 u4 current_stext_block_id_;


public:

 SDI_VM_Writer();

 ACCESSORS(QString ,svm)
 ACCESSORS(QString ,avm)
 ACCESSORS__GET(u4 ,current_atext_block_id)
 ACCESSORS__GET(u4 ,current_stext_block_id)

 SDI_VM_Writer& araw(QString contents);
 SDI_VM_Writer& sraw(QString contents);
 SDI_VM_Writer& braw(QString contents);

 SDI_VM_Writer& araw_line(QString contents);
 SDI_VM_Writer& sraw_line(QString contents);
 SDI_VM_Writer& braw_line(QString contents);

 void opstatement(QString contents, u1 mask);
 void opstatement(QString instruction, QString mid_control, QString parameter, u1 mask);
 void opstatement(QString instruction, QString parameter, u1 mask);
 void write_end_control(u1 mask);


//? QTextStream&
 void opstatement_to_mid(QString instruction, QString mid_control, u1 mask);

 void opstatement_u4(QString instruction, u4 parameter, u1 mask)
 {
  opstatement(instruction, "4#", QString::number(parameter), mask);
 }

 template<typename NUM_Type>
 void opstatement_u4s(QString instruction, QVector<NUM_Type> args, u1 mask)
 {
  if(args.count() > 4)
    opstatement_to_mid(instruction, "4##", mask);
  else
    opstatement_to_mid(instruction, "4#/" + QString::number(args.count()), mask);

  for(NUM_Type arg: args)
    braw(" ").braw(QString::number(arg));

  write_end_control(mask);
 }

 SDI_VM_Writer& blank_line()
 {
  return braw_line("");
 }

 void opstatement_text_block(QString instruction, u1 mask)
 {
  if(mask & 1)
    opstatement_text_block(instruction, current_stext_block_id_, 1);
  if(mask & 2)
    opstatement_text_block(instruction, current_atext_block_id_, 2);
 }

 void opstatement_text_block(QString instruction, u4 parameter, u1 mask)
 {
  opstatement(instruction, "$#", QString::number(parameter), mask);
 }

 void write_text_block(QString contents, u1 mask);

 void finalize_svm()
 {
  svm_acc_ << "\n\n=done\n";
 }

 void finalize_avm()
 {
  avm_acc_ << "\n\n=done\n";
 }

};

_KANS(GTagML)


#endif
