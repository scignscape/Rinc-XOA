
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef TIA_TEX_FILE__H
#define TIA_TEX_FILE__H

#include <QTextStream>

#include "global-types.h"

#include "accessors.h"

#include "otns.h"


OTNS_(DCM2RO)

class TIA_Tex_File
{
 QString image_name_;
 u2 width_;
 u2 height_;

public:

 TIA_Tex_File();

 ACCESSORS(QString ,image_name)
 ACCESSORS(u2 ,width)
 ACCESSORS(u2 ,height)


};

_OTNS(DCM2RO)

#endif // TIA_TEX_FILE__H
