
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "sdi-vm-writer.h"


#include <QFile>
#include <QTextStream>

#include "kans.h"

USING_KANS(GTagML)


SDI_VM_Writer::SDI_VM_Writer()
  :  vm_acc_(&vm_), current_text_block_id_(0)
{
}

void SDI_VM_Writer::write_text_block(QString contents)
{
 ++current_text_block_id_;

 vm_acc_ << "$.#" << current_text_block_id_ << "\n";

 contents.replace("\n", "\n|  ");
 contents.prepend("|  ");

 s4 ix = contents.lastIndexOf("\n|  ");
 contents[ix + 1] = '.';
 raw_line(contents);
 //vm_acc_ << ".#" << current_text_block_id_ << "\n";
}

SDI_VM_Writer& SDI_VM_Writer::raw(QString contents)
{
 vm_acc_ << contents;
 return *this;
}

SDI_VM_Writer& SDI_VM_Writer::raw_line(QString contents)
{
 vm_acc_ << contents << "\n";
 return *this;
}

void SDI_VM_Writer::write_end_control()
{
 vm_acc_ << " ;.\n";
}

void SDI_VM_Writer::opstatement(QString contents)
{
 vm_acc_ << contents << " ;.\n";
}

QTextStream& SDI_VM_Writer::opstatement_to_mid(QString instruction, QString mid_control)
{
 vm_acc_ << instruction << " " << mid_control;
 return vm_acc_;
}


void SDI_VM_Writer::opstatement(QString instruction, QString mid_control, QString parameter)
{
 vm_acc_ << instruction << " " << mid_control
   << " " << parameter << " ;.\n";
}

void SDI_VM_Writer::opstatement(QString instruction, QString parameter)
{
 opstatement(instruction, "$", parameter);
}

