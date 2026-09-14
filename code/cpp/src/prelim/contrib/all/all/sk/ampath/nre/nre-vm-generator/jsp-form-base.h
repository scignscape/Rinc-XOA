
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)




#ifndef JSP_FORM_BASE__H
#define JSP_FORM_BASE__H

#include <QJsonObject>
#include <QString>
#include <QStringList>

#include "accessors.h"

#include "otns.h"

OTNS_(AMPATH_NRE)


class JSP_Form_Base
{
protected:
 QString name_;
 QString index_code_;
 QString summary_;

 QString header_file_path_;
 QString implementation_file_path_;

public:

 JSP_Form_Base();

 void init(QString name, QString index_code, QString summary);

 ACCESSORS(QString ,header_file_path)
 ACCESSORS(QString ,implementation_file_path)

 void save_4lr(QString file_path);
 void finalize_4lr();

 virtual QString get_generated_class_name() = 0;
 virtual void read_JSON_Object(const QJsonObject& qjo) = 0;
};

_OTNS(AMPATH_NRE)


#endif // JSP_FORM_BASE__H
