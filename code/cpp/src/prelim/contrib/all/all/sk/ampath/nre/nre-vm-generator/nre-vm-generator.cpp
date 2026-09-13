
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "nre-vm-generator.h"

#include "forms-jsp/jsp-admission-form.h"


USING_OTNS(AMPATH_NRE)

NRE_VM_Generator::NRE_VM_Generator()
{

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
  JSP_Admission_Form form_jsp(c1, c2, c3);

  qDebug() << "c1 = " << c1;
  qDebug() << "c2 = " << c2;
  qDebug() << "c3 = " << c3;

  form_jsp.read_JSON_Object(qjo);

  //?form_jsp.write_summary("_summary.txt");

  QString test = " test-dis  $  test-arg ;.";
  QString rs;


  //?int r = form_jsp.advance_past_dispatch(test, &rs);

//  qDebug() << "rs = " << rs;
//  qDebug() << "r = " << r;
//  qDebug() << "t = " << test;
 }
}
