
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "nre-vm-generator.h"

#include "forms-jsp/jsp-admission-form.h"


USING_OTNS(AMPATH_NRE)

NRE_VM_Generator::NRE_VM_Generator(QString output_folder_path, QString generated_cpp_folder_path)
  :  output_folder_path_(output_folder_path), generated_cpp_folder_path_(generated_cpp_folder_path)
{
 if(!generated_cpp_folder_path_.endsWith("/"))
   generated_cpp_folder_path_ += "/";

 forms_jsp_[8] = new JSP_Admission_Form;
}

void NRE_VM_Generator::read_json_file(QString file_path)
{
 QFile qf(file_path);
 if(!qf.exists())
 {
  qDebug() << "File " << file_path << " does not exist!";
  return;
 }

 qf.open(QFile::ReadOnly);

 QByteArray qba = qf.readAll();

 QJsonParseError err;
 QJsonDocument qjd = QJsonDocument::fromJson(qba, &err);

 if (err.error != QJsonParseError::NoError) {
     qWarning() << "JSON parse error:" << err.errorString()
     << "at offset" << err.offset;
     return;
 }

 if (qjd.isArray())
 {
     qDebug() << "Unexpected Aray";
     return;
 }
 if (qjd.isNull())
 {
     qDebug() << "Unexpected empty document";
     return;
 }

 QJsonObject root_obj = qjd.object();
 process_form_node(root_obj);

 qf.close();
}

void NRE_VM_Generator::process_form_node(const QJsonObject& qjo, QString key, Node_Type nt)
{
 QString name = qjo.value("name").toString();

 QRegularExpression rx("^(F(\\d+)-ITFC)\\s*(\\w*)");
 QRegularExpressionMatch m = rx.match(name);

 if(m.hasMatch())
 {
  QString c1 = m.captured(1);
  QString c2 = m.captured(2);
  QString c3 = m.captured(3);

  u1 which_form = c2.toUInt();

  JSP_Form_Base* jfb = forms_jsp_.value(which_form);

  if(!jfb)
  {
   qDebug() << "Unexpected missing form parser, with number " << which_form;
   return;
  }

  QString cn = jfb->get_generated_class_name().toLower().replace("_", "-");
  cn.prepend(generated_cpp_folder_path_);
  jfb->set_header_file_path(cn + ".h");
  jfb->set_implementation_file_path(cn + ".cpp");

  jfb->init(c1, c2, c3);

  qDebug() << "c1 = " << c1;
  qDebug() << "c2 = " << c2;
  qDebug() << "c3 = " << c3;

  jfb->read_JSON_Object(qjo);

  QString path = "%1/%2.4lr"_qt.arg(output_folder_path_).arg(which_form);

  jfb->finalize_4lr();
  jfb->save_4lr(path);
 }
}
