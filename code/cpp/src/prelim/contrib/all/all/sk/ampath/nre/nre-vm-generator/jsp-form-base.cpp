
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include "jsp-form-base.h"

#include "textio.h"

USING_OTNS(AMPATH_NRE)

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>

#include <QFile>


JSP_Form_Base::JSP_Form_Base()
{

}


void JSP_Form_Base::finalize_4lr()
{
 summary_ += "\n\n=done\n\n";
}

void JSP_Form_Base::save_4lr(QString file_path)
{
 save_file(file_path, summary_);
}

void JSP_Form_Base::init(QString name, QString index_code, QString summary)
{
 name_ = name;
 index_code_ = index_code;
 summary_ = ".; " + summary + " ;.\n\n=prog\n\n";
}

