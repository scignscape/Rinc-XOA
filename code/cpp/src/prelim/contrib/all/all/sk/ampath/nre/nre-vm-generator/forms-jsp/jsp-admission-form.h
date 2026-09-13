
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)




#ifndef JSP_ADMISSION_FORM__H
#define JSP_ADMISSION_FORM__H

#include <QJsonObject>
#include <QString>
#include <QStringList>

#include "jsp-form-base.h"

#include "otns.h"

OTNS_(AMPATH_NRE)


class JSP_Admission_Form : public JSP_Form_Base
{
 QString current_field_prefix_;

 QString processor_;
 QString uuid_;
 QString version_;

 QStringList page_labels_;
 QVector<QStringList> section_labels_;

 QSet<QString> known_prefixes_;

 enum class Node_Type {
  N_A, Form_Root
 };

 void reset_field_prefix(QString prefix);
 void check_field_expand(QString& dispatch);

 public:

 JSP_Admission_Form();

 void read_JSON_Object(const QJsonObject& qjo) Q_DECL_OVERRIDE;
 void parse_question(const QJsonObject& question_qjo);
};

_OTNS(AMPATH_NRE)


#endif // JSP_ADMISSION_FORM__H
