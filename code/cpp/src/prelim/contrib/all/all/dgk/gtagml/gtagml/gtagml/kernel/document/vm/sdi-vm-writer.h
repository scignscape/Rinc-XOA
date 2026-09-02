
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
 QString vm_;
 QTextStream vm_acc_;

 u4 current_text_block_id_;


public:

 SDI_VM_Writer();

 ACCESSORS(QString ,vm)
 ACCESSORS__GET(u4 ,current_text_block_id)

 SDI_VM_Writer& raw(QString contents);
 SDI_VM_Writer& raw_line(QString contents);

 void opstatement(QString contents);
 void opstatement(QString instruction, QString mid_control, QString parameter);
 void opstatement(QString instruction, QString parameter);
 void write_end_control();


 QTextStream& opstatement_to_mid(QString instruction, QString mid_control);

 void opstatement_u4(QString instruction, u4 parameter)
 {
  opstatement(instruction, "4#", QString::number(parameter));
 }

 template<typename NUM_Type>
 void opstatement_u4s(QString instruction, QVector<NUM_Type> args)
 {
  opstatement_to_mid(instruction, "4##");
  for(NUM_Type arg: args)
    raw(" ").raw(QString::number(arg));
  write_end_control();
 }

 SDI_VM_Writer& blank_line()
 {
  return raw_line("");
 }

 void opstatement_text_block(QString instruction)
 {
  opstatement_text_block(instruction, current_text_block_id_);
 }

 void opstatement_text_block(QString instruction, u4 parameter)
 {
  opstatement(instruction, "$#", QString::number(parameter));
 }

 void write_text_block(QString contents);

};

_KANS(GTagML)


#endif
