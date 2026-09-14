
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef NRE_FORM_BASE__H
#define NRE_FORM_BASE__H

#include <QTextStream>
#include <QMap>

#include "global-types.h"

#include "accessors.h"

#include "otns.h"

OTNS_(AMPATH_NRE)

class NRE_Form_Base
{
protected:

 QMap<QString, QString> cpp_header_parts_;
 QMap<QString, QString> cpp_implementation_parts_;

 QMap<QString, QTextStream*> header_acc_;
 QMap<QString, QTextStream*> implementation_acc_;

public:

 NRE_Form_Base();

 QTextStream& header_acc_top()
 {
  return header_acc("top");
 }

 QTextStream& implementation_acc_top()
 {
  return implementation_acc("top");
 }

 QString cpp_header_part(QString p)
 {
  return cpp_header_parts_[p];
 }

 QString cpp_implementation_part(QString p)
 {
  return cpp_implementation_parts_[p];
 }

 QString cpp_header_top()
 {
  return cpp_header_part("top");
 }

 QString cpp_implementation_top()
 {
  return cpp_implementation_part("top");
 }

 void init_accs(QStringList parts);

 QTextStream& header_acc(QString which);
 QTextStream& implementation_acc(QString which);

// ACCESSORS(QString ,current_class_name)

};

_OTNS(AMPATH_NRE)

#endif // NRE_FORM_BASE__H
