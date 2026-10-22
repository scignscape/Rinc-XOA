
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dcm2ro-vm-writer.h"


#include <QFile>
#include <QTextStream>

#include <QDateTime>

#include <QXmlStreamReader>

#include "textio.h"

USING_KANS(TextIO)


#include "otns.h"

USING_OTNS(DCM2RO)


VM_Writer::VM_Writer()
  :  mvm_acc_(&main_process_vm_), pvm_acc_(&post_process_vm_), current_mask_(0)
{
 auto init_stream = [](QTextStream& acc)
 {
  acc << "\n.; Generated on " << QDateTime::currentDateTime().toString() << " ;.\n\n"
              << "=prog\n\n";
 };

 init_stream(mvm_acc_);
 init_stream(pvm_acc_);
}

void VM_Writer::write_coord_pairs(const QVector<QPair<u2, u2>>& xys)
{
 for(auto pr : xys)
 {
  mvm_opstatement("tia-point-xy").mid("4#/2").args(pr).end();
 }
}

void VM_Writer::check_characteristics_map()
{
 // //  here I use a simple filter, just for demo

 current_characteristics_map_["internalStructure"] += 10;
 current_characteristics_map_["subtlety"] += 10;

 u1 minimum = std::min_element(current_characteristics_map_.begin(),
   current_characteristics_map_.end(),
         [](int a, int b) { return a < b; }).value();

 if(minimum < 5)
   current_characteristics_map_.clear();
 else
 {
  current_characteristics_map_["internalStructure"] -= 10;
  current_characteristics_map_["subtlety"] -= 10;
 }
}

void VM_Writer::scan_xml(QString xml_path)
{
 QFile xml_file(xml_path);

 if (!xml_file.open(QIODevice::ReadOnly | QIODevice::Text))
   return;

 QXmlStreamReader reader(&xml_file);

 if(reader.hasError())
 {
  qDebug() << "XML Stream Reader error: " << reader.errorString();
 }

 QVector<QPair<u2, u2>> xys;

 static QStringList possible_characteristics {
   "subtlety",
   "internalStructure",
   "calcification",
   "sphericity",
   "margin",
   "lobulation",
   "spiculation",
   "texture",
   "malignancy"
 };

 QString current_characteristic;
 //QString held_tag_name;

 XML_Parse_Stage parse_stage = XML_Parse_Stage::Generic;

 while (!reader.hasError())
 {
  if(reader.atEnd())
  {
   qDebug() << "XML Stream Reader concludes";
   break;
  }

  QXmlStreamReader::TokenType token_type = reader.readNext();

  if(token_type == QXmlStreamReader::StartElement)
  {
   if(possible_characteristics.contains(reader.name()))
   {
    current_characteristic = reader.name().toString();
    parse_stage = XML_Parse_Stage::Reading_Characteristics;
    continue;
   }

   if(parse_stage == XML_Parse_Stage::Generic)
     continue;

   if(reader.name() == "roi")
   {
    parse_stage = XML_Parse_Stage::In_ROI;
    continue;
   }

   if(reader.name().endsWith("Coord"))
   {
    if(reader.name().startsWith("x"))
      parse_stage = XML_Parse_Stage::In_ROI_x;
    else if(reader.name().startsWith("y"))
      parse_stage = XML_Parse_Stage::In_ROI_y;
    continue;
   }

  }

  if(parse_stage == XML_Parse_Stage::Generic)
    continue;

//  if(held_tag_name.isEmpty() && current_characteristic.isEmpty())
//    continue;

  if(token_type == QXmlStreamReader::Characters)
  {
   if(parse_stage == XML_Parse_Stage::In_ROI_x)
   {
    xys.push_back({reader.text().toUShort(), 0});
    parse_stage = XML_Parse_Stage::In_ROI;
    continue;
   }
   if(parse_stage == XML_Parse_Stage::In_ROI_y)
   {
    xys.last().second = reader.text().toUShort();
    parse_stage = XML_Parse_Stage::In_ROI;
    continue;
   }

   if(current_characteristic.isEmpty())
     continue;

   u1 val = reader.text().toShort();
   current_characteristics_map_[current_characteristic] = val;
   //held_tag_name = current_characteristic;
   current_characteristic.clear();
   continue;
  }

  if(token_type == QXmlStreamReader::EndElement)
  {
   if(reader.name() == "characteristics")
   {
    check_characteristics_map();
    if(current_characteristics_map_.isEmpty())
      parse_stage = XML_Parse_Stage::Generic;
    else
      parse_stage = XML_Parse_Stage::Characteristics_Map_Checked_Positive;
//    held_tag_name.clear();
    continue;
   }
   if(reader.name() == "roi")
   {
    if(parse_stage == XML_Parse_Stage::In_ROI)
    {
     write_coord_pairs(xys);
     parse_stage = XML_Parse_Stage::Generic;
    }
   }
  }

 }
}

void VM_Writer::save_mvm(QString file_path)
{
 save_file(file_path, main_process_vm_);
}

void VM_Writer::save_pvm(QString file_path)
{
 save_file(file_path, post_process_vm_);
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
   mvm_acc_ << "tia-" << contents << " ;.\n";
 if(mask & 2)
   pvm_acc_ << "asa-" << contents << " ;.\n";
}

//QTextStream&
void VM_Writer::opstatement_to_mid(QString instruction, QString mid_control, u1 mask)
{
 if(mask & 1)
   mvm_acc_ << "tia-" << instruction << " " << mid_control;
 if(mask & 2)
   pvm_acc_ << "asa-" << instruction << " " << mid_control;
}


void VM_Writer::opstatement(QString instruction, QString mid_control, QString parameter, u1 mask)
{
 if(mask & 1)
   mvm_acc_ << "tia-" << instruction << " " << mid_control
     << " " << parameter << " ;.\n";
 if(mask & 2)
   pvm_acc_ << "asa-" << instruction << " " << mid_control
     << " " << parameter << " ;.\n";
}

void VM_Writer::opstatement(QString instruction, QString parameter, u1 mask)
{
 opstatement(instruction, "$", parameter, mask);
}

