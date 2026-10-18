
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dcm2ro-vm-writer.h"


#include <QFile>
#include <QTextStream>

#include <QDateTime>


#include "otns.h"

USING_OTNS(DCM2RO)


VM_Writer::VM_Writer()
  :  mvm_acc_(&main_process_vm_), pvm_acc_(&post_process_vm_)
{
 auto init_stream = [](QTextStream& acc)
 {
  acc << "\n.; Generated on " << QDateTime::currentDateTime().toString() << " ;.\n\n"
              << "=prog\n\n";
 };

 init_stream(mvm_acc_);
 init_stream(pvm_acc_);
}


VM_Writer& VM_Writer::mraw(QString contents)
{
 mvm_acc_ << contents;
 return *this;
}

VM_Writer& VM_Writer::praw(QString contents)
{
 pvm_acc_ << contents;
 return *this;
}

VM_Writer& VM_Writer::braw(QString contents)
{
 mvm_acc_ << contents;
 pvm_acc_ << contents;
 return *this;
}

VM_Writer& VM_Writer::mraw_line(QString contents)
{
 mvm_acc_ << contents << "\n";
 return *this;
}

VM_Writer& VM_Writer::praw_line(QString contents)
{
 pvm_acc_ << contents << "\n";
 return *this;
}

VM_Writer& VM_Writer::braw_line(QString contents)
{
 mvm_acc_ << contents << "\n";
 pvm_acc_ << contents << "\n";
 return *this;
}

void VM_Writer::write_end_control(u1 mask)
{
 if(mask & 1)
   mvm_acc_ << " ;.\n";
 if(mask & 2)
   pvm_acc_ << " ;.\n";
}

void VM_Writer::opstatement(QString contents, u1 mask)
{
 if(mask & 1)
   mvm_acc_ << "tao-" << contents << " ;.\n";
 if(mask & 2)
   pvm_acc_ << "asa-" << contents << " ;.\n";
}

//QTextStream&
void VM_Writer::opstatement_to_mid(QString instruction, QString mid_control, u1 mask)
{
 if(mask & 1)
   mvm_acc_ << "tao-" << instruction << " " << mid_control;
 if(mask & 2)
   pvm_acc_ << "asa-" << instruction << " " << mid_control;
}


void VM_Writer::opstatement(QString instruction, QString mid_control, QString parameter, u1 mask)
{
 if(mask & 1)
   mvm_acc_ << "tao-" << instruction << " " << mid_control
     << " " << parameter << " ;.\n";
 if(mask & 2)
   pvm_acc_ << "asa-" << instruction << " " << mid_control
     << " " << parameter << " ;.\n";
}

void VM_Writer::opstatement(QString instruction, QString parameter, u1 mask)
{
 opstatement(instruction, "$", parameter, mask);
}

