
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#include "tia-graphic-element.h"

#include <bit>

#include <QDebug>

#include "textio.h"


USING_KANS(TextIO)

USING_OTNS(DCM2RO)

TIA_Graphic_Element::TIA_Graphic_Element()
{

}

QVariant& TIA_Graphic_Element::add_characteristic(QString key)
{
 return characteristics_[key];
}

void TIA_Graphic_Element::characteristic_values(QStringList keys, QVariant value)
{
 for(QString ec : keys)
 {
  add_characteristic(ec).setValue(value);
 }
}

