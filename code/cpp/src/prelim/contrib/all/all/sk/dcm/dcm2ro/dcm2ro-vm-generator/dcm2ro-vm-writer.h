
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DCM2RO_VM_WRITER__H
#define DCM2RO_VM_WRITER__H

#include "accessors.h"

#include "global-types.h"

#include "flags.h"

#include "kans.h"

#include <QStringList>
#include <QTextStream>

#include "otns.h"

OTNS_(DCM2RO)


class VM_Writer
{
 QString main_process_vm_;
 QTextStream mvm_acc_;

 QString post_process_vm_;
 QTextStream pvm_acc_;

 QMap<QString, u1> current_characteristics_map_;

 void check_characteristics_map();
 void write_coord_pairs(const QVector<QPair<u2, u2>>& xys);

 u1 current_mask_;

 VM_Writer& mvm_opstatement(QString contents)
 {
  mvm_acc_ << "\n" << contents;
  current_mask_ = 1;
 }

 VM_Writer& pvm_opstatement(QString contents)
 {
  pvm_acc_ << "\n" << contents;
  current_mask_ = 2;
 }

 VM_Writer& mid(QString contents)
 {
  if(current_mask_ == 1)
    mvm_acc_ << " " << contents;
  else if(current_mask_ == 2)
    pvm_acc_ << " " << contents;
 }

 VM_Writer& end()
 {
  if(current_mask_ == 1)
    mvm_acc_ << " ;.";
  else if(current_mask_ == 2)
    pvm_acc_ << " ;.";

  current_mask_ = 0;
 }

 template<typename ARGS_Type>
 VM_Writer& args(QPair<ARGS_Type, ARGS_Type> pr)
 {
  if(current_mask_ == 1)
    mvm_acc_ << " %1 %2"_qt.arg(pr.first).arg(pr.second);
  else if(current_mask_ == 2)
    pvm_acc_ << " %1 %2"_qt.arg(pr.first).arg(pr.second);
 }


public:

 VM_Writer();

 ACCESSORS(QString ,main_process_vm)
 ACCESSORS(QString ,post_process_vm)

 void scan_xml(QString xml_path);

// ACCESSORS__RGET(QTextStream ,pvm_acc)


 VM_Writer& mraw(QString contents);
 VM_Writer& praw(QString contents);
 VM_Writer& braw(QString contents);


 VM_Writer& mraw_line(QString contents);
 VM_Writer& praw_line(QString contents);
 VM_Writer& braw_line(QString contents);




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


 void finalize_vm(QTextStream& qts)
 {
  qts << "\n\n=done\n\n";
 }

 void finalize_mvm()
 {
  finalize_vm(mvm_acc_);
 }

 void finalize_pvm()
 {
  finalize_vm(pvm_acc_);
 }

};

_OTNS(DCM2RO)


#endif
