
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#include "nre-form-base.h"

#include <bit>

#include <QDebug>

#include "textio.h"

USING_KANS(TextIO)

USING_OTNS(AMPATH_NRE)

NRE_Form_Base::NRE_Form_Base()
{
 init_accs({"top"});
}

void NRE_Form_Base::init_accs(QStringList parts)
{
 for(QString part : parts)
 {
  header_acc_[part] = new QTextStream;
  implementation_acc_[part] = new QTextStream;
  header_acc_[part]->setString(&cpp_header_parts_[part]);
  implementation_acc_[part]->setString(&cpp_implementation_parts_[part]);
 }
}

QTextStream& NRE_Form_Base::header_acc(QString which)
{
 return *header_acc_[which];
}

QTextStream& NRE_Form_Base::implementation_acc(QString which)
{
 return *implementation_acc_[which];
}

