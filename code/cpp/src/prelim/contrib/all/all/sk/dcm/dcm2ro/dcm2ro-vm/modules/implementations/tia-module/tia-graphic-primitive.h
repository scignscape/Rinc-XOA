
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef TIA_GRAPHIC_PRIMITIVE__H
#define TIA_GRAPHIC_PRIMITIVE__H

#include <QTextStream>

#include "global-types.h"

#include "accessors.h"

#include "otns.h"

OTNS_(DCM2RO)

class TIA_Graphic_Primitive
{
 u2 rank_;
 QString kind_;

 QVector<QPair<u4, u4>> points_xy_;

public:

 TIA_Graphic_Primitive(QString kind);

 ACCESSORS(u2 ,rank)
 ACCESSORS(QString ,kind)
 ACCESSORS(QVector<QPair<u4, u4>> ,points_xy)

};

_OTNS(DCM2RO)

#endif // TIA_GRAPHIC_PRIMITIVE__H
