
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef TIA_GRAPHIC_ELEMENT__H
#define TIA_GRAPHIC_ELEMENT__H

#include <QTextStream>

#include "global-types.h"

#include "accessors.h"

#include "otns.h"

OTNS_(DCM2RO)

class TIA_Graphic_Element
{
 QMap<QString, QVariant> characteristics_;

 QStringList interpretation_;


public:

 TIA_Graphic_Element();

 ACCESSORS(QStringList ,interpretation)

 QVariant& add_characteristic(QString key);

 void characteristic_values(QStringList keys, QVariant value);


};

_OTNS(DCM2RO)

#endif // TIA_GRAPHIC_ELEMENT__H
