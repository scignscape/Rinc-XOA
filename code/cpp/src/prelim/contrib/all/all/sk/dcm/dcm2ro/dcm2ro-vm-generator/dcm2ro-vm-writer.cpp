
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dcm2ro-vm-writer.h"

#include "dcm2ro-vm-script-data.h"

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
 init_stream_ = [](QTextStream& acc)
 {
  acc << "\n.; Generated on " << QDateTime::currentDateTime().toString() << " ;.\n\n"
              << "=prog\n\n";
 };

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

   if(reader.name() == "imageSOP_UID")
   {
    parse_stage = XML_Parse_Stage::In_ROI_imageSOP_UID;
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
   if(parse_stage == XML_Parse_Stage::In_ROI_imageSOP_UID)
   {
    current_sop_instance_uid_ = reader.text().toString();
    parse_stage = XML_Parse_Stage::In_ROI;
    continue;
   }
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
     VM_Script_Data* vsd = new VM_Script_Data;
     vsd->set_sop_instance_uid(current_sop_instance_uid_);
     vsd->set_characteristics_map(current_characteristics_map_);
     vsd->set_coord_pairs(xys);
     script_data_by_instance_sop_uid_.insert({current_sop_instance_uid_, vsd});
     xys.clear();
     //write_coord_pairs(xys);
     parse_stage = XML_Parse_Stage::Generic;
    }
   }
  }

 }
}

VM_Writer& VM_Writer::praw_comment_line(QString contents, s1 prior_blank_line_count, u1 prior_space_count)
{
 QString nl(prior_blank_line_count + 1, '\n');
 QString sp(prior_space_count, ' ');

 pvm_acc_ << nl << sp << ".; ";
 current_mask_ = 2;
 return line(contents);

}

VM_Writer& VM_Writer::line(QString contents, u1 mask)
{
 if(mask & 1)
   mvm_acc_ << contents << "\n";
 if(mask & 2)
   pvm_acc_ << contents << "\n";

 return *this;
}


void VM_Writer::finalize_pvm(QString file_path, QString tikz_folder, QString tikz_html_folder)
{
 u2 count = 0;
 u2 path_ids = 0;
 for(auto pr : script_data_by_instance_sop_uid_.values_container())
 {
  ++count;
  VM_Script_Data* vsd = pr.second;

  post_process_vm_.clear();
  init_stream_(pvm_acc_);

  pvm_opstatement("asa-load-svg-file").mid("$")
    .arg(tikz_folder + "/from-svg-%1.svg"_qt.arg(count)).end(1);

  pvm_opstatement("asa-new->graphic-element").end();
    // //  in this context all characteristics elements have unblindedReadNodule as parent
  pvm_opstatement(" :interpretation").mid("$").arg("nodule|unblinded-read").end();

  QMap<QString, u1> characteristics = vsd->characteristics_map();

  u1 _internal_structure = characteristics.take("internalStructure");

  static QStringList internal_structure_options {"?", "soft-tissue", "fluid", "fat", "air" };
  QString internal_structure = internal_structure_options.value(_internal_structure);

  praw_comment_line("1 = Soft Tissue" ,1 ,1)
  .line(" 2 = Fluid")
  .line(" 3 = Fat")
  .line(" 4 = Air")
  .end();

  pvm_opstatement(" :characteristic").mid("$").arg("internalStructure").end();
  pvm_opstatement(" :value-str").mid("$").arg(internal_structure).end(1);

  QMapIterator<QString, u1> it(characteristics);
  while(it.hasNext())
  {
   it.next();
   pvm_opstatement(" :characteristic").mid("$").arg(it.key()).end();
   pvm_opstatement(" :value-str").mid("1#").arg(it.value()).end(!it.hasNext());
  }


  pvm_opstatement("asa-path-id").mid("2#").arg(++path_ids).end();
  pvm_opstatement("asa-path-id-string-auto").mid("$").arg("em-path").end();
  pvm_opstatement("asa-group-id").mid("2##")
    .arg("%1 %2"_qt.arg(++path_ids).arg(++path_ids)).end();
  pvm_opstatement("asa-path-group-glyphs").mid("$$").arg("glyph0-1").end();
  pvm_opstatement("asa-path-group-id-string-auto").mid("$").arg("em-group").end();
  pvm_opstatement("asa-gel-id-string-auto").mid("$").arg("gel").end(1);
  pvm_opstatement("asa-finalize<-graphic-element").end(1);
  pvm_opstatement("asa-prepare-svg-file").end();
  pvm_opstatement("asa-save-svg-file").mid("$")
    .arg(tikz_html_folder + "/ia-%1.svg"_qt.arg(count)).end();

  pvm_opstatement("asa-prepare-html-file").end();

  pvm_opstatement("asa-load-html-template").mid("$").arg(tikz_svg_html_template_).end(1);

  pvm_opstatement("asa-save-html-file").mid("$")
    .arg(tikz_html_folder + "/ia-%1.html"_qt.arg(count)).end();


  finalize_vm(pvm_acc_);
  save_pvm(file_path.arg(count));
 }
}


extern QVector<QString> qtGrepSearch(QString, QString);

void VM_Writer::finalize_mvm(QString file_path, QString image_xml_folder, QString images_folder)
{
// init_stream(pvm_acc_);

 u2 count = 0;
 for(auto pr : script_data_by_instance_sop_uid_.values_container())
 {
  ++count;
  VM_Script_Data* vsd = pr.second;

  main_process_vm_.clear();
  init_stream_(mvm_acc_);

  QVector<QString> grep_files = qtGrepSearch(image_xml_folder, vsd->sop_instance_uid());

  if(grep_files.isEmpty())
  {
   qDebug() << "Can't find image file from SOP Instance UID";
  }
  else
  {
   QString image_file = grep_files.first();
   QFileInfo qfi(image_file);
   QString bn = qfi.baseName();

   mvm_opstatement("tia-load-base-file").mid("$").arg(images_folder + "/" + bn + ".png").end(1);

  }

  if(grep_files.size() > 1)
  {
   qDebug() << "Unexpected repeat of SOP Instance UID";
  }

  mvm_opstatement("tia-load-tikz-template").mid("$").arg(tikz_template_).end(1);

  mvm_opstatement("tia-new->tex-file").end();
  mvm_opstatement(" :image-name").mid("$").arg("i-%1.png"_qt.arg(count)).end();
  mvm_opstatement(" :sop-instance-uid").mid("$").arg(vsd->sop_instance_uid()).end();
  mvm_opstatement(" :width").mid("2#").arg(512).end();
  mvm_opstatement(" :height").mid("2#").arg(512).end();
  mvm_opstatement("tia-finalize<-tex-file").end(2);

  write_coord_pairs(vsd->coord_pairs());
  finalize_vm(mvm_acc_);
  save_mvm(file_path.arg(count));
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

