
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef TIA_GRAPHIC_LAYER__H
#define TIA_GRAPHIC_LAYER__H

#include <QTextStream>

#include "global-types.h"

#include "accessors.h"

#include "otns.h"

OTNS_(DCM2RO)

class Tia_Graphic_Layer
{
 QString uid_;

public:

 Tia_Graphic_Layer();

 ACCESSORS(QString ,uid)


};

_OTNS(DCM2RO)

#endif // TIA_GRAPHIC_LAYER__H
