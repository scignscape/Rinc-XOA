
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
  :  svm_acc_(&svm_), avm_acc_(&avm_), current_stext_block_id_(0),
     current_atext_block_id_(0)
{
}

void SDI_VM_Writer::write_text_block(QString contents, u1 mask)
{
 if(mask & 1)
 {
  ++current_stext_block_id_;
  svm_acc_ << "$.#" << current_stext_block_id_ << "\n";
 }

 if(mask & 2)
 {
  ++current_atext_block_id_;
  avm_acc_ << "$.#" << current_atext_block_id_ << "\n";
 }

 contents.replace("\n", "\n|  ");
 contents.prepend("|  ");

 s4 ix = contents.lastIndexOf("\n|  ");
 contents[ix + 1] = '.';

 if(mask & 1)
   sraw_line(contents);

 if(mask & 2)
   araw_line(contents);
  //vm_acc_ << ".#" << current_text_block_id_ << "\n";
}

SDI_VM_Writer& SDI_VM_Writer::araw(QString contents)
{
 avm_acc_ << contents;
 return *this;
}

SDI_VM_Writer& SDI_VM_Writer::sraw(QString contents)
{
 svm_acc_ << contents;
 return *this;
}

SDI_VM_Writer& SDI_VM_Writer::braw(QString contents)
{
 avm_acc_ << contents;
 svm_acc_ << contents;
 return *this;
}

SDI_VM_Writer& SDI_VM_Writer::araw_line(QString contents)
{
 avm_acc_ << contents << "\n";
 return *this;
}

SDI_VM_Writer& SDI_VM_Writer::sraw_line(QString contents)
{
 svm_acc_ << contents << "\n";
 return *this;
}

SDI_VM_Writer& SDI_VM_Writer::braw_line(QString contents)
{
 avm_acc_ << contents << "\n";
 svm_acc_ << contents << "\n";
 return *this;
}

void SDI_VM_Writer::write_end_control(u1 mask)
{
 if(mask & 1)
   svm_acc_ << " ;.\n";
 if(mask & 2)
   avm_acc_ << " ;.\n";
}

void SDI_VM_Writer::opstatement(QString contents, u1 mask)
{
 if(mask & 1)
   svm_acc_ << "sdi-" << contents << " ;.\n";
 if(mask & 2)
   avm_acc_ << "asl-" << contents << " ;.\n";
}

//QTextStream&
void SDI_VM_Writer::opstatement_to_mid(QString instruction, QString mid_control, u1 mask)
{
 if(mask & 1)
   svm_acc_ << "sdi-" << instruction << " " << mid_control;
 if(mask & 2)
   avm_acc_ << "asl-" << instruction << " " << mid_control;
 //return vm_acc_;
}


void SDI_VM_Writer::opstatement(QString instruction, QString mid_control, QString parameter, u1 mask)
{
 if(mask & 1)
   svm_acc_ << "sdi-" << instruction << " " << mid_control
     << " " << parameter << " ;.\n";
 if(mask & 2)
   avm_acc_ << "asl-" << instruction << " " << mid_control
     << " " << parameter << " ;.\n";
}

void SDI_VM_Writer::opstatement(QString instruction, QString parameter, u1 mask)
{
 opstatement(instruction, "$", parameter, mask);
}

